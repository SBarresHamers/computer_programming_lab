#include <iostream>
#include <vector>
using namespace std;

void removeDuplicate (vector<int>& inputVector){
    unsigned int i;
    unsigned int j;
    vector<int> testVector;
    int Vectorvalues;
    bool DuplicateValue;

    for(i= 0; i <inputVector.size(); ++i)
    {
           inputVector.at(i);
        for( j = 1 ; j <inputVector.size(); ++j)
        {
            if( i != j  && inputVector.at(i) == inputVector.at(j))
            {
                inputVector.erase(inputVector.begin() + j) ;
                -- j;
            }
        }
    }
}

void printvector (vector<int>& inputVector){
    unsigned int i;
    int vectorSize;
    vectorSize = inputVector.size();

   cout<<'[';
        for (int i = 0; i < vectorSize; i++)
        {
            cout<< inputVector.at(i);
            if ( i != vectorSize - 1){
                cout << ',';
            }
        }
        cout << ']';
}

int main() {
    int userInput;
    unsigned int i;
    vector<int> inputVector;
    
        cout << "Enter the vector elements: " << endl;
        while (cin >> userInput)
        {  
            if(cin.fail()){ break;
            }
            if (cin.eof()){
                 inputVector.push_back(userInput);
                 break;
            }
            else {
                inputVector.push_back(userInput);
                continue;
            }
        }
        cout << "The deduplicated vector is: ";
        removeDuplicate (inputVector);
        printvector(inputVector);
    return 0;
}
