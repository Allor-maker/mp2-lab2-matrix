#include "tmatrix.h"
#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, can_create_vector_with_std_vector)//добавил тест для конструктора из std::vector<T> в TDynamicVector<T>
{
    std::vector<int> a = { 1,2,3 };

    TDynamicVector<int> b(a);

    std::cout << b << std::endl;
}
//TEST(TDynamicVector, operator_cin)//тест для проверки ввода/вывода
//{
//    TDynamicVector<int> v(2);
//    std::cin >> v;
//    std::cout << std::endl;
//    std::cout << v << std::endl;
//}
TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
    std::vector<int> a = { 1,2,3 };
    TDynamicVector<int> vec1(a);

    TDynamicVector<int> vec2(vec1);

    EXPECT_EQ(vec1, vec2);
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
    std::vector<int> a = { 1,2,3 };
    TDynamicVector<int> v(a);
    TDynamicVector<int> v2(v);
    TDynamicVector<int> v3(a); 

    v2[0] = 0;
    std::vector<int> a2 = { 0,2,3 };
    TDynamicVector<int> v4(a2);
   
    EXPECT_NE(v[0], v2[0]);
    EXPECT_EQ(v,v3);  
    EXPECT_EQ(v2,v4); 
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

TEST(TDynamicVector, can_set_and_get_element)
{
  TDynamicVector<int> v(3);
  v[0] = 2338;

  EXPECT_EQ(2338, v[0]);
}

TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
    TDynamicVector<int> v(3);

    ASSERT_ANY_THROW(v.at(-1) = 1);
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
    TDynamicVector<int> v(3);

    ASSERT_ANY_THROW(v.at(4) = 1);
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
    TDynamicVector<int> v(3);

    v[0] = 1;
    v = v;  

    EXPECT_EQ(v[0], 1);
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
    TDynamicVector<int> v1(3);
    TDynamicVector<int> v2(3);

    v1[0] = 1;
    v2 = v1;

    EXPECT_EQ(v2,v1);
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
    TDynamicVector<int> v1(3);
    TDynamicVector<int> v2(4);

    v2 = v1;  

    EXPECT_EQ(v2.size(), 3);
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
    TDynamicVector<int> v1(3);
    TDynamicVector<int> v2(4);

    v1[0] = 1;
    v2 = v1;   

    EXPECT_EQ(v2,v1);
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
    TDynamicVector<int> vec1(3);
    TDynamicVector<int> vec2(3);

    vec1[0] = 1;
    vec2 = vec1;

    EXPECT_TRUE(vec1 == vec2);
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
    TDynamicVector<int> v(3);

    EXPECT_TRUE(v == v);
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
    TDynamicVector<int> v1(3);
    TDynamicVector<int> v2(4);

    EXPECT_FALSE(v1 == v2);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
    std::vector<int> a = { 1,2,3 };
    TDynamicVector<int> v(a);
    
    TDynamicVector<int> r = v + 2;
    std::vector<int> b = { 3,4,5 };
    TDynamicVector<int> v2(b);

    EXPECT_EQ(r,v2);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
    std::vector<int> a = { 3,4,5 };
    TDynamicVector<int> v(a);

    TDynamicVector<int> r = v - 2;
    std::vector<int> b = { 1,2,3 };
    TDynamicVector<int> v2(b);

    EXPECT_EQ(r,v2);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
    std::vector<int> a = { 1,2,3 };
    TDynamicVector<int> v(a);
    
    TDynamicVector<int> r = v * 2;
    std::vector<int> b = { 2,4,6 };
    TDynamicVector<int> v2(b);

    EXPECT_EQ(r, v2);
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
    std::vector<int> a1 = { 1,2,3 };
    std::vector<int> a2 = { 4,5,6 };
    TDynamicVector<int> v1(a1);
    TDynamicVector<int> v2(a2);

    TDynamicVector<int> r = v1 + v2;
    std::vector<int> b = { 5,7,9 };
    TDynamicVector<int> v3(b);

    EXPECT_EQ(r,v3);
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
    TDynamicVector<int> v1(3);
    TDynamicVector<int> v2(4);

    ASSERT_ANY_THROW(v1 + v2);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
    std::vector<int> a1 = { 1,2,3 };
    std::vector<int> a2 = { 4,5,6 };
    TDynamicVector<int> v1(a1);
    TDynamicVector<int> v2(a2);

    TDynamicVector<int> r = v2 - v1;
    std::vector<int> b = { 3,3,3 };
    TDynamicVector<int> v3(b);

    EXPECT_EQ(r,v3);
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
    TDynamicVector<int> v1(3);
    TDynamicVector<int> v2(4);

    ASSERT_ANY_THROW(v1 - v2);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
    std::vector<int> a1 = { 1,2,3 };
    std::vector<int> a2 = { 1,2,3 };
    TDynamicVector<int> v1(a1);
    TDynamicVector<int> v2(a2);

    int scalar_mul = v1 * v2;  

    EXPECT_EQ(scalar_mul, 14);  
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
    TDynamicVector<int> v1(3);
    TDynamicVector<int> v2(4);

    ASSERT_ANY_THROW(v1 * v2);
}


