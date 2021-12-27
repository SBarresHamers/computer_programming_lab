#include <iostream>
#include <vector>
#include <string>
using namespace std;

void InputCharacters (string& InputDecompressedData){
    unsigned int i;
    int numberOfCompressions;
    int vectorsize;
    vectorsize = InputDecompressedData.size();

    for (i=0; i<vectorsize; i++) { 
        InputDecompressedData[i];
        numberOfCompressions = 1;

        if(isupper(InputDecompressedData[i])){
            cout << "invalid input" << endl;
            break;
        }  
        while(i < vectorsize-1 &&  InputDecompressedData[i] ==  InputDecompressedData[i+1]){
            numberOfCompressions++;
            i++;
        }
        cout << InputDecompressedData[i] <<  numberOfCompressions;
    }
}

void DecompressedData(string& InputDecompressedData){
     vector<char> inputVector;
     unsigned int i;
     for (i=0; i<inputVector.size(); i++) {
         inputVector.at(i);
         cout << inputVector.at(i);
}
}

int main(){
    string InputDecompressedData;
    vector<char> inputVector;

    cout << "Enter the data to be compressed: ";
    cin >> InputDecompressedData;
    cout << "Test: ";
    InputCharacters(InputDecompressedData);
    
    return 0;
}



