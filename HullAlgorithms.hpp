/**
 * @file
 * @author The CS2 TA Team
 * @version 1.0
 * @date 2013-2014
 * @copyright This code is in the public domain.
 *
 * @brief The gift wrapping and Graham scan convex hull algorithms
 * (header file).
 *
 */

#include <vector>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include "ConvexHullApp.hpp"
#include "structs.hpp"

using namespace std;

int partition(std::vector<double> &angles, vector<Tuple*> &points, double pivot, int left, int right);
void quicksort_inplace(std::vector<double> &angles, vector<Tuple*> &points, int left, int right);
bool LeftTurn(Tuple* a, Tuple* b, Tuple* c);
void DoGiftWrap(vector<Tuple*> points, ConvexHullApp *app);
void DoGrahamScan(vector<Tuple*> points, ConvexHullApp *app);


