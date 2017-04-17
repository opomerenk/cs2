/**
 *@brief Solves the given quadratic equation.
 * 
 * This function, given real coefficients A, B, C to the equation
 * A*x*x + B*x + C = 0, returns the real part of a solution to the
 * equation thus defined. Where two real solutions exist, the one
 * closer to positive infinity is chosen.
 *
 * @param a the quadratic coefficient.
 * @param b the linear coefficient.
 * @param c the constant coefficient.
 *
 * @return the real part of a solution to the defined quadratic equation,
 *         as described.
 */
 
 #include <cmath>  
 #include <iostream>
 
 double qfsolve(double a, double b, double c)
 {
	 double x1, x2, d;
	 d = b * b - 4 * a * c; // define determinant of quadratic function
	 if (d >= 0) // If determinant is positive, a real solution exists
	 {
		 x1 = (-b + sqrt(d)) / (2 * a);
		 x2 = (-b - sqrt(d)) / (2 * a);
	 }
	 else
	 {
		 return 0; // return 0 if no real solution exists
	 }
	 if (x1 >= x2) // return value closest to positive infinity
	 {
		 return x1;
	 }
	 else
	 {
		 return x2;
	 }
 }
 
 int main(int argc, char ** argv)
 {
	 // Try some test cases
	 double a = qfsolve(1.0, 2.0, -3.0);
	 std::cout << "Inputs: A = 1, B = 2, C = -3. Output: " << a << std::endl;
	 double b = qfsolve(2.0, 0.0, 6.0);
	 std::cout << "Inputs: A = 2, B = 0, C = 6. Output: " << b << std::endl;
	 double c = qfsolve(4.0, 1.0, -2.0);
	 std::cout << "Inputs: A = 4, B = 1, C = -2. Output: " << c << std::endl;
	 double d = qfsolve(-3.0, 8.0, 3.0);
	 std::cout << "Inputs: A = -3, B = 8, C = 3. Output: " << d << std::endl;
	 double e = qfsolve(1.0, 4.0, 1.0);
	 std::cout << "Inputs: A = 1, B = 4, C = 1. Output: " << e << std::endl;
	 return 0;
 }
	 
	 
	 
	 
	 
 
