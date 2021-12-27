#include <iostream>
#include <cmath>
#include <string>
using namespace std;

double Discriminant_func(double aVal, double bVal, double  cVal) { 
    double discriminantValue;
    discriminantValue = pow(bVal, 2.0) -(4 * aVal * cVal);
    return discriminantValue;
}

double Quad_func_pos(double a, double b,double c, double D){
    double x_quadratic_pos;
    D =  pow(b, 2.0) -(4 * a * c);
    x_quadratic_pos = (-b + sqrt(D))/(2*a);
    return x_quadratic_pos;
}

double Quad_func_neg(double a, double b,double c, double D){
    double x_quadratic;
    D = pow(b, 2.0) -(4 * a * c );
    x_quadratic = (-b - sqrt(D))/(2 * a);
    return x_quadratic;
}

void resultQaudraticFormula(double& aVal, double& bVal,double& cVal){
    double x_quadratic_pos;
    double x_quadratic_neg; 
    double discriminantValueInput = Discriminant_func(aVal,bVal, cVal);

        if(discriminantValueInput < 0){
            cout << "There is no solution." << endl;
            return;
        }
        else if (discriminantValueInput == 0){
            cout << "There is 1 solution." << endl;
            cout << "The solution is: " << Quad_func_neg(aVal,bVal,cVal,discriminantValueInput);
        }
        else {
            cout << "There are 2 solutions." << endl;
            cout << "The solutions are: " << Quad_func_pos(aVal,bVal,cVal,discriminantValueInput) << " and "<< Quad_func_neg(aVal,bVal,cVal,discriminantValueInput) << endl;
        return;
        }
}

void checkAinputValue(){
        cout << "An error occurred: a must not be zero" << endl;
        return;
    }

int main() {
    double aInputVal, bInputVal, cInputVal, discriminantValueInput ;
    string PROMPT = "Please enter the values of a, b, and c: ";
    string errormMessage = "An error occurred: Malformed user input";

    cout << PROMPT << endl;
    cin >> aInputVal >> bInputVal >> cInputVal;

    if(cin.fail()){
        cout << errormMessage << endl;
    }
    else if (aInputVal == 0){
        checkAinputValue();
    }
    else if (cin.eof()){
        resultQaudraticFormula(aInputVal, bInputVal, cInputVal);
    }
    else {
        resultQaudraticFormula(aInputVal, bInputVal, cInputVal);
    }

return 0 ;
}
