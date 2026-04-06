clc;
clear;

disp('=== Jenkins MIL Run Started ===');

try
    sltest.testmanager.clear;
    sltest.testmanager.load('TurnLights_System/MIL_Test_Files/Manual_Test/TurnLights_TestSuite.mldatx');
    results = sltest.testmanager.run;

    disp('=== MIL Run Completed Successfully ===');
    disp(results);

catch ME
    disp('=== MIL Run Failed ===');
    disp(getReport(ME));
    exit(1);
end

exit(0);
