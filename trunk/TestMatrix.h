// --------------------------------
// projects/c++/matrix/TestMatrix.h
// Copyright (C) 2009
// Glenn P. Downing
// --------------------------------

#ifndef TestMatrix_h
#define TestMatrix_h

// --------
// includes
// --------

#include <algorithm> // equal
#include <stdexcept> // out_of_range

#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE

#include "Matrix.h"

// ---------
// TestMatrix
// ---------

struct TestMatrix : CppUnit::TestFixture {
    // -----
    // tests
    // -----
    void test_matrix_defConstrV(){
    My::Array <int, 4> b(4);
     My::Matrix<int, 3, 4> a(b);
    }
    void test_matrix_defConstrT(){
     My::Matrix<int, 3, 4> a(10);
     }
    // -----
    // suite
    // -----
    CPPUNIT_TEST_SUITE(TestMatrix);

    CPPUNIT_TEST(test_matrix_defConstrV);
    CPPUNIT_TEST(test_matrix_defConstrT);

    CPPUNIT_TEST_SUITE_END();};

#endif // TestMatrix_h
