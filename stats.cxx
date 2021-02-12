
/*                              MOHAMMED FAHAD , ID: 24006611
“The work in this assignment is my own. Any outside sources have been properly cited.”
 */


/* Description : This .cpp file contains the definition for class stats.cpp
which resides inside the main_savitch_2C namespace. This class
keeps track of the largest, smallest, total amount and
number-of-entry values in a sequence.
*/

#include <assert.h> // header file for the class
#include "stats.h" // needed for assert()

using namespace main_savitch_2C; // defining the namespace

// default constructor which initializes the member variables count and total
// to 0.
statistician::statistician()
{
// initializing member variables
count = 0;
total = 0;
}

// This function adds values to the sequence of entries. It also sets the value
// for member variables.
void statistician::next(double r)
{
total += r; // update total

// if object has previous entries
if (length() > 0)
{
if (r < tinyest)
{
tinyest = r;
}

if (r > largest)
{
largest = r;
}
}

// if object does not have entries
else if(length() == 0)
{
tinyest = r;
largest = r;
}

count++; // increment count
}

// This function clears the statistician by setting the member variables
// to 0.
void statistician::reset()
{
count = 0;
total = 0;
tinyest = 0;
largest = 0;
}

// This function calculates and returns the mean value for the sequence
// of entries.
double statistician::mean() const
{
assert(length() > 0); // make sure object has entries.

return (total / count);
}

// This function returns the minimum value for the sequence of entries.
double statistician::minimum() const
{
assert(length() > 0); // make sure object has entries.

return tinyest;
}

// This function returns the maximum value for the sequence of entries.
double statistician::maximum() const
{
assert(length() > 0); // make sure object has entries.

return largest;
}

// This function overloads the (+) operator.
statistician main_savitch_2C::operator+(const statistician& s1, const statistician& s2)
{
statistician s3;

// if s1 has no entries
if (s1.length() == 0)
{
s3.total = s2.total;
s3.count = s2.count;
s3.tinyest = s2.tinyest;
s3.largest = s2.largest;
}
// if s2 has no entries
else if (s2.length() == 0)
{
s3.total = s1.total;
s3.count = s1.count;
s3.tinyest = s1.tinyest;
s3.largest = s1.largest;
}
// if both s1 and s2 have entries
else
{
s3.total = s1.total + s2.total;
s3.count = s1.count + s2.count;

if (s1.tinyest < s2.tinyest)
{
s3.tinyest = s1.tinyest;
}
else
{
s3.tinyest = s2.tinyest;
}

if (s1.largest > s2.largest)
{
s3.largest = s1.largest;
}
else
{
s3.largest = s2.largest;
}
}

return s3;
}

// This function overloads the (*) operator.
statistician main_savitch_2C::operator *(double scale, const statistician& s)
{
statistician s1;

// if s has entries
if (s.length() != 0)
{
s1.total = scale * s.total;
s1.count = s.count;

// if scale is positive
if (scale > 0)
{
s1.tinyest = scale * s.tinyest;
s1.largest = scale * s.largest;
}
// if scale is negative
else
{
s1.tinyest = scale * s.largest;
s1.largest = scale * s.tinyest;
}
}

return s1;
}

// This function overloads the (==) operator.
bool main_savitch_2C::operator ==(const statistician& s1, const statistician& s2)
{
// In order for two statisticians to be equal, they must have the same length
// Also, if their length is greater than zero, they must also have the same
// mean, the same minimum, the same maximum, and the same sum.
if ((s1.length() == 0 && s2.length() == 0) || (s1.length() == s2.length()
&& s1.sum() == s2.sum() && s1.mean() == s2.mean()
&& s1.minimum() == s2.minimum() && s1.maximum() == s2.maximum()))
{
return true; // s1 equals s2
}
return false; // s1 does not equal s2
}
