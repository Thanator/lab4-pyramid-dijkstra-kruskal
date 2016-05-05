// unit_test.cpp: определяет точку входа для консольного приложения.
//


#include <gtest.h>



int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

}
