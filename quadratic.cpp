#include <iostream>
#include <cmath>
using namespace std;

double Discriminant_func(double a, double b, double  c) { 
    double discriminantValue;
    discriminantValue = pow(b, 2.0) -(4 * a * c);
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

int main() {
    double a_input, b_input, c_input, D_value ;

    cout << "Please enter the values of a, b, and c: " << endl;
    cin >> a_input >> b_input >> c_input;
    
    D_value = Discriminant_func(a_input,b_input, c_input);

    if(D_value < 0){
        cout << "There is no solution.";
    }
    else if (D_value == 0){
        cout << "There is 1 solution." << endl;
        cout << "The solution is: " << Quad_func_neg(a_input,b_input,c_input,D_value);
    }
    else {
        cout << "There are 2 solutions." << endl;
        cout << "The solutions are: " << Quad_func_pos(a_input,b_input,c_input,D_value) << " and "<< Quad_func_neg(a_input,b_input,c_input,D_value) << endl;
    }
    return 0 ;
}

