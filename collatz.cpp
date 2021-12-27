#include <iostream>
using namespace std;

int main() {
    int nextNumber, i = 0;
    
    cout << "Enter the first number of the sequence: " << endl;
    cin >> nextNumber ;
    
    while( i < 3){
        if ( nextNumber == 1){
            i++;
        }
        cout << nextNumber << " " ;
        if (nextNumber % 2 == 0) {
            nextNumber = nextNumber / 2;
        } 
        else {
            nextNumber = (3 * nextNumber) + 1;
        }
    }
    cout << "...";
    return 0 ;
}
