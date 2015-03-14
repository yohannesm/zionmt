# Introduction #

a program to implement an stack-allocated 2D matrix object. Matrix must be initialized with an array or  default value, because we have two constructors with same signature. Therefore, it will be ambiguous if we don't specify it. If we don't provide an allocator, Matrix uses the standard allocator from STD library. Allocator provided will be rebinded into an allocator for an array. For internal data, we used pointer and char array to prevent the compiler from calling the default constructor of array from "Array.h".
We already override the copy constructor, assignment, and destructor.

## bool operator == ##
It tells whether the both matrix is same or not.
## bool operator < ##
It tells whether the rhs matrix's values are larger than lhs matrix's values.
## operator + ##
Add the some constant value to the each value in the Matrix. Add also each value from rhs Matrix to the lhs Matrix.
## operator - ##
subtract the constant value from the Matrix. subtract each value from rhs Matrix to the lhs Matrix.
## operator **##
Multiply the constant value to each value in the Matrix.
## operator / ##
Divide each value from the matrix by constant value.
## constructor containing constant value ##
constructor that takes the array containing the constant value.
## constructor containing the pointer ##
constructor that takes the array containing the pointer to the array.
## reference operator [.md](.md) ##
subscript for the matrix. It returns the pointer pointing to array.
## const\_reference operator [.md](.md) ##
const subscript for the matrix. It returns the pointer pointing to the const array.
## operator += ##
It works in same way as '+'
## operator -= ##
It works in same way as '-'
## operator**= ##
It works in same way as '