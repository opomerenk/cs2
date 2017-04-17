/**
 * @file
 * @author The CS2 TA Team
 * @version 1.0
 * @date 2013-2014
 * @copyright This code is in the public domain.
 *
 * @brief An example of sorting (x, y) pairs by angle.
 *
 */
#include "structs.hpp"
#include <vector>


int partition(std::vector<double> &angles, vector<Tuple*> &points, double pivot, int left, int right)
{
	// Index of pivot is rightmost value
	int index = right;
	// Iterate from left endpoint to index
	for (int j = left; j < index; j++)
	{
		// Shift all elements that follow element back by 1 if 
		// element > pivot, append element to end of vector
		if (angles[j] > pivot)
		{
			double move_angle = angles[j];
			Tuple* move_point = points[j];
			for (int i = j + 1; i <= right; i++)
			{
				double angle = angles[i];
				Tuple* point = points[i];
				angles[i-1] = angle;
				points[i-1] = point;
			}
			angles[right] = move_angle;
			points[right] = move_point;
			// Index and j both are subtracted by 1 to account for the
			// backwards shift
			index--;
			j--;
			
		}
	}
	return index;
}

void quicksort_inplace(std::vector<double> &angles, vector<Tuple*> &points, int left, int right)
{
	if (left < right)
	{	
		int pivot = angles[right];
		// Store new location of pivot after initial sort
		int index = partition(angles, points, pivot, left, right);
		// Set new enpoint values around new pivot location
		int left_top = index - 1;
		int right_bottom = index + 1;
		// Recursive step on two subvectors on either side of pivot
		quicksort_inplace(angles, points, left, left_top);
		quicksort_inplace(angles, points, right_bottom, right);
	}
}

int main(int argc, char const *argv[])
{
    vector<double> angles {4.2, 2.8, 1.4, 5.0, 3.3};
    vector<Tuple*> points;
    // Print the initial points and angles
    for (unsigned int i = 0; i < angles.size(); ++i)
    {
        points.push_back(new Tuple(i, i));
    }
    for (vector<Tuple*>::iterator i = points.begin(); i != points.end(); ++i)
    {
        (*i)->printTuple();
    }
    for (vector<double>::iterator i = angles.begin(); i != angles.end(); ++i)
    {
        cout << *i << endl;
    }

    // Now sort them with respect to angle (points[i] corresponds to angle[i])

    /** THIS IS THE ONLY LINE OF THE MAIN LOOP YOU NEED TO MODIFY. */
    int left = 0;
    int right = (int) angles.size() - 1;
    quicksort_inplace(angles, points, left, right);
    /** REPLACE THE LINE ABOVE WITH A CALL TO YOUR SORTING FUNCTION. */

    // and print out the new points and angles
    for (vector<Tuple*>::iterator i = points.begin(); i != points.end(); ++i)
    {
        (*i)->printTuple();
    }
    for (vector<double>::iterator i = angles.begin(); i != angles.end(); ++i)
    {
        cout << *i << endl;
    }

    // Don't want to leak memory...
    // Either of the below implementations works
    // for (std::vector<Tuple*>::iterator i = points.begin(); i != points.end(); ++i)
    // {
    //     delete (*i);
    // }
    for (unsigned int i = 0; i < points.size(); ++i)
    {
        delete points[i];
    }
    return 0;
}
