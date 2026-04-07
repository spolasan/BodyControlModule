clc;
clear;

disp('=== Jenkins MIL Run Started ===');

try
    bdclose('all');
    sltest.testmanager.clear;

    % Since this script itself is inside Manual_Test,
    % current folder should already be Manual_Test
    manualTestFolder = pwd;

    disp(['Current folder    : ', manualTestFolder]);

    if exist(manualTestFolder, 'dir') ~= 7
        error(['Current folder not found: ', manualTestFolder]);
    end

    addpath(genpath(manualTestFolder));

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

    disp(results);

    disp('=== MIL Run Completed Successfully ===');
    exit(0);

catch ME
    disp('=== MIL Run Failed ===');
    disp(getReport(ME, 'extended', 'hyperlinks', 'off'));
    exit(1);
end
