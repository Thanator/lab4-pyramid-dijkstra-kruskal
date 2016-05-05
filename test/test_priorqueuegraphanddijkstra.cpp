#include <gtest.h>
#include <GraphAndPriorityQueue.h>




TEST(Graph, can_create_graph)
{
	ASSERT_NO_THROW(Graph A);
} 

TEST(Graph, can_create_graph_with_user_parameters)
{
	ASSERT_NO_THROW(Graph A(4, 5));
}

TEST(Graph, exeption_when_parameters_incorrect)
{
	ASSERT_ANY_THROW(Graph A(-1, 6));
}

TEST(Graph, exeption_when_edgescounter_incorrect)
{
	ASSERT_ANY_THROW(Graph A(3, 4));
}

TEST(Graph, copy_constr_work)
{
	Graph A(4, 5);
	Graph B(A);
	EXPECT_EQ(A.adjmatrix[0][1], B.adjmatrix[0][1]);
}

//работа метода printgraph продемонстрирована в сэмпле
TEST(Graph, DijkstrasAlgorithm)
{
	Graph A(6, 15); // как пример, граф с википедии
	A.adjmatrix[0][1] = A.adjmatrix[1][0] = 7;
	A.adjmatrix[0][2] = A.adjmatrix[2][0] = 9;
	A.adjmatrix[0][3] = A.adjmatrix[3][0] = -1;
	A.adjmatrix[0][4] = A.adjmatrix[4][0] = -1;
	A.adjmatrix[0][5] = A.adjmatrix[5][0] = 14;

	A.adjmatrix[1][2] = A.adjmatrix[2][1] = 10;
	A.adjmatrix[1][3] = A.adjmatrix[3][1] = 15;
	A.adjmatrix[1][4] = A.adjmatrix[4][1] = -1;
	A.adjmatrix[1][5] = A.adjmatrix[5][1] = -1;

	A.adjmatrix[2][3] = A.adjmatrix[3][2] = 11;
	A.adjmatrix[2][4] = A.adjmatrix[4][2] = -1;
	A.adjmatrix[2][5] = A.adjmatrix[5][2] = 2;

	A.adjmatrix[3][4] = A.adjmatrix[4][3] = 6;
	A.adjmatrix[3][5] = A.adjmatrix[5][3] = -1;

	A.adjmatrix[4][5] = A.adjmatrix[5][4] = 9;
	A.Dijkstra(0);
	int k = 0;
	if (A.adjmatrix[0][0] == 0 && A.adjmatrix[1][1] == 7 && A.adjmatrix[2][2] == 9 && A.adjmatrix[3][3] == 20 && A.adjmatrix[4][4] == 20
		&& A.adjmatrix[5][5] == 11)
		k = 1;
	EXPECT_EQ(1, k);


	
}

TEST(prior_queue, can_create_prior_queue)
{
	ASSERT_NO_THROW(prior_queue A);
}

TEST(prior_queue, can_create_prior_queue_with_user_paramaters)
{
	ASSERT_NO_THROW(prior_queue A(5));
}

TEST(prior_queue, exeption_when_parameters_constr_incorrect)
{
	ASSERT_ANY_THROW(prior_queue A(-2));
}

TEST(prior_queue, can_insert_into_pqueue)
{
	prior_queue A;
	A.insert(4);
	A.insert(5);
	A.insert(9);
	EXPECT_EQ(4, A.keys[1]);
}

TEST(prior_queue, can_drop_elem_from_pqueue) 
{
	prior_queue A;
	A.drop();
	A.insert(4);
	A.insert(-1);
	A.insert(6);
	A.drop();
	EXPECT_EQ(4, A.keys[0]);
}

TEST(prior_queue, can_change_key)
{
	prior_queue A;
	A.changeKey(0, 1337);
	EXPECT_EQ(1337, A.keys[0]);
}

TEST(prior_queue, exeption_when_incorrect_pick_changge_elem)
{
	prior_queue A;
	ASSERT_ANY_THROW(A.changeKey(5, 999));
}

TEST(prior_queue, isEmpty_correct)
{
	prior_queue A;
	A.drop();
	EXPECT_TRUE(A.isEmpty());
}




