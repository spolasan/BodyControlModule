clc;
clear;

disp('Starting MIL test execution...');

sltest.testmanager.clear;
sltest.testmanager.load('TurnLights_System/MIL_Test_Files/Manual_Test/TurnLights_TestSuite.mldatx');

results = sltest.testmanager.run;

disp('MIL test execution completed.');
disp(results);
