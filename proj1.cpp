/*
Jie Wu
Data Structures
HW#1
Due Date: 9/19/17
*/

/** @mainpage
 *
 * CISC 2200: Data Structures<br/>
 * Project 1: Computing Powers<br/>
 *
 * <p>Compare the function of three different functions for powers.</p>
 *
 * @author Harry Q. Bovik, PhD
 * @date 35 Octember 12345
 * @file proj1.cc
 *
 **********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

// function prototypes
template <class T>
T power1(T x, unsigned int n, unsigned int& mults);

template <class T>
T power2(T x, unsigned int n, unsigned int& mults);

template <class T>
T power3(T x, unsigned int n, unsigned int& mults);

template <class T>
void printReport(T base, unsigned int pow,
                 T result1, T result2, T result3,
                 unsigned int mults1, unsigned int mults2,
                 unsigned int mults3);

/**
 * The usual main function.
 *
 * It computes the powers 2<sup><em>i</em></sup> for
 * <em>i=</em>0,1,2,..,32 via all three methods, reporting the number
 * of multiplications needed for each method.  (Note what happens for
 * 2^32.)  It then does likewise for 0.5<sup><em>i</em></sup>, but now
 * with <em>i=</em>0,1,2,...64
 *
 */

int main()
{
   unsigned int mults1, mults2, mults3;
   cout << "Test for integer base:\n";
   for (unsigned int pow = 0; pow <= 32; pow++) {
      unsigned int base = 2;
      unsigned int result1 = power1(base, pow, mults1);
      unsigned int result2 = power2(base, pow, mults2);
      unsigned int result3 = power3(base, pow, mults3);
      printReport(base, pow, result1, result2, result3,
                  mults1, mults2, mults3);
   }
   cout << "\nTest for floating-point base:\n";
   for (unsigned int pow = 0; pow <= 64; pow++) {
      double base = 0.5;
      double result1 = power1(base, pow, mults1);
      double result2 = power2(base, pow, mults2);
      double result3 = power3(base, pow, mults3);
      printReport(base, pow, result1, result2, result3,
                  mults1, mults2, mults3);
   }
}

/**
 * Iterative function to compute a power <em>x<sup>n</sup></em>.
 *
 * @param x is the base
 * @param n is the exponent
 * @param mults is the number of multiplications used, which it was initially zero.
 * @return result and 1
 * @pre n >= 0
 * @post mults is the total number of multiplications used
 */

template <class T>
T power1(T x, unsigned int n, unsigned int& mults)
{
    mults = 0;
    if(n == 0)
        return 1;
    else if(n == 1)
        return x;
    else if(n >= 2)
    {
        T result = result * x;
        for(int i = 1; i < n; i++)
            mults++;
        return result;
    }
    return 1;
}

/**
 * A function that computes a^n to a*a^(n-1)
 * @param x is the power
 * @param n is the exponent
 * @param multi is total of multiplications used that is assumed to be set by the pervious
 * recursive functions.
 * @return result and 1
 * @pre n >= 0
 * @post multi is the new number of multiplications used
 */

template <class T>
T power2(T x, unsigned int n, unsigned int& mults)
{
    mults = 0;
    if(n == 0)
        return 1;
    else if(n == 1)
        return x;
    else if(n >= 2){
        T result = x*power2(x, n-1, mults);
        mults++;
        return result;
    }
    return 1;
}

/**
 * @param x is the power
 * @param n is the exponent
 * @param multi is total of multiplications used that is assumed to be set by the pervious
 * recursive functions.
 * @return result and 1
 * @pre n >= 0
 * @post multi is the new number of multiplications used
 */
template <class T>
T power3(T x, unsigned int n, unsigned int& mults)
{
   mults = 0;
   if(n == 0)
      return 1;
   else if(n == 1)
      return x;
   else if(n % 2 == 0) //if the power is even
   {
      T result = power3(x, n/2, mults);
      mults++;
      return result * result;
   }
   //if the power is old
   else {
      T result = power3(x, n/2, mults);
      mults += 2;
      return result * result * x;
   }
   return 1;
}

/**
 * Report the results of three different exponentiation calculations.
 *
 * To give you practice using doxygen, I'll let you fill in the rest
 * of this comment block yourself.
 *
 * @param base is the number of power
 * @param power is the exponent
 * @param mults1 is the number of multiplications from power1
 * @param mults2 is the number of multiplications from power2
 * @param mults3 is the number of multiplications from power3
 * @param result1 is the output from power1
 * @param result2 is the output from power2
 * @param result3 is the output from power3
 */

