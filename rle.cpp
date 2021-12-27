#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

bool isNumber(const string& InputDecompressedData) {
    unsigned int i;
    int stringSize;
    string sID;
    bool containNum;

    sID = InputDecompressedData;
    containNum = false;
    stringSize =InputDecompressedData.size();
        for (i = 0; i< stringSize ; i++) {
            if (sID[i] >= '0' && sID[i] <= '9'){
                    containNum =  true;
                    break;
            }
        }
    return containNum;
}

bool isCapital(string& InputDecompressedData) {
    bool isUpper;
    unsigned int i;
    string sID;

    sID = InputDecompressedData;
    isUpper  = false;
        for (i = 0; i< InputDecompressedData.size() ; i++) {
            if(sID[i] >= 'A' && sID[i] <= 'Z'){
                isUpper = true;
            }
        }
    return isUpper;
}

void InputCharacters (string& InputDecompressedData) {
    unsigned int i;
    int vectorsize;
    int numberOfCompressions;
    vector<char> compDataVector;
    vector<int> numCompVector;

    vectorsize = InputDecompressedData.size();
        for (i=0; i<vectorsize; i++) {
            compDataVector.push_back(InputDecompressedData[i]);

            if(compDataVector.size() == 1){
                numCompVector.push_back(1);
            }
            else {
                numCompVector.push_back(0);
            }  
        }
        for (i=0; i<vectorsize; i++) {
            numberOfCompressions =1;

            while(i < vectorsize-1){ 
                if(compDataVector.at(i) ==  compDataVector.at(i+1)){
                    numberOfCompressions ++ ; 
                    i++;
                    numCompVector.at(i) = numberOfCompressions; 
                    continue; 
                }
                else {
                    numCompVector.at(i) = numberOfCompressions;
                    break;
                }
            }
            numCompVector.resize(vectorsize);
            compDataVector.resize(vectorsize);
            cout << numCompVector.at(i) << compDataVector.at(i);
        }
}   
    
int main(){
    string InputDecompressedData;
    vector<char> compDataVector;
    bool NumberVal;
    bool IsUpper;
    
    try{
    cout << "Enter the data to be compressed: " << endl;
    cin >> InputDecompressedData;

    NumberVal = isNumber(InputDecompressedData);
    IsUpper =  isCapital(InputDecompressedData);

        if(NumberVal == true|| IsUpper == true){
            throw runtime_error("error: invalid input"); 
        }

    cout << "The compressed data is:";
    InputCharacters(InputDecompressedData);
    }
    catch (runtime_error& excpt) {
        cout << excpt.what() << endl;
    }

    return 0;
}