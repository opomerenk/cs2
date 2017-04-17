/**
 * @file arrays1.cpp
 * @author The CS2 TA Team <cs2tas@caltech.edu>
 * @date 2014-2015
 * @copyright This code is in the public domain.
 *
 * @brief An array example.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

#define TEST_SIZE 1000000

using namespace std;

//find maximum value in an array
int max_val(int *arr, int n)
{
	int max = *(arr);
	for (int i = 0; i < n; i++)
	{
		//iterate through array, comparing each element to largest one
		//found so far
		if (*(arr + i) > max)
		{
			max = *(arr + i);
		}
	}
	return max;
}

//compute arithmetic mean of an array
double mean_val(int *arr, int n)
{
	double total = 0;
	double mean;
	for (int i = 0; i < n; i++)
	{
		//sum elements in array
		total += *(arr + i);
	}
	mean = total / n;
	return mean;
}

//overwrite n elements of array with an ascending sequence
void overwrite(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = i;
	}
}	

/**
 * @brief Sets up and runs an array example.
 */
int main(int argc, char ** argv)
{

    /*-------- CHANGE NOTHING BELOW THIS LINE FOR PART 1 --------*/
    int *test_values = new int[TEST_SIZE];
    int real_size;

    // seed the PRNG
    srand(time(nullptr));

    // initialize the test array to garbage
    for (int i = 0; i < TEST_SIZE; i++)
    {
        test_values[i] = rand();
    }

    // determine a real size
    real_size = TEST_SIZE - (rand() % 20);

    // initialize the meaningful part of the test array to random numbers
    // all of which are less than one million
    for (int i = 0; i < real_size; i++)
    {
        test_values[i] = rand() % 1000000;
    }
    
    /*-------- CHANGE NOTHING ABOVE THIS LINE FOR PART 1 --------*/

    //print maximum and mean values of array
    cout << max_val(test_values, real_size) << endl;
	cout << mean_val(test_values, real_size) << endl;
	//replace all values of array with an ascending sequence and print them
	overwrite(test_values, real_size);
	for (int i = 0; i < real_size; i++)
    {
        cout << test_values[i] << " ";
    }
    cout << endl;
    
    //free memory that was used 
    delete[] test_values;
	return 0;
}
