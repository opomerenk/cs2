/**
 * @file
 * @author The CS2 TA Team
 * @version 1.0
 * @date 2013-2014
 * @copyright This code is in the public domain.
 *
 * @brief The bubble sort, quick sort, merge sort, and in-place quicksort
 * algorithms (implementation).
 *
 */
#include "sorter.hpp"

int main(int argc, char* argv[])
{
    // Set up buffers and data input
    std::vector<int> nums;
    std::string line;
    char *filename;
    int sort_type;

    // Ensure that at most one type of sort and at least a filename are specified.
    if (argc > 3 || argc < 2)
    {
        usage();
    }

    // default sort is bubble sort
    sort_type = BUBBLE_SORT;

    // Figure out which sort to use
    for (int i = 1; i < argc; ++i)
    {
        char *arg = argv[i];
        if (strcmp(arg, "-b") == 0) { sort_type = BUBBLE_SORT; }
        else if (strcmp(arg, "-q") == 0) { sort_type = QUICK_SORT; }
        else if (strcmp(arg, "-m") == 0) { sort_type = MERGE_SORT; }
        else if (strcmp(arg, "-qi") == 0) { sort_type = QUICK_SORT_INPLACE; }
        else { filename = argv[i]; }
    }

    // Read the file and fill our vector of integers
    // THIS FUNCTION IS STUDENT IMPLEMENTED
    readFile(filename, nums);

    switch (sort_type)
    {
        case BUBBLE_SORT:
        print_vector(bubbleSort(nums));
        break;

        case QUICK_SORT:
        print_vector(quickSort(nums));
        break;

        case MERGE_SORT:
        print_vector(mergeSort(nums));
        break;

        case QUICK_SORT_INPLACE:
        quicksort_inplace(nums, 0, nums.size() - 1);
        print_vector(nums);
        break;

        default:
        usage();
        break;
    }
    return 0;
}

/**
 * Usage    Prints out a usage statement and exits.
 */
void usage()
{
    std::cerr << usage_string << std::endl;
    exit(1);
}

/**
 * TO STUDENTS: In all of the following functions, feel free to change the
 * function arguments and/or write helper functions as you see fit. Remember to
 * add the function header to sorter.hpp if you write a helper function!
 */
 
/**
 * Bubble sort returns a sorted vector, list, in ascending order by 
 * comparing adjacent elements and switching them if the left one is
 * larger than the right one.
 * 
 * FOR k = length(list) - 1, k > 0 THEN
 * FOR i < k THEN
 * 		IF list[i+1] < list[i] THEN
 * 			list[i+1] = list[i]
 * 			list[i] = list[i+1]
 * return list
 */
 
std::vector<int> bubbleSort(std::vector<int> &list)
{
	// Count down the length of the input list so that each time we
	// go through the list to compare elements, we only compare the
	// unsorted ones 
	if (list.size() == 0)
	{
		return list;
	}
	for (unsigned int k = list.size() - 1; k > 0; k--)
	{
		// Iterate once through the list (only the k unsorted elements)
		for (unsigned int i = 0; i < k; i++)
		{
			// If the previous element > the next element, switch them
			if (list[i+1] < list[i]) 
			{
				int temp1 = list[i];
				int temp2 = list[i+1];
				list[i] = temp2;
				list[i+1] = temp1;
			}
		}
	}
    return list;
}

/**
 * QuickSort returns a sorted list in ascending order.
 * 
 * IF size(list) == 1 or 0 THEN
 * 		return list
 * ELSE
 * 		instantiate vector left
 * 		instantiate vector right
 * 		instantiate pivot = list[0]
 * 		FOR i = 1, i < size(list), i++ THEN
 * 			IF list[i] <= pivot THEN
 * 				add list[i] to left
 *			ELSE IF list[i] > pivot THEN
 * 				add list[i] to right
 * 		right = quickSort(right)
 * 		left = quickSort(left)
 * 		add pivot to left
 * 		concatenate left with right
 * 		return left
 */ 

std::vector<int> quickSort(std::vector<int> &list)
{
	// Base case: empty list or list of length 1
	if ((list.size() == 1) || list.size() == 0)
	{
		return list;
	}
	else
	{
		std::vector<int> left;
		std::vector<int> right;
		int pivot = list[0];
		// Compare all elements (not including the pivot) against the
		// pivot. Add to left vector if <=, to right vector if >
		for (unsigned int i = 1; i < list.size(); i++)
		{
			if (list[i] <= pivot)
			{
				left.push_back(list[i]);
			}
			else if (list[i] > pivot)
			{
				right.push_back(list[i]);
			}
		}
		// Recursion: sort subvectors left and right
		left = quickSort(left);
		right = quickSort(right);
		// Add pivot to sorted left vector
		left.push_back(pivot);
		// Add sorted right vector to left vector to produce final sort
		for (unsigned int j = 0; j < right.size(); j++)
		{
			left.push_back(right[j]);
		}
		return left;
	}
}

/**
 * MergeSort returns a sorted vector, list, in ascending order.
 * 
 * IF size(list) is 1 or 0 THEN
 * 		return list
 * ELSE
 * 		length = size(list)
 * 		instantiate vector left
 * 		instantiate vector right
 * 		FOR i = 0, i < half of length, i++ THEN
 * 			add list[i] to left
 * 		FOR j = half of length, j < length, j++ THEN
 * 			add list[j] to right
 * 		left = mergeSort(left)
 * 		right = mergeSort(right)
 * 		return merge(left, right)
 * ENDIF
 */
 
