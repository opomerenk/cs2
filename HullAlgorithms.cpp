/**
 * @file
 * @author The CS2 TA Team
 * @version 1.0
 * @date 2013-2014
 * @copyright This code is in the public domain.
 *
 * @brief The gift wrapping and Graham scan convex hull algorithms
 * (implementation).
 *
 */
#include "HullAlgorithms.hpp"

/**
 * TO STUDENTS: In all of the following functions, feel free to change the
 * function arguments and/or write helper functions as you see fit. Remember to
 * add the function header to HullAlgorithms.hpp if you write a helper function!
 *
 * Our reference implementation has four helper functions and the function(s)
 * copied over from angleSort.cpp.
 */

/**
 * @brief Partitions 2 corresponding vectors of angles and points to
 * enable the in-place quicksort algorithm.
 */
 
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

/**
 * @brief Sorts two corresponding vectors of angles and points.
 */
  
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

/**
 * @brief Checks to see if a left turn was made between 3 points.
 */ 
 
bool LeftTurn(Tuple* a, Tuple* b, Tuple* c)
{
	// Store cross product
	int test = (b->x - a->x) * (c->y - a->y) - (b->y - a->y) * (c->x - a->x);
	if (test >= 0)
	{
		return true;
	}
	else
	{
		return false;
	}
} 
 
 /**
  * @brief Uses the gift wrapping algorithm to implement a convex hull.
  * 
  * pick first point, then find leftmost point:
  * FOR all points:
  * 	IF point(x) < first point(x) THEN
  * 		first point = point
  * original point = leftmost point, add to hull
  * left turn count = 0
  * iterate through all points:
  * 	iterate again through all points and check for a left turn through all
  * 		possible combinations
  * 		left turn count ++
  * 	once left turn count = number of total points:
  * 		set next leftmost point to this current point
  * 		add current point to hull
  * 	once leftmost point = original point:
  * 		stop
  * 
  * 
  */ 
 
void DoGiftWrap(vector<Tuple*> points, ConvexHullApp *app)
{
	// Locate leftmost point and add it to the hull
	Tuple* leftmost_point = points[0];
    for (unsigned int i = 0; i < points.size(); i++)
    {
		if (points[i]->x < leftmost_point->x)
		{
			leftmost_point = points[i];
		}
    }
    Tuple* original_point = leftmost_point;
    app->add_to_hull(leftmost_point);
    // Keep track of how many left turns have occurred and whether
    // the hull is closed
    int left_turn_count = 0;
    bool closed = false;
    while (closed == false)
    {
		// Check all points for left turns
		for (unsigned int j = 0; j < points.size(); j++)
		{
			for (unsigned int k = 0; k < points.size(); k++)
			{
				// Make sure the point in question is not the jumping-off point,
				// and check to make sure a left turn occurs for all other points
				if ((LeftTurn(leftmost_point, points[j], points[k]) == true) &&
						(leftmost_point != points[j]))
				{
					left_turn_count++;
				}
			}
			// Once all points are checked, add the point to the hull and
			// move to next point
			if (left_turn_count == (int) points.size())
			{
				leftmost_point = points[j];
				app->add_to_hull(points[j]);
				// Stop the algorithm once the hull is closed
				if (points[j] == original_point)
				{
					closed = true;
				}
			}
			left_turn_count = 0;
		}
	}
}

 /**
 * @brief Executes a Graham Scan to implement a convex hull.
 * 
 * pick first point, then find bottom point:
 * FOR all points:
 * 	IF point(x) < first point(x) THEN
 * 		first point = point
 * compute all angles with respect to bottom point
 * sort angles
 * create a temp vector to store points on the hull
 * push the first and second values in the sorted points set onto temp
 * for all remaining points:
 * 		if a left turn is not created between the last 3 points:
 * 			remove the middle point from the temp set
 * add everything in temp to hull
 * add original point to hull
 * 
 * 
 */
 
void DoGrahamScan(vector<Tuple*> points, ConvexHullApp *app)
{
	// Locate starting point (point with smallest y coordinates)
	Tuple* bottom_point = points[0];
	vector<double> angles;
	vector<Tuple*> temp;
    for (unsigned int i = 0; i < points.size(); i++)
    {
		if (points[i]->y > bottom_point->y)
		{
			bottom_point = points[i];
		}
    }
    // Compute all angles of other points relative to the starting point,
    // then sort the vectors of angles and their corresponding points
	for (unsigned int k = 0; k < points.size(); k++)
	{
		angles.push_back(bottom_point->angle_wrt_pt(points[k]));
	}	
	int left = 0;
	int right = (int) angles.size() - 1;
	quicksort_inplace(angles, points, left, right);
	// Introduce a new vector to keep track of the points on the hull
	temp.push_back(bottom_point);
	temp.push_back(points[1]);
	// Check remaining points (other than the first and second)
	for (unsigned int i = 2; i < points.size(); i++)
	{
		// Add the next point, and check if a left turn is created.
		// If a left turn did not occur, remove the middle point
		temp.push_back(points[i]);
		while (LeftTurn(temp[temp.size()-2], temp[temp.size()-1], points[i]) == false)
		{
			temp.pop_back();
		}
	}
	// Add everything in temp to the hull, then add the original first point
	for (unsigned int j = 0; j < temp.size(); j++)
	{
		app->add_to_hull(temp[j]);
	}
	app->add_to_hull(bottom_point);
}
