#include <iostream>
#include <string>
using namespace std;

int main() {
   string prefixNotation;
   char operatorValue;
   double XValue,YValue, resultPolish;

   while (operatorValue != 'q'){
   
   cout << "Enter the expression: ";
   cin >> prefixNotation >> XValue >> YValue;
   operatorValue = prefixNotation.at(0);

      switch(operatorValue){
         case '+' :
            resultPolish = XValue + YValue;
            cout << XValue  << " " << operatorValue << " " << YValue << " = " << resultPolish << endl;
            break;
         case '-' :
            resultPolish = XValue - YValue;
            cout << XValue  << " " << operatorValue << " " << YValue << " = " << resultPolish << endl;
            break;
         case '*' :
            resultPolish = XValue * YValue;
            cout << XValue  << " " << operatorValue << " " << YValue << " = " << resultPolish << endl;
            break;
         case '/' :
            resultPolish = XValue / YValue;
            cout << XValue  << " " << operatorValue << " " << YValue << " = " << resultPolish << endl;
            break;
         default:
            cout << "" << endl;
            break;
      }
   }
   return 0 ;
   }
   



