// Assignment 4: GCD.h
// Template functionfor to calculate a greatest common divisor of 2 values  
// Author: Veronica Logvinenko A01208105 
// Date: 2021-02-08

template < typename T>

T gcd(T x, T y)
{
    //ensure positive numbers
    if (x < 0) {
        x = x * -1;
    }
    if (y < 0) {
        y = y * -1;
    }

    T greatest = 1; // current greatest common divisor, 1 is minimum

    // loop from 2 to smaller of x and y
    for (int i = 2; i <= ((x < y) ? x : y); i++)
    {
        // if current i divides both x and y
        if (x % i == 0 && y % i == 0)
        {
            greatest = i; // update greatest common divisor
        }
    } // end for

    return greatest; // return greatest common divisor found
} // end function gcd