std::vector<int> mergeSort(std::vector<int> &list)
{
	// Base case: empty vector or vector of length 1
	if ((list.size() == 1) || list.size() == 0)
	{
		return list;
	}
	else
	{
		// Keep track of original length, instantiate left and right vectors
		// to divide list in half
		unsigned int length = list.size();
		std::vector<int> left;
		std::vector<int> right;
		for (unsigned int i = 0; i < length / 2; i++)
		{
			left.push_back(list[i]);
		}
		for (unsigned int j = length / 2; j < length; j++)
		{
			right.push_back(list[j]);
		}
		// Recursive step: sort left and right vectors, return merge
		// of the two vectors
		left = mergeSort(left);
		right = mergeSort(right);
		return merge(left, right);
	}	
}

/**
 * Helper function Merge used to assist MergeSort. Merges two lists
 * by comparing their head elements. Takes 2 vectors, left and right.
 * 
 * instantiate vector sort
 * i = 0
 * j = 0
 * WHILE i < size(left) and j < size(right)
 * 		IF left[i] < right[j] THEN
 * 			add left[i] to sort
 * 			i++
 * 		ELSE IF left[i] > right[j] THEN
 * 			add right[j] to sort
 * 			j++
 * 		ELSE
 * 			add left[i] to sort
 * 			add left[j] to sort
 * 			i++
 * 			j++
 * IF i == size(left) THEN
 * 		WHILE j < size(right)
 * 			add right[j] to sort
 * 			j++
 * ELSE IF j == size(right) THEN
 * 		WHILE i < size(left)
 * 			add left[i] to sort
 * 			i++
 * return sort
 */
std::vector<int> merge(std::vector<int> &left, std::vector<int> &right)
{
	// Set up empty sort vector to fill, and 2 counters to keep track
	// of where we are in the 2 input vectors as they merge
    std::vector<int> sort;
    unsigned int i = 0;
    unsigned int j = 0;
    // Compare head elements only while both vectors contain elements
    // that haven't been added to the sort vector
    while (i < left.size() && j < right.size())
    {
		if (left[i] < right[j])
		{
			sort.push_back(left[i]);
			i++;
		}
		else if (left[i] > right[j])
		{
			sort.push_back(right[j]);
			j++;
		}
		// If both head elements are equal, add them both to the
		// sort vector and count up for both vectors
		else
		{
			sort.push_back(left[i]);
			sort.push_back(right[j]);
			i++;
			j++;
		}
	}
	// If the left vector has no more elements to be compared, add
	// the entire sorted right vector
	if (i == left.size())
	{
		while (j < right.size())
		{
			sort.push_back(right[j]);
			j++;
		}
	}
	// Otherwise, do the reverse and add the entire sorted left vector
	else if (j == right.size())
	{
		while (i < left.size())
		{
			sort.push_back(left[i]);
			i++;
		}
	}
	return sort;
}

/*
 * quicksort_inplace:  In-place version of the quicksort algorithm. Requires
 *              O(1) instead of O(N) space, same time complexity. Each call of
 *              the method partitions the list around the pivot (an item taken
 *              from the middle of the array) with items left of the pivot
 *              smaller than it and items to its right larger than it. Then the
 *              method recursively sorts the left and right portions of the list
 *              until it reaches its base case: a list of length 1 is already
 *              sorted.
 *
 * @param list: pointer to integer array to be sorted
 * @returns:    Nothing, the array is sorted IN-PLACE.
 *
 */
 
 /**
  * Partition moves any element larger than the pivot (which is the
  * rightmost endpoint of the vector being sorted) to the right of the
  * pivot.
  * 
  * index = rightmost endpoint
  * iterate through vector from left to index:
  * 	if current element > pivot:
  * 		store value of element
  * 		shift all remaining elements after element back by one,
  * 			add element to the rightmost point of vector
  * 		subtract 1 from index because its position shifted back 1
  * 		subtract 1 from iterator of main for loop, because now		
  * 			must investigate elements after back shift
  * return new index
  */
 
 int partition(std::vector<int> &list, int pivot, int left, int right)
{
	// Index of pivot is rightmost value
	int index = right;
	// Iterate from left endpoint to index
	for (int j = left; j < index; j++)
	{
		// Shift all elements that follow element back by 1 if 
		// element > pivot, append element to end of vector
		if (list[j] > pivot)
		{
			int move_element = list[j];
			for (int i = j + 1; i <= right; i++)
			{
				int element = list[i];
				list[i-1] = element;
			}
			list[right] = move_element;
			// Index and j both are subtracted by 1 to account for the
			// backwards shift
			index--;
			j--;
			
		}
	}
	return index;
}
 
/**
 * Quicksort takes a vector and two enpoint locations in the vector
 * and sorts it.
 * 
 * if left endpoint smaller than right endpoint:
 * 		set pivot to right endpoint
 * 		apply partition function, store new index value
 * 		set new endpoints: top left = index - 1, top right = index + 1
 * 		recursive step: quicksort(left, top left) and
 * 			quicksort(right, top right)
 * return nothing b/c void function
 */
   
void quicksort_inplace(std::vector<int> &list, int left, int right)
{
	if (left < right)
	{	
		int pivot = list[right];
		// Store new location of pivot after initial sort
		int index = partition(list, pivot, left, right);
		// Set new enpoint values around new pivot location
		int left_top = index - 1;
		int right_bottom = index + 1;
		// Recursive step on two subvectors on either side of pivot
		quicksort_inplace(list, left, left_top);
		quicksort_inplace(list, right_bottom, right);
	}
}






