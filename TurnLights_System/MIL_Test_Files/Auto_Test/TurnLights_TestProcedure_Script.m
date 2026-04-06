%Test procedure script to populate the test combinations to test procedure
%Code to create Test Cases

%MAKE SURE TO BE IN THE CORRECT MATLAB FOLDER
f = waitbar(0,'Starting "Test Procedure" Script');
waitbar(0,f,'Loading "TestProcedure" file');
%Reads the Test Procedure Document
p = readtable('TurnLights_TestProcedure.xlsx','Format','auto','PreserveVariableNames',true);
waitbar(0,f,'Loading "TestCombinations" file');
k = xlsread('TurnLights_TestCombinations.xlsx'); %Reads the Test Combinations Document
w=width(k);

waitbar(0,f,'Creating "TestCases" file');
filename = uiputfile('TurnLights_TestCases.xlsx');
sheetnames = [];

for i = 1:length(k)
    m=i/length(k); %Calculates % Progress of the execution
    waitbar(m,f,sprintf('Updating Test Cases %d/%d (%d%%)',uint64(i),uint64(length(k)),uint8(m*100)));
    sheetnames(i) = i;
    sheet_name = string(sheetnames);
    writetable(p,(filename),'Sheet',char(sheet_name(i)),'Range','A1')
    
    writematrix(k(i,1:w),(filename),'Sheet',char(sheet_name(i)),'Range','B8')
    writematrix(k(i,1:w),(filename),'Sheet',char(sheet_name(i)),'Range','B9')
    
end

waitbar(1,f,'Done');
close(f);