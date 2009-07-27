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

   namespace func {
	static int value = 0;
	int f(int x) {
		value++;
		return value;
	}
}
// ---------
// TestMatrix
// ---------

struct TestMatrix : CppUnit::TestFixture {
    // -----
    // tests
    // -----
    #if 0
    void test_matrix_defConstrV(){
    My::Array <int, 4> b(4);
     My::Matrix<int, 3, 4> a(b);
     CPPUNIT_ASSERT(a[0][0] == 4);
     CPPUNIT_ASSERT(a[2][3] == 4);
    }
    #endif
    void test_Matrix_default_constructor() {
		using namespace My;
		Matrix<int,5,8> a;
		Matrix<double,5,8> b;
	}
	void test_Matrix_default_constructor2() {
		using namespace My;
		Matrix<int,1,1> a;
		Matrix<double,1,1> b;
	}
	void test_Matrix_default_constructor3() {
		using namespace My;
		Matrix<int,100,100> a;
		Matrix<double,100,100> b;
	}

    void test_matrix_defConstrT(){
     My::Matrix<int, 3, 4> a(10) ;
     CPPUNIT_ASSERT(a[0][0] == 10);
     CPPUNIT_ASSERT(a[2][3] == 10);
    }
    void test_constructor1() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<int, rows, cols> m(5);
        CPPUNIT_ASSERT(m[0][0] == 5);
        CPPUNIT_ASSERT(m[0][2] == 5);
        CPPUNIT_ASSERT(m[1][0] == 5);
        CPPUNIT_ASSERT(m[1][2] == 5);
    }
    template<typename T>
    void test_subscript1() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<T, rows, cols> m(5);
        
        m[0][0] = 0;
        CPPUNIT_ASSERT(m[0][0] == 0);
        CPPUNIT_ASSERT(m[0][1] == 5);
        CPPUNIT_ASSERT(m[0][2] == 5);
        CPPUNIT_ASSERT(m[1][0] == 5);
        CPPUNIT_ASSERT(m[1][1] == 5);
        CPPUNIT_ASSERT(m[1][2] == 5);
        m[1][1] = 3;
        CPPUNIT_ASSERT(m[0][0] == 0);
        CPPUNIT_ASSERT(m[0][1] == 5);
        CPPUNIT_ASSERT(m[0][2] == 5);
        CPPUNIT_ASSERT(m[1][0] == 5);
        CPPUNIT_ASSERT(m[1][1] == 3);
        CPPUNIT_ASSERT(m[1][2] == 5);
    }
     void test_const_subscript1() {
	const My::Matrix<int, 2, 3> n(6);
	const My::Matrix<int, 2, 3> m(6);
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 3; ++j) {
			CPPUNIT_ASSERT(n[i][j] == m[i][j]);
		}
	}
	const My::Array<int, 3> a = m[0];
    }
    void test_at(){
    My::Matrix<int, 2, 3> n(5);
    My::Matrix<int, 2, 3> m(5);
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 3; ++j) {
			CPPUNIT_ASSERT((n.at)(i)[j] == (m.at(i))[j]);
		}
	}
	try{ m.at(17); CPPUNIT_ASSERT(false); }
	catch(std::out_of_range e) { CPPUNIT_ASSERT(true);}
    }
    
    void test_const_at() {
	const My::Matrix<int, 2, 3> n(6);
	const My::Matrix<int, 2, 3> m(6);
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 3; ++j) {
			CPPUNIT_ASSERT((n.at)(i)[j] == (m.at(i))[j]);
		}
	}
	try{ m.at(17); CPPUNIT_ASSERT(false); }
	catch(std:: out_of_range e) { CPPUNIT_ASSERT(true);}
    }
    
     template <typename T>
    void test_plus_equal() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<T, rows, cols> m(5);
        m[0][2] = 0;
        m += 2;
        CPPUNIT_ASSERT(m[0][0] == 7);
        CPPUNIT_ASSERT(m[0][2] == 2);
        CPPUNIT_ASSERT(m[1][0] == 7);
        CPPUNIT_ASSERT(m[1][2] == 7);
    }
    template <typename T>
    void test_plus_equal_matrix() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<T, rows, cols> m(0);
        My::Matrix<T, rows, cols> n(0);
        m[0][0] = 1;
        m[0][1] = 2;
        m[0][2] = 3;
        m[1][0] = 4;
        m[1][1] = 5;
        m[1][2] = 6;
        n[0][0] = 6;
        n[0][1] = 5;
        n[0][2] = 4;
        n[1][0] = 3;
        n[1][1] = 2;
        n[1][2] = 1;
        m += n;
        CPPUNIT_ASSERT(m[0][0] == 7);
        CPPUNIT_ASSERT(m[0][1] == 7);
        CPPUNIT_ASSERT(m[0][2] == 7);
        CPPUNIT_ASSERT(m[1][0] == 7);
        CPPUNIT_ASSERT(m[1][1] == 7);
        CPPUNIT_ASSERT(m[1][2] == 7);
        CPPUNIT_ASSERT(n[0][0] == 6);
        CPPUNIT_ASSERT(n[1][2] == 1);
    }
     template <typename T>
    void test_minus_equal() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<T, rows, cols> m(5);
        m[0][0] = 2;
        m -= 2;
        CPPUNIT_ASSERT(m[0][0] == 0);
        CPPUNIT_ASSERT(m[0][2] == 3);
        CPPUNIT_ASSERT(m[1][0] == 3);
        CPPUNIT_ASSERT(m[1][2] == 3);
    }


    template <typename T>
    void test_minus_equal_matrix() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<T, rows, cols> m(5);
        My::Matrix<T, rows, cols> n(2);
        m -= n;
        CPPUNIT_ASSERT(m[0][0] == 3);
        CPPUNIT_ASSERT(m[0][2] == 3);
        CPPUNIT_ASSERT(m[1][0] == 3);
        CPPUNIT_ASSERT(m[1][2] == 3);
        CPPUNIT_ASSERT(n[0][0] == 2);
        CPPUNIT_ASSERT(n[1][2] == 2);
    }
     template <typename T>
    void test_multiply_equal() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<T, rows, cols> m(5);
        m[0][0] = 0;
        m[0][1] = 1;
        m *= 2;
        CPPUNIT_ASSERT(m[0][0] == 0);
        CPPUNIT_ASSERT(m[0][1] == 2);
        CPPUNIT_ASSERT(m[1][0] == 10);
        CPPUNIT_ASSERT(m[1][2] == 10);
    }
      template <typename T>
    void test_divide_equal() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<int, rows, cols> m(5);
        m[0][0] = 1;
        m[0][1] = 6;
        m /= 2;
        CPPUNIT_ASSERT(m[0][0] == 0);
        CPPUNIT_ASSERT(m[0][1] == 3);
        CPPUNIT_ASSERT(m[1][0] == 2);
        CPPUNIT_ASSERT(m[1][2] == 2);
    }
    template <typename T>
     void test_modulo_equal() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<int, rows, cols> m(5);
        m[0][0] = 1;
        m[0][1] = 6;
        m %= 3;
        CPPUNIT_ASSERT(m[0][0] == 1);
        CPPUNIT_ASSERT(m[0][1] == 0);
        CPPUNIT_ASSERT(m[1][0] == 2);
        CPPUNIT_ASSERT(m[1][2] == 2);
    }
    void test_size() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<int, rows, cols> m(5);
        CPPUNIT_ASSERT(m.size() == rows * cols);
    }
    void test_rows() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<int, rows, cols> m(5);
        CPPUNIT_ASSERT(m.rows() == rows);
    }
    void test_cols() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<int, rows, cols> m(5);
        CPPUNIT_ASSERT(m.cols() == cols);
    }
    void test_begin() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<int, rows, cols> m(5);
        m[0][0] = 1;
        m[1][0] = 2;

        My::Matrix<int, rows, cols>::iterator it = m.begin();
        CPPUNIT_ASSERT((*it)[0] == 1);
        ++it;
        CPPUNIT_ASSERT((*it)[0] == 2);
    }
    void test_end() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<int, rows, cols> m(5);
        m[0][0] = 1;
        m[1][0] = 2;

        My::Matrix<int, rows, cols>::iterator it = m.end();
        --it;
        CPPUNIT_ASSERT((*it)[0] == 2);
        --it;
        CPPUNIT_ASSERT((*it)[0] == 1);
    }
     void test_const_begin(){
	const My::Matrix<int, 2, 3> m(5);
  	My::Matrix<int, 2, 3>::const_iterator it;
	const My::Array<int, 3> n(5);
	it = m.begin();
	CPPUNIT_ASSERT(*it == n);
	++it;
	CPPUNIT_ASSERT(*it == n);
    }

    void test_const_end(){
	const My::Matrix<int, 2, 3> m(5);
  	My::Matrix<int, 2, 3>::const_iterator it;
	const My::Array<int, 3> n(5);
	it = m.end();
	--it;
	CPPUNIT_ASSERT(*it == n);
	--it;
	CPPUNIT_ASSERT(*it == n);
    }
    void test_equal() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        const My::Matrix<int, rows, cols> m(5);
        const My::Matrix<int, rows, cols> n(5);
        CPPUNIT_ASSERT(m == n);
    }
    void test_less_than() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        const My::Matrix<int, rows, cols> m(5);
        const My::Matrix<int, rows, cols> n(3);
        CPPUNIT_ASSERT(n < m);
    }
 
    void test_Matrix_apply() {
        using namespace My;

	func::value = 0;
        Matrix<int,5,8> a(0);
        Matrix<int,5,8> b(0);
	CPPUNIT_ASSERT(a == b);
	a = apply(a, &func::f);
	func::value = 0;
	b.apply(&func::f);

	CPPUNIT_ASSERT(a == b);
      }
      void test_friend_plus() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<int, rows, cols> m(5);
        const My::Matrix<int, rows, cols> n(3);
        My::Matrix<int, rows, cols> z(8);
        CPPUNIT_ASSERT((m + n) == z); 
    }
    void test_friend_minus() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<int, rows, cols> m(5);
        My::Matrix<int, rows, cols> z(3);
        CPPUNIT_ASSERT((m - 2) == z);        
    }
     void test_friend_minus1() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<int, rows, cols> m(5);
        My::Matrix<int, rows, cols> z(7);
        CPPUNIT_ASSERT((m - (-2)) == z);        
    }
    void test_friend_plus1() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<int, rows, cols> m(5);
        My::Matrix<int, rows, cols> z(3);
        CPPUNIT_ASSERT((z + 2) == m);        
    }
    void test_friend_mult() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<int, rows, cols> m(6);
        My::Matrix<int, rows, cols> z(3);
        CPPUNIT_ASSERT((z * 2) == m);        
    }
 
    void test_friend_div() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<int, rows, cols> m(6);
        My::Matrix<int, rows, cols> z(3);
        CPPUNIT_ASSERT((m / 2) == z);        
    }

    void test_friend_mod() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<int, rows, cols> m(6);
        My::Matrix<int, rows, cols> z(0);
        CPPUNIT_ASSERT((m % 2) == z);        
    }
    void test_apply() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<int, rows, cols> m(6);
        My::Matrix<int, rows, cols> z(3);
	m.apply(std::bind2nd(std::plus<int>(),(-3)));
        CPPUNIT_ASSERT(m == z);        
    }

    void test_apply_template() {
        const unsigned int rows = 2;
        const unsigned int cols = 3;
        My::Matrix<int, rows, cols> m(6);
        My::Matrix<int, rows, cols> z(3);
        CPPUNIT_ASSERT((My::apply(m, std::bind2nd(std::plus<int>(), (-3))) == z));
    }
    void test_Matrix_value_constructor() {
		using namespace My;
		Matrix<int,5,8> a(4);
		Matrix<double,5,8> b(4.0);
	}
	void test_Matrix_value_constructor1() {
		using namespace My;
		Matrix<int,1,1> a(4);
		Matrix<double,1,1> b(4.0);
	}
	void test_Matrix_value_constructor2() {
		using namespace My;
		Matrix<int,100,100> a(4);
		Matrix<double,100,100> b(4.0);
	}
    void test_Matrix_copy_constructor() {
		using namespace My;
		Matrix<int,5,8> a(0);
		Matrix<int,5,8> b(a);
		CPPUNIT_ASSERT(a == b);
	}
	void test_Matrix_copy_constructor1() {
		using namespace My;
		Matrix<double,5,8> c(0);
		Matrix<double,5,8> d(c);
		CPPUNIT_ASSERT(c == d);
	}
	void test_Matrix_copy_assignment() {
		using namespace My;
		Matrix<int,5,8> a(0);
		Matrix<int,5,8> b(3);
		a = b;
		CPPUNIT_ASSERT(a == b);
	}
	void test_Matrix_copy_assignment1() {
		using namespace My;
		Matrix<double,5,8> c(0);
		Matrix<double,5,8> d(7);
		c = d;
		CPPUNIT_ASSERT(c == d);
	}
	void test_Matrix_iterators() {
		using namespace My;
		func::value = 0;
		Matrix<int,5,8> a;
		Matrix<int,5,8> b;
		a = apply(a, &func::f);
		b.apply(&func::f);
		const Matrix<int,5,8> c(b);

		CPPUNIT_ASSERT(*c.begin() == *b.begin());
		CPPUNIT_ASSERT(c.begin() != b.begin());
		CPPUNIT_ASSERT(*(b.end()-1) == *(c.end()-1));
		Matrix<int,5,8>::iterator it = b.begin();
		CPPUNIT_ASSERT(++++++++++it == b.end());
	}
	void test_Matrix_comparators() {
		using namespace My;
		func::value = 0;
		Matrix<int,5,8> a;
		Matrix<int,5,8> b;
		a = apply(a, &func::f);
		func::value = 1;
		b.apply(&func::f);
		const Matrix<int,5,8> c(b);

		CPPUNIT_ASSERT(b == c);
		CPPUNIT_ASSERT(c == b);
		CPPUNIT_ASSERT(a < b);
		CPPUNIT_ASSERT(a < c);
		CPPUNIT_ASSERT(b > a);
		CPPUNIT_ASSERT(c > a);
		CPPUNIT_ASSERT(b <= c && b >= c);
		CPPUNIT_ASSERT(a != b);
		CPPUNIT_ASSERT(a != c);
		CPPUNIT_ASSERT(a <= a && b >= b);
	}
    // -----
    // suite
    // -----
    CPPUNIT_TEST_SUITE(TestMatrix);

    //CPPUNIT_TEST(test_matrix_defConstrV);
    CPPUNIT_TEST(test_matrix_defConstrT);
    CPPUNIT_TEST(test_Matrix_default_constructor);
    CPPUNIT_TEST(test_Matrix_default_constructor2);
    CPPUNIT_TEST(test_Matrix_default_constructor3);
    CPPUNIT_TEST(test_constructor1);
    CPPUNIT_TEST(test_subscript1<int>);
    CPPUNIT_TEST(test_const_subscript1);
    CPPUNIT_TEST(test_at);
    CPPUNIT_TEST(test_const_at);
    CPPUNIT_TEST(test_plus_equal<int>);
    CPPUNIT_TEST(test_plus_equal_matrix<int>);
    CPPUNIT_TEST(test_minus_equal<int>);
    CPPUNIT_TEST(test_minus_equal_matrix<int>);
    CPPUNIT_TEST(test_multiply_equal<int>);
    CPPUNIT_TEST(test_divide_equal<int>);
    CPPUNIT_TEST(test_modulo_equal<int>);
    CPPUNIT_TEST(test_size);
    CPPUNIT_TEST(test_rows);
    CPPUNIT_TEST(test_cols);
    CPPUNIT_TEST(test_begin);
    CPPUNIT_TEST(test_end);
    CPPUNIT_TEST(test_const_begin);
    CPPUNIT_TEST(test_const_end);
    CPPUNIT_TEST(test_equal);
    CPPUNIT_TEST(test_less_than);
    CPPUNIT_TEST(test_Matrix_apply);
    CPPUNIT_TEST(test_friend_plus);
    CPPUNIT_TEST(test_friend_minus);
    CPPUNIT_TEST(test_friend_minus1);
    CPPUNIT_TEST(test_friend_plus1);
    CPPUNIT_TEST(test_friend_mult);
    CPPUNIT_TEST(test_friend_div);
    CPPUNIT_TEST(test_friend_mod);
    CPPUNIT_TEST(test_apply);
    CPPUNIT_TEST(test_apply_template);
    CPPUNIT_TEST(test_Matrix_value_constructor);
    CPPUNIT_TEST(test_Matrix_value_constructor1);
    CPPUNIT_TEST(test_Matrix_value_constructor2);
    CPPUNIT_TEST(test_Matrix_copy_constructor);
    CPPUNIT_TEST(test_Matrix_copy_constructor1);
    CPPUNIT_TEST(test_Matrix_copy_assignment);
    CPPUNIT_TEST(test_Matrix_copy_assignment1);
    CPPUNIT_TEST(test_Matrix_iterators);
    CPPUNIT_TEST(test_Matrix_comparators);
    


    CPPUNIT_TEST_SUITE_END();};

#endif // TestMatrix_h
