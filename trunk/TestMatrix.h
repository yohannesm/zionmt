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

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestMatrix);
    CPPUNIT_TEST_SUITE_END();};

#endif // TestMatrix_h
