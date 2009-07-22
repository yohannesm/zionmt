// ------------------------------
// projects/c++/array/TestArray.h
// Copyright (C) 2009
// Glenn P. Downing
// ------------------------------

#ifndef TestArray_h
#define TestArray_h

// --------
// includes
// --------

#include <algorithm> // equal
#include <stdexcept> // out_of_range
#include <iostream> // cout
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE

#include "Array.h"

// ---------
// TestArray
// ---------

struct TestArray : CppUnit::TestFixture {
    // -----
    // tests
    // -----
     
    // -----
    // tests constructor
    // -----
    void test_constructor0(){
    My::Array<int, 10> x(5);
    CPPUNIT_ASSERT(std::count(&x[0], &x[5], 5));
    }
    void test_constructor1(){
    My::Array<int, 10> x(2);
    CPPUNIT_ASSERT(std::count(&x[0], &x[9], 2));
    }
    void test_constructorSeq1() {
	int a[] = { 1, 2, 3, 4, 5 };
	My::Array<int, 5> x(a, a+5);
	CPPUNIT_ASSERT(std::equal(a, a+5, x.begin()));
		}
    void test_constructorSeq2() {
	int a[] = { 5, 4, 3, 2, 1 };
	My::Array<int, 5> x(a, a+5);
	CPPUNIT_ASSERT(std::equal(a, a+5, x.begin()));
		}
    void test_size1() {
    My::Array<int, 21> x(0);
    CPPUNIT_ASSERT(x.size() == 21);
		}
    void test_size2() {
    My::Array<int, 1> x(1);
    CPPUNIT_ASSERT(x.size() == 1);
		}
    void test_equal1() {
		int a[] = { 1, 2, 3, 4, 5 };
		int b[] = { 1, 2, 3, 4, 5 };
		My::Array<int, 5> x(a, a+5);
		My::Array<int, 5> y(b, b+5);
		My::Array<int, 5> z(a, a+4);
			
		CPPUNIT_ASSERT(x == y);
		CPPUNIT_ASSERT(y == x);
    }
    void test_equal2() {
		My::Array<int, 5> x(2);
		My::Array<int, 5> y(2);
			
		CPPUNIT_ASSERT(x == y);
		CPPUNIT_ASSERT(y == x);
    }
    void test_not_equal(){
    		int a[] = { 1, 2, 3, 4, 5 };
		int b[] = { 1, 2, 3, 4, 5 };
		My::Array<int, 5> x(a, a+5);
		My::Array<int, 5> y(b, b+5);
		My::Array<int, 5> z(a, a+4);
    			CPPUNIT_ASSERT(y != z);
			CPPUNIT_ASSERT(z != x);
			CPPUNIT_ASSERT(z != y);
			CPPUNIT_ASSERT(x != z);
    }
    void test_LTE_GTE(){
    		int a[] = { 1, 2, 3, 4, 5 };
		int b[] = { 1, 2, 3, 4, 5 };
		My::Array<int, 5> x(a, a+5);
		My::Array<int, 5> y(b, b+5);
		My::Array<int, 5> z(a, a+4);
    			CPPUNIT_ASSERT(x <= y);
			CPPUNIT_ASSERT(y <= x);
			CPPUNIT_ASSERT(x >= y);
			CPPUNIT_ASSERT(y >= x);
			CPPUNIT_ASSERT(y <= x);
			CPPUNIT_ASSERT(x <= y);
    }
    void test_LT_GT() {
			int a[] = { 1, 2, 3, 4, 5 };
			My::Array<int, 5> x(a, a+5);
			My::Array<int, 5> y(a, a+5);

			My::Array<int, 5> z(a, a+4);
			My::Array<int, 5> o(a+1, a+5);
			CPPUNIT_ASSERT(!(x < y));
			CPPUNIT_ASSERT(!(y < x));
			CPPUNIT_ASSERT(z < x);
			CPPUNIT_ASSERT(!(x < z));
			CPPUNIT_ASSERT(x < o);
			CPPUNIT_ASSERT(!(o < x));
			CPPUNIT_ASSERT(x <= o);
			CPPUNIT_ASSERT(!(o <= x));
			CPPUNIT_ASSERT(o > x);
			CPPUNIT_ASSERT(!(x > o));
			CPPUNIT_ASSERT(o >= x);
			CPPUNIT_ASSERT(!(x >= o));
     }
     void test_sub2() {
			int a[] = { 1, 2, 3, 4, 5};
			My::Array<int, 5> x(a, a+5);
			for(int i=0; i < 5; ++i){
				x[i] = 5-i;
				a[i] = 5-i;
			}
			CPPUNIT_ASSERT(std::equal(a,a+5,x.begin()));
     }
     void test_sub_const() {
			int a[] = { 1, 2, 3, 4, 5 };
			int i;
			const int* ci;
			const My::Array<int, 5> x(a, a+5);
			for (int j = 0; j < 5; ++j) {
				i = x[j];
				CPPUNIT_ASSERT(i == a[j]);
				ci = &x[j];
				CPPUNIT_ASSERT(*ci == a[j]);
			}
			const My::Array<int, 5> y(a, a+5);
			CPPUNIT_ASSERT(x == y);
		}
     void test_at() {
			int a[] = { 1, 2, 3, 4, 5 };
			int i;
			const int* ci;
			My::Array<int, 5> x(a, a+5);
			try {
				for(int j = 0; j < 5; ++j) {
					i = x.at(j);
					CPPUNIT_ASSERT(i == a[j]);
					ci = &x.at(j);
					CPPUNIT_ASSERT(*ci == a[j]);
				}
			}
			catch(std::out_of_range e) {
				CPPUNIT_ASSERT(false);
			}
			try {
				i = x.at(6);
				CPPUNIT_ASSERT(false);
			}
			catch(std::out_of_range e) {CPPUNIT_ASSERT(!std::strcmp(e.what(),"My::Array.at(i) >= size"));}
			try {
				ci = &x.at(-1);
				CPPUNIT_ASSERT(false);
			}
			catch(std::out_of_range e) {CPPUNIT_ASSERT(!std::strcmp(e.what(),"My::Array.at(i) >= size"));}
     }
     void test_at1() {
			int a[] = { 1, 2, 3, 4, 5};
			My::Array<int, 5> x(a, a+5);
			for(int i=0; i < 5; ++i){
				x.at(i) = 5-i;
				a[i]    = 5-i;
			}
			CPPUNIT_ASSERT(std::equal(a,a+5,x.begin()));

			try{
				x.at(6) = 6;
				CPPUNIT_ASSERT(false);
			}
			catch(const std::out_of_range& e) {CPPUNIT_ASSERT(!std::strcmp(e.what(),"My::Array.at(i) >= size"));}
			try{
				x.at(-1) = 4;
				CPPUNIT_ASSERT(false);
			}
			catch(const std::out_of_range& e) {CPPUNIT_ASSERT(!std::strcmp(e.what(),"My::Array.at(i) >= size"));}
		}
     void test_at_const() {
			int a[] = { 1, 2, 3, 4, 5 };
			int i;
			const int* ci;
			const My::Array<int, 5> x(a, a+5);
			try {
				for(int j = 0; j < 5; ++j) {
					i = x.at(j);
					CPPUNIT_ASSERT(i == a[j]);
					ci = &x.at(j);
					CPPUNIT_ASSERT(*ci == a[j]);
				}
			}
			catch(std::out_of_range e) {
				CPPUNIT_ASSERT(false);
			}
			try {
				i = x.at(6);
				CPPUNIT_ASSERT(false);
			}
			catch(std::out_of_range e) {}
			try {
				ci = &x.at(-1);
				CPPUNIT_ASSERT(false);
			}
			catch(std::out_of_range e) {}
	}
	template<typename II, typename II2> 
		bool iteratorHelper(II b, const II e, II2 x) {
			while (b != e) {
				if (*b != *x)
					return false;
				++b;
				++x;
			}
			return true;
		}
		void test_iterators() {
			int a[] = { 1, 2, 3, 4, 5 };
			My::Array<int,5> x(a, a+5);
			CPPUNIT_ASSERT(iteratorHelper(x.begin(), x.end(), a));
		}
		void test_iterators1() {
			int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1 };
			My::Array<int,5> x(a, a+9);
			CPPUNIT_ASSERT(iteratorHelper(x.begin(), x.end(), a));

	}
	void test_assignment(){
			int a[] = { 1, 2, 3, 4, 5 };
			int b[] = { 2, 2, 2, 2, 2 };
			My::Array<int, 5> x(a, a+5);
			My::Array<int, 5> y(b, b+5);
			My::Array<int, 5> z(b, b+5);
			CPPUNIT_ASSERT(x != y);
			y = x;
			CPPUNIT_ASSERT(x == y);
			x = z;
			y = z;
			CPPUNIT_ASSERT(x == y);
			CPPUNIT_ASSERT(x == z);
			CPPUNIT_ASSERT(y == z);
		}
		
		void test_copy(){
			int a[] = { 1, 2, 3, 4, 5 };
			
			My::Array<int, 5> x(a, a+5);
			My::Array<int, 5> y(x);
			CPPUNIT_ASSERT(x == y);
		}
	void test_copy1(){
			int a[] = { 5, 4, 3, 2, 1 };
			
			My::Array<int, 5> x(a, a+5);
			My::Array<int, 5> y(x);
			CPPUNIT_ASSERT(x == y);
		}

     // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestArray);
    
    CPPUNIT_TEST(test_constructor0);
    CPPUNIT_TEST(test_constructor1);
    CPPUNIT_TEST(test_constructorSeq1);
    CPPUNIT_TEST(test_constructorSeq2);
    CPPUNIT_TEST(test_size1);
    CPPUNIT_TEST(test_size2);
    CPPUNIT_TEST(test_equal1);
    CPPUNIT_TEST(test_equal2);
    CPPUNIT_TEST(test_not_equal);
    CPPUNIT_TEST(test_LTE_GTE);
    CPPUNIT_TEST(test_LT_GT);
    CPPUNIT_TEST(test_sub2);
    CPPUNIT_TEST(test_sub_const);
    CPPUNIT_TEST(test_at);
    CPPUNIT_TEST(test_at1);
    CPPUNIT_TEST(test_at_const);
    CPPUNIT_TEST(test_iterators);
    CPPUNIT_TEST(test_iterators1);
    CPPUNIT_TEST(test_assignment);
    CPPUNIT_TEST(test_copy);
    CPPUNIT_TEST(test_copy1);
    
    CPPUNIT_TEST_SUITE_END();};

#endif // TestArray_h
 
