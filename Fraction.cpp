// Assignment 4: Fraction.cpp
// Member-function definitions for class Fraction.
// Author: Veronica Logvinenko A01208105 
// Date: 2021-02-08

#include "Fraction.h"
#include "GCD.h" // template function for calculating greatest common divisor
#include <iostream>

using namespace std;

//default constructor
Fraction::Fraction() 
	:numerator(0), denominator(1)
{}

// second ctor, which requires at least one long long argument
Fraction::Fraction(long long num, long long denom) 
	:numerator(num), denominator(denom)
{
	simplify();
}

// Returns numerator
long long Fraction::getNum(void)const 
{
	return numerator;
}

// Returns denominator
long long Fraction::getDenom(void)const 
{
	return denominator;
}

//Implementation of the timesEq() member function
//Performs similar operation as the *= operator on the built-in types
const Fraction & Fraction::timesEq(const Fraction & op )
{
	numerator *= op.numerator;
	denominator *= op.denominator;

	simplify();  // will make sure that denominator is positive and
	             //   will invoke gcd() function to reduce fraction
	             //   as much as possible

	return (*this); // returns the object which invoked the method
}

//Implementation of the divideEq() memeber function
//Divides RHS into the Fraction object invoked with this method
//  (thereby modifying the Fraction object) and returns the result
const Fraction & Fraction::divideEq(const Fraction& RHS) 
{
	numerator *= RHS.denominator;
	denominator *= RHS.numerator;

	simplify();
 	
	return (*this);
}

//Implementation of the plusEq() memeber function
//Adds RHS to the Fraction object invoked with this method
//(thereby modifying the Fraction object) and returns the result
const Fraction & Fraction::plusEq(const Fraction& RHS)
{
	long long leastCommonDivisor;

	leastCommonDivisor = (denominator * RHS.denominator) / gcd(denominator, RHS.denominator);

	numerator = numerator * (leastCommonDivisor / denominator) + RHS.numerator * (leastCommonDivisor / RHS.denominator);
	denominator = leastCommonDivisor;

	simplify();

	return (*this);
}

//Implementation of the minusEq() memeber function
//Subtracts RHS from the Fraction object invoked with this method
//(thereby modifying the Fraction object) and returns the result							  
const Fraction & Fraction::minusEq(const Fraction& RHS)
{
	long long leastCommonDivisor;

	leastCommonDivisor = (denominator * RHS.denominator) / gcd(denominator, RHS.denominator);
	
	numerator = numerator * (leastCommonDivisor / denominator) - RHS.numerator * (leastCommonDivisor / RHS.denominator);
	denominator = leastCommonDivisor;

	simplify();

	return (*this);
}
										  
//Implementation of the negate() member function
//Returns the negation of the Fraction object invoked with the method but must NOT
//  modify the actual Fraction object invoked 
Fraction Fraction::negate()const
{
	Fraction temp = *this;
	temp.numerator = -temp.getNum();
	return temp;
}

//Implementation of the display() member function	
// Outputs to standard output stream the Fraction object
//   in the format: numerator/denominator
void Fraction::display()const
{
	cout << numerator <<"/" << denominator;
}

//Implementation of the simplify() member function
// this method reduces the Fraction objects as much as possible.  
//It also ensures that the denominator is positive.
void Fraction::simplify()
{
	long long commonValue;

	commonValue = gcd(numerator, denominator);

	numerator = getNum() / commonValue;
	denominator = getDenom() / commonValue;

	if (getDenom() < 0) {
		numerator = -getNum();
		denominator = -getDenom();
	}

}
