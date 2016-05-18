
#include <gtest.h>
#include <separatearray.h>


TEST(separate_array, can_create_separray)
{
	ASSERT_NO_THROW(separate_array A);
}

TEST(separate_array, can_create_separray_with_parameters)
{
	ASSERT_NO_THROW(separate_array A(2));
}

TEST(separate_array, cant_create_separray_with_incorect_parameters)
{
	ASSERT_ANY_THROW(separate_array A(-2));
}

TEST(separate_array, can_find_elem)
{
	separate_array A(2);
	EXPECT_EQ(A.find(0), 65);

}

TEST(separate_array, cant_find_elem_when_incorrect_parameters)
{
	separate_array A(2);
	ASSERT_ANY_THROW(A.find(-1));
}

TEST(separate_array, can_merge_elems)
{
	separate_array A(2);
	A.merge(0, 1);
	EXPECT_EQ(66, A.find(0));
}

TEST(separate_array, cant_merge_elems_when_parameters_incorrect)
{
	separate_array A(2);
	ASSERT_ANY_THROW(A.merge(-1, 1));
}

TEST(separate_array, can_setnumnu)
{
	separate_array A(2);
	A.setNN(0, 1);
	EXPECT_EQ(A.getNN(0), 1);
}

TEST(separate_array, can_getnum)
{
	separate_array A(2);
	A.setNN(0, 1);
	EXPECT_EQ(A.getNN(0), 1);
}

TEST(separate_array, cangetnumnodes)
{
	separate_array A(2);
	EXPECT_EQ(A.getNuN(), 2);
}
