clc;
clear;

disp('=== Jenkins MIL Run Started ===');

try
    % Optional: close existing models/data from previous state
    bdclose('all');

    % Clear Test Manager
    sltest.testmanager.clear;

    % Load the test file
    tf = 'TurnLights_System/MIL_Test_Files/Manual_Test/TurnLights_TestSuite.mldatx';
    disp(['Loading Test File: ', tf]);
    sltest.testmanager.load(tf);

    % Run tests
    disp('Running Test Manager suite...');
    results = sltest.testmanager.run;

    % Display results object
    disp(results);

    disp('=== MIL Run Completed Successfully ===');
    exit(0);

catch ME
    disp('=== MIL Run Failed ===');
    disp(getReport(ME, 'extended', 'hyperlinks', 'off'));
    exit(1);
end
