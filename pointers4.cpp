/**
 * @file pointers4.cpp
 * @author The CS2 TA Team <cs2tas@caltech.edu>
 * @date 2015
 * @copyright This code is in the public domain.
 *
 * @brief Pointer-fu Exercise 4: Typecasting vs. address-of
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * @brief performs type castings
 */
int main(int argc, char *argv[])
{
    int a = 5, *b;
    void *c;

    // Now make `b` point to `a`.
    // To make b point to a, b should equal the address of a. The error
    // is that b was cast to a pointer type, not just set to the address
    // of a.
    b = &a;

    /***** CHANGE NOTHING BELOW THIS LINE *****/
    cout << "The value pointed by `b` is " << *b;
    /***** CHANGE NOTHING ABOVE THIS LINE *****/

    // Allocate an array of 10 ints.
    c = malloc(10 * sizeof(int));

    // Get the address of the array.
    // To get the address of c, we do not convert the address of c back
    // into a void pointer. Instead, since c is already a void pointer, b is cast
    // to the integer pointer type of c.
    b = (int *) c;

    /***** CHANGE NOTHING BELOW THIS LINE *****/
    b[2] = 5;
    /***** CHANGE NOTHING ABOVE THIS LINE *****/
    
    return 0;
}
