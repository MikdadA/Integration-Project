/*
* Project - Integration
*/

#include <iostream>
using namespace std;

//FUNC represents functions of one variable that take a double as input and returns a double 
//integrate(f, a, b) will return the value of the definite integral of f evaluated between a and b.
typedef double (*FUNC)(double); //pointer to a function that takes a double and returns a double
double integrate(FUNC f, double a, double b) //we are given this function in the assignment 
{
    //initialize the variables to store
    double sum = 0; //set the sum to 0
	double delta = .0001; //delta is the width
	double x = a; //x represents the horizontal position of the rectangle

	while(x < b) //do a comparision 
	{
	    //f(x) is the height of the rectangle
		sum += f(x)*delta; //calculate the area and add it to the sum of the rectangle
		x = x + delta; //sum the width with x(horizontal position) 
	}
	return sum; //return the sum
}
double line(double x) //this is the function y=x
{
	return x; //return the value of x
}

double square(double x) //this is the function y=x^2
{
	return x*x; //return the value of x^2
}

double cube(double x) //this is the function y=x^3
{
	return x*x*x; //return the value of x^3
}

//in the main function we just need to print the solution of x, x^2, x^3
int main()
{
	cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl; //area is 12
	cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl; //area is 41
	cout << "The integral of f(x)= x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl; //area is 156
}