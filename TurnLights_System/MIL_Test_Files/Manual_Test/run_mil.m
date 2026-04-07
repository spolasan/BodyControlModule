clc;
clear;

disp('=== Jenkins MIL Run Started ===');

try
    bdclose('all');
    sltest.testmanager.clear;

    % Workspace root from Jenkins
    rootFolder = pwd;
    manualTestFolder = fullfile(rootFolder, 'TurnLights_System', 'MIL_Test_Files', 'Manual_Test');

    disp(['Root folder       : ', rootFolder]);
    disp(['Manual_Test folder: ', manualTestFolder]);

    if exist(manualTestFolder, 'dir') ~= 7
        error(['Manual_Test folder not found: ', manualTestFolder]);
    end

    % Move into Manual_Test folder
    cd(manualTestFolder);
    addpath(genpath(manualTestFolder));

    disp(['Current folder    : ', pwd]);

    % Show folder contents for debugging
    disp('=== Files in Manual_Test folder ===');
    folderFiles = dir;
    for k = 1:length(folderFiles)
        if ~folderFiles(k).isdir
            disp(folderFiles(k).name);
        end
    end

    % Load bus/data file if needed
    if exist('TurnLights_Bus.mat', 'file') == 2
        disp('Loading bus file: TurnLights_Bus.mat');
        load('TurnLights_Bus.mat');
    else
        disp('Bus file not found or not needed.');
    end

    % Load model first
    if exist('TurnLights_Model.slx', 'file') == 2
        disp('Loading model: TurnLights_Model.slx');
        load_system('TurnLights_Model.slx');
        disp('Model loaded successfully.');
    else
        error('Model file TurnLights_Model.slx not found.');
    end

    % Check suite file
    tf = fullfile(manualTestFolder, 'TurnLights_TestSuite.mldatx');
    disp(['Checking test suite: ', tf]);

    if exist(tf, 'file') ~= 2
        error(['Test suite file not found: ', tf]);
    end

    fileInfo = dir(tf);
    disp(['Test suite size (bytes): ', num2str(fileInfo.bytes)]);

    % Load suite
    disp('Loading Test Manager suite...');
    sltest.testmanager.load(tf);
    disp('Test suite loaded successfully.');

    % Run suite
    disp('Running Test Manager suite...');
    results = sltest.testmanager.run;
    disp('Test execution finished.');

    % Display raw result object
    disp(results);

    disp('=== MIL Run Completed Successfully ===');
    exit(0);

catch ME
    disp('=== MIL Run Failed ===');
    disp(getReport(ME, 'extended', 'hyperlinks', 'off'));
    exit(1);
end
