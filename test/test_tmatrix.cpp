#include "tmatrix.h"
#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}
TEST(TDynamicMatrix, cam_create_matrix_with_std_vector)//тест для проверки конструктора преобразования из std::vector<vector<T>> в TDynamicMatrix<T>
{
    std::vector<vector<int>> a = { {1,2,3},{4,5,6},{7,8,9} };
    TDynamicMatrix<int> m1(a);
    std::cout << m1 << std::endl;
}
//TEST(TDynamicMatrix, operator_cin)//тест для проверки ввода/вывода
//{
//    TDynamicMatrix<int> m(2);
//    std::cin >> m;
//    std::cout << std::endl;
//    std::cout << m << std::endl;
//}
TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
    std::vector<vector<int>> a = { {1,2,3},{4,5,6},{7,8,9} };
    TDynamicMatrix<int> m1(a);

    TDynamicMatrix<int> m2 = m1;

    EXPECT_EQ(m1, m2);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
    std::vector<vector<int>> a = { {1,2},{3,4} };
    TDynamicMatrix<int> m(a);

    TDynamicMatrix<int> m2 = m;
    m[0][0] = 100; 

    EXPECT_NE(m, m2);  
}

TEST(TDynamicMatrix, can_get_size)
{
    TDynamicMatrix<int> m(4);

    EXPECT_EQ(m.size(), 4);
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
  TDynamicMatrix<int> m(3);

  m[0][0] = 100;
  
  EXPECT_EQ(m[0][0], 100);
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
    TDynamicMatrix<int> m(3);

    ASSERT_ANY_THROW(m.at(-1)[1] = 100);
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
    TDynamicMatrix<int> m(3);

    ASSERT_ANY_THROW(m.at(4)[1] = 100);
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
    TDynamicMatrix<int> m(3);
    m[0][0] = 100;
    m = m;  
    EXPECT_EQ(m[0][0], 100); 
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
    TDynamicMatrix<int> m1(3);
    TDynamicMatrix<int> m2(3);

    m1[0][0] = 100;
    m2 = m1;

    EXPECT_EQ(m1,m2);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
    TDynamicMatrix<int> m1(3);
    TDynamicMatrix<int> m2(4);

    m2 = m1;  
    EXPECT_EQ(m2.size(), 3);  
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
    TDynamicMatrix<int> m1(3);
    TDynamicMatrix<int> m2(4);

    m2 = m1;

    EXPECT_EQ(m2,m1);  
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
    TDynamicMatrix<int> m1(3);
    TDynamicMatrix<int> m2 = m1;

    EXPECT_TRUE(m1 == m2);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
    TDynamicMatrix<int> m(3);

    EXPECT_TRUE(m == m);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
    TDynamicMatrix<int> m1(3);
    TDynamicMatrix<int> m2(4);

    EXPECT_TRUE(m1 != m2);
}
TEST(TDynamicMatrix, can_mult_matrix_and_scalar)//тест на умножение матрицы на скаляр
{
    std::vector<vector<int>> a = { {1,2},{3,4} };
    TDynamicMatrix<int> m(a);

    TDynamicMatrix<int> m2;
    m2 = m *4;
    std::vector<vector<int>> b = { {4,8},{12,16} };
    TDynamicMatrix<int> m3(b);

    EXPECT_EQ(m3, m2);
}
TEST(TDynamicMatrix, can_mult_matrix_and_vector)//тест на умножение матрицы на вектор
{
    std::vector<vector<int>> a = { {1,2,3},{4,5,6},{7,8,9} };
    TDynamicMatrix<int> m1(a);
    std::vector<int> b= { 1,2,3 };
    TDynamicVector<int> v1(b);

    TDynamicVector<int> v2;
    v2 = m1 * v1;
    std::vector<int> c = { 14,32,50 };
    TDynamicVector<int> v3(c);

    EXPECT_EQ(v3, v2);
}
TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
    TDynamicMatrix<int> m1(3);
    TDynamicMatrix<int> m2(3);
    TDynamicMatrix<int> m(3);

    m1[0][0] = 100;
    m2[0][0] = 200;
    m[0][0] = 300;

    EXPECT_EQ(m1 + m2, m);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
    TDynamicMatrix<int> m1(3);
    TDynamicMatrix<int> m2(4);

    ASSERT_ANY_THROW(m1 + m2);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
    TDynamicMatrix<int> m1(3);
    TDynamicMatrix<int> m2(3);
    TDynamicMatrix<int> m(3);

    m1[0][0] = 300;
    m2[0][0] = 100;
    m[0][0] = 200;

    EXPECT_EQ(m1 - m2, m);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TDynamicMatrix<int> m1(3);
    TDynamicMatrix<int> m2(4);

    ASSERT_ANY_THROW(m1 - m2);
}
TEST(TDynamicMatrix, can_mult_matrix)//тест на умножение матриц
{
    std::vector<vector<int>> a = { {3,5},{2,1} };
    std::vector<vector<int>> b = { {8,2,3},{1,7,2} };
    TDynamicMatrix<int> m1(a);
    TDynamicMatrix<int> m2(b);

    TDynamicMatrix<int> m = m1 * m2;
    std::vector<vector<int>> c = { {29,41,19},{17,11,8} };
    TDynamicMatrix<int> m3(c);

    EXPECT_EQ(m,m3);
}
TEST(TDynamicMatrix, cant_mult_matrix_with_diff_size)//тест на исключение при умножении матриц
{
    std::vector<vector<int>> a = { {3,5,5},{2,1,8} };
    std::vector<vector<int>> b = { {8,2,3},{1,7,2} };
    TDynamicMatrix<int> m1(a);
    TDynamicMatrix<int> m2(b);

    ASSERT_ANY_THROW(m1*m2);
}

