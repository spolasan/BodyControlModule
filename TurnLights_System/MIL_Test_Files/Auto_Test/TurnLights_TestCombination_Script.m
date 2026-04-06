%Test combinations for turnLights (3 inputs with boundary values)
LH=[0,1];
RH=[0,1];
HZ=[0,1];
X=combinations(LH,RH,HZ); %Creates the combination matrix
writetable(X,'TurnLights_TestCombinations.xlsx','Sheet',1); %Saves the file into the folder in Matlab