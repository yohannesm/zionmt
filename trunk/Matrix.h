// ----------------------------
// projects/c++/matrix/Matrix.h
// Copyright (C) 2009
// Glenn P. Downing
// ----------------------------

#ifndef Matrix_h
#define Matrix_h

// --------
// includes
// --------

#include <algorithm> // copy, equal, fill, lexicographical_compare
#include <cassert>   // assert
#include <cstddef>   // ptrdiff_t, size_t
#include <stdexcept> // out_of_range
#include <utility>   // !=, <=, >, >=
#include "Array.h"
// -----
// using
// -----

using namespace std::rel_ops;

// ----------
// namespaces
// ----------

namespace My {

// ------
// Matrix
// ------

template <typename T, std::size_t R, std::size_t C, typename A = std::allocator<T> >
class Matrix {
    public:
        // --------
        // typedefs
        // --------

        typedef ?                 value_type;

        typedef std::size_t       size_type;
        typedef std::ptrdiff_t    difference_type;

        typedef value_type*       pointer;
        typedef const value_type* const_pointer;

        typedef value_type&       reference;
        typedef const value_type& const_reference;

        typedef pointer           iterator;
        typedef const_pointer     const_iterator;

    public:
        // -----------
        // operator ==
        // -----------

        /**
         * <your documentation>
         */
        friend bool operator == (const Matrix& lhs, const Matrix& rhs) {
            // <your code>
            return false;}
        
        // ----------
        // operator <
        // ----------

        /**
         * <your documentation>
         */
        friend bool operator < (const Matrix& lhs, const Matrix& rhs) {
            // <your code>
            return false;}

        // ----------
        // operator +
        // ----------

        /**
         * <your documentation>
         */
        friend Matrix operator + (Matrix lhs, const T& rhs) {
            return lhs += rhs;}

        // ----------
        // operator +
        // ----------

        /**
         * <your documentation>
         */
        friend Matrix operator + (Matrix lhs, const Matrix& rhs) {
            return lhs += rhs;}

        // ----------
        // operator -
        // ----------

        /**
         * <your documentation>
         */
        friend Matrix operator - (Matrix lhs, const T& rhs) {
            return lhs -= rhs;}

        // ----------
        // operator -
        // ----------

        /**
         * <your documentation>
         */
        friend Matrix operator - (Matrix lhs, const Matrix& rhs) {
            return lhs -= rhs;}

        // ----------
        // operator *
        // ----------

        /**
         * <your documentation>
         */
        friend Matrix operator * (Matrix lhs, const T& rhs) {
            return lhs *= rhs;}

        // ----------
        // operator /
        // ----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs == 0)
         */
        friend Matrix operator / (Matrix lhs, const T& rhs) {
            return lhs /= rhs;}

        // ----------
        // operator %
        // ----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs <= 0)
         */
        friend Matrix operator % (Matrix lhs, const T& rhs) {
            return lhs %= rhs;}

    private:
        // <your data>

    public:
        // ------------
        // constructors
        // ------------

        /**
         * <your documentation>
         */
        explicit Matrix (const T& v = T()) {
            // <your code>
            }

        // Default copy, destructor, and copy assignment.
        // Matrix (const Matrix&);
        // ~Matrix ();
        // Matrix& operator = (const Matrix&);

        // -----------
        // operator []
        // -----------

        /**
         * <your documentation>
         */
        reference operator [] (size_type i) {
            // <your code>
            // dummy is just to be able to compile the skeleton, remove it
            static value_type dummy;
            return dummy;}

        /**
         * <your documentation>
         */
        const_reference operator [] (size_type i) const {
            // <your code>
            // you must call the non-const operator[]()
            // dummy is just to be able to compile the skeleton, remove it
            static value_type dummy;
            return dummy;}

        // -----------
        // operator +=
        // -----------

        /**
         * <your documentation>
         */
        Matrix& operator += (const T& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator +=
        // -----------

        /**
         * <your documentation>
         */
        Matrix& operator += (const Matrix& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator -=
        // -----------

        /**
         * <your documentation>
         */
        Matrix& operator -= (const T& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator -=
        // -----------

        /**
         * <your documentation>
         */
        Matrix& operator -= (const Matrix& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator *=
        // -----------

        /**
         * <your documentation>
         */
        Matrix& operator *= (const T& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator /=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs == 0)
         */
        Matrix& operator /= (const T& rhs) {
            // <your code>
            return *this;}

        // -----------
        // operator %=
        // -----------

        /**
         * <your documentation>
         * @throws invalid_argument if (rhs <= 0)
         */
        Matrix& operator %= (const T& rhs) {
            // <your code>
            return *this;}

        // -----
        // apply
        // -----

        /**
         * apply a function or function object to each element
         * <your documentation>
         */
        template <typename UF>
        Matrix& apply (UF f) {
            // <your code>
            return *this;}

        // --
        // at
        // --

        /**
         * <your documentation>
         */
        reference at (size_type i) {
            // <your code>
            // dummy is just to be able to compile the skeleton, remove it
            static value_type dummy;
            return dummy;}

        /**
         * <your documentation>
         */
        const_reference at (size_type i) const {
            // <your code>
            // you must call the non-const at()
            // dummy is just to be able to compile the skeleton, remove it
            static value_type dummy;
            return dummy;}

        // -----
        // begin
        // -----

        /**
         * <your documentation>
         */
        iterator begin () {
            // <your code>
            return 0;}

        /**
         * <your documentation>
         */
        const_iterator begin () const {
            // <your code>
            // you must call the non-const begin()
            return 0;}

        // ---
        // end
        // ---

        /**
         * <your documentation>
         */
        iterator end () {
            // <your code>
            return 0;}

        /**
         * <your documentation>
         */
        const_iterator end () const {
            // <your code>
            // you must call the non-const end()
            return 0;}

        // ----
        // size
        // ----

        /**
         * <your documentation>
         */
        size_type size () const {
            // <your code>
            return 0;}};

// -----
// apply
// -----

/**
 * apply a function or function object to each element
 * <your documentation>
 */
template <typename T, std::size_t R, std::size_t C, typename A, typename UF>
Matrix<T, R, C> apply (Matrix<T, R, C, A> x, UF f) {
    return x.apply(f);}

} // My

#endif // Matrix_h