template <class T>
void printReport(T base, unsigned int pow,
                 T result1, T result2, T result3,
                 unsigned int mults1, unsigned int mults2,
                 unsigned int mults3)
{
   cout << base << "^" << pow << " = ";
   if (result1 == result2 && result2 == result3)
      cout << result1 << ": ";
   else
      cout << "(" << result1 << ", " << result2 << ", " << result3
           << ") [ERROR!]: ";
   cout << "mults1 = " << mults1 << ", mults2 = " << mults2
        << ", mults3 = " << mults3 << endl;
}
/*
Sample Run

Test for integer base:
2^0 = 1: mults1 = 0, mults2 = 0, mults3 = 0
2^1 = 2: mults1 = 0, mults2 = 0, mults3 = 0
2^2 = 4: mults1 = 1, mults2 = 1, mults3 = 1
2^3 = 8: mults1 = 2, mults2 = 2, mults3 = 2
2^4 = 16: mults1 = 3, mults2 = 3, mults3 = 2
2^5 = 32: mults1 = 4, mults2 = 4, mults3 = 3
2^6 = 64: mults1 = 5, mults2 = 5, mults3 = 3
2^7 = 128: mults1 = 6, mults2 = 6, mults3 = 4
2^8 = 256: mults1 = 7, mults2 = 7, mults3 = 3
2^9 = 512: mults1 = 8, mults2 = 8, mults3 = 4
2^10 = 1024: mults1 = 9, mults2 = 9, mults3 = 4
2^11 = 2048: mults1 = 10, mults2 = 10, mults3 = 5
2^12 = 4096: mults1 = 11, mults2 = 11, mults3 = 4
2^13 = 8192: mults1 = 12, mults2 = 12, mults3 = 5
2^14 = 16384: mults1 = 13, mults2 = 13, mults3 = 5
2^15 = 32768: mults1 = 14, mults2 = 14, mults3 = 6
2^16 = 65536: mults1 = 15, mults2 = 15, mults3 = 4
2^17 = 131072: mults1 = 16, mults2 = 16, mults3 = 5
2^18 = 262144: mults1 = 17, mults2 = 17, mults3 = 5
2^19 = 524288: mults1 = 18, mults2 = 18, mults3 = 6
2^20 = 1048576: mults1 = 19, mults2 = 19, mults3 = 5
2^21 = 2097152: mults1 = 20, mults2 = 20, mults3 = 6
2^22 = 4194304: mults1 = 21, mults2 = 21, mults3 = 6
2^23 = 8388608: mults1 = 22, mults2 = 22, mults3 = 7
2^24 = 16777216: mults1 = 23, mults2 = 23, mults3 = 5
2^25 = 33554432: mults1 = 24, mults2 = 24, mults3 = 6
2^26 = 67108864: mults1 = 25, mults2 = 25, mults3 = 6
2^27 = 134217728: mults1 = 26, mults2 = 26, mults3 = 7
2^28 = 268435456: mults1 = 27, mults2 = 27, mults3 = 6
2^29 = 536870912: mults1 = 28, mults2 = 28, mults3 = 7
2^30 = 1073741824: mults1 = 29, mults2 = 29, mults3 = 7
2^31 = 2147483648: mults1 = 30, mults2 = 30, mults3 = 8
2^32 = 0: mults1 = 31, mults2 = 31, mults3 = 5

Test for floating-point base:
0.5^0 = 1: mults1 = 0, mults2 = 0, mults3 = 0
0.5^1 = 0.5: mults1 = 0, mults2 = 0, mults3 = 0
0.5^2 = 0.25: mults1 = 1, mults2 = 1, mults3 = 1
0.5^3 = 0.125: mults1 = 2, mults2 = 2, mults3 = 2
0.5^4 = 0.0625: mults1 = 3, mults2 = 3, mults3 = 2
0.5^5 = 0.03125: mults1 = 4, mults2 = 4, mults3 = 3
0.5^6 = 0.015625: mults1 = 5, mults2 = 5, mults3 = 3
0.5^7 = 0.0078125: mults1 = 6, mults2 = 6, mults3 = 4
0.5^8 = 0.00390625: mults1 = 7, mults2 = 7, mults3 = 3
0.5^9 = 0.00195312: mults1 = 8, mults2 = 8, mults3 = 4
0.5^10 = 0.000976562: mults1 = 9, mults2 = 9, mults3 = 4
0.5^11 = 0.000488281: mults1 = 10, mults2 = 10, mults3 = 5
0.5^12 = 0.000244141: mults1 = 11, mults2 = 11, mults3 = 4
0.5^13 = 0.00012207: mults1 = 12, mults2 = 12, mults3 = 5
0.5^14 = 6.10352e-05: mults1 = 13, mults2 = 13, mults3 = 5
0.5^15 = 3.05176e-05: mults1 = 14, mults2 = 14, mults3 = 6
0.5^16 = 1.52588e-05: mults1 = 15, mults2 = 15, mults3 = 4
0.5^17 = 7.62939e-06: mults1 = 16, mults2 = 16, mults3 = 5
0.5^18 = 3.8147e-06: mults1 = 17, mults2 = 17, mults3 = 5
0.5^19 = 1.90735e-06: mults1 = 18, mults2 = 18, mults3 = 6
0.5^20 = 9.53674e-07: mults1 = 19, mults2 = 19, mults3 = 5
0.5^21 = 4.76837e-07: mults1 = 20, mults2 = 20, mults3 = 6
0.5^22 = 2.38419e-07: mults1 = 21, mults2 = 21, mults3 = 6
0.5^23 = 1.19209e-07: mults1 = 22, mults2 = 22, mults3 = 7
0.5^24 = 5.96046e-08: mults1 = 23, mults2 = 23, mults3 = 5
0.5^25 = 2.98023e-08: mults1 = 24, mults2 = 24, mults3 = 6
0.5^26 = 1.49012e-08: mults1 = 25, mults2 = 25, mults3 = 6
0.5^27 = 7.45058e-09: mults1 = 26, mults2 = 26, mults3 = 7
0.5^28 = 3.72529e-09: mults1 = 27, mults2 = 27, mults3 = 6
0.5^29 = 1.86265e-09: mults1 = 28, mults2 = 28, mults3 = 7
0.5^30 = 9.31323e-10: mults1 = 29, mults2 = 29, mults3 = 7
0.5^31 = 4.65661e-10: mults1 = 30, mults2 = 30, mults3 = 8
0.5^32 = 2.32831e-10: mults1 = 31, mults2 = 31, mults3 = 5
0.5^33 = 1.16415e-10: mults1 = 32, mults2 = 32, mults3 = 6
0.5^34 = 5.82077e-11: mults1 = 33, mults2 = 33, mults3 = 6
0.5^35 = 2.91038e-11: mults1 = 34, mults2 = 34, mults3 = 7
0.5^36 = 1.45519e-11: mults1 = 35, mults2 = 35, mults3 = 6
0.5^37 = 7.27596e-12: mults1 = 36, mults2 = 36, mults3 = 7
0.5^38 = 3.63798e-12: mults1 = 37, mults2 = 37, mults3 = 7
0.5^39 = 1.81899e-12: mults1 = 38, mults2 = 38, mults3 = 8
0.5^40 = 9.09495e-13: mults1 = 39, mults2 = 39, mults3 = 6
0.5^41 = 4.54747e-13: mults1 = 40, mults2 = 40, mults3 = 7
0.5^42 = 2.27374e-13: mults1 = 41, mults2 = 41, mults3 = 7
0.5^43 = 1.13687e-13: mults1 = 42, mults2 = 42, mults3 = 8
0.5^44 = 5.68434e-14: mults1 = 43, mults2 = 43, mults3 = 7
0.5^45 = 2.84217e-14: mults1 = 44, mults2 = 44, mults3 = 8
0.5^46 = 1.42109e-14: mults1 = 45, mults2 = 45, mults3 = 8
0.5^47 = 7.10543e-15: mults1 = 46, mults2 = 46, mults3 = 9
0.5^48 = 3.55271e-15: mults1 = 47, mults2 = 47, mults3 = 6
0.5^49 = 1.77636e-15: mults1 = 48, mults2 = 48, mults3 = 7
0.5^50 = 8.88178e-16: mults1 = 49, mults2 = 49, mults3 = 7
0.5^51 = 4.44089e-16: mults1 = 50, mults2 = 50, mults3 = 8
0.5^52 = 2.22045e-16: mults1 = 51, mults2 = 51, mults3 = 7
0.5^53 = 1.11022e-16: mults1 = 52, mults2 = 52, mults3 = 8
0.5^54 = 5.55112e-17: mults1 = 53, mults2 = 53, mults3 = 8
0.5^55 = 2.77556e-17: mults1 = 54, mults2 = 54, mults3 = 9
0.5^56 = 1.38778e-17: mults1 = 55, mults2 = 55, mults3 = 7
0.5^57 = 6.93889e-18: mults1 = 56, mults2 = 56, mults3 = 8
0.5^58 = 3.46945e-18: mults1 = 57, mults2 = 57, mults3 = 8
0.5^59 = 1.73472e-18: mults1 = 58, mults2 = 58, mults3 = 9
0.5^60 = 8.67362e-19: mults1 = 59, mults2 = 59, mults3 = 8
0.5^61 = 4.33681e-19: mults1 = 60, mults2 = 60, mults3 = 9
0.5^62 = 2.1684e-19: mults1 = 61, mults2 = 61, mults3 = 9
0.5^63 = 1.0842e-19: mults1 = 62, mults2 = 62, mults3 = 10
0.5^64 = 5.42101e-20: mults1 = 63, mults2 = 63, mults3 = 6
*/
