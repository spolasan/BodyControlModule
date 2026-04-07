clc;
clear;

disp('=== Jenkins MIL Run Started ===');

try
    bdclose('all');
    sltest.testmanager.clear;

    manualTestFolder = pwd;
    disp(['Current folder    : ', manualTestFolder]);

    if ~isfolder(manualTestFolder)
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
    busFile = fullfile(manualTestFolder, 'TurnLights_Bus.mat');
    if isfile(busFile)
        disp(['Loading bus file: ', busFile]);
        load(busFile);
    else
        disp('Bus file not found or not needed.');
    end

    % Load model first
    modelFile = fullfile(manualTestFolder, 'TurnLights_Model.slx');
    disp(['Checking model file: ', modelFile]);

    if isfile(modelFile)
        disp('Loading model: TurnLights_Model.slx');
        load_system(modelFile);
        disp('Model loaded successfully.');
    else
        error(['Model file not found: ', modelFile]);
    end

    % Check suite file
    tf = fullfile(manualTestFolder, 'TurnLights_TestSuite.mldatx');
    disp(['Checking test suite: ', tf]);

    if ~isfile(tf)
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
