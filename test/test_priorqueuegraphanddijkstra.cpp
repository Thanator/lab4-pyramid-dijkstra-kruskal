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
	EXPECT_EQ(A.getAE(0,1), B.getAE(0, 1));
}

//работа метода printgraph продемонстрирована в сэмпле
TEST(Graph, DijkstrasAlgorithm)
{
	Graph A(6, 15); // как пример, граф с википедии
	
	A.setAE(0, 1, 7); A.setAE(1, 0, 7);
	A.setAE(0, 2, 9); A.setAE(2, 0, 9);
	A.setAE(0, 3, -1); A.setAE(3, 0, -1);
	A.setAE(0, 4, -1); A.setAE(4, 0, -1);
	A.setAE(0, 5, 14); A.setAE(5, 0, 14);


	A.setAE(1, 2, 10); A.setAE(2, 1, 10);
	A.setAE(1, 3, 15); A.setAE(3, 1, 15);
	A.setAE(1, 4, -1); A.setAE(4, 1, -1);
	A.setAE(1, 5, -1); A.setAE(5, 1, -1);


	A.setAE(2, 3, 11); A.setAE(3, 2, 11);
	A.setAE(2, 4, -1); A.setAE(4, 2, -1);
	A.setAE(2, 5, 2); A.setAE(5, 2, 2);


	A.setAE(3, 4, 6); A.setAE(4, 3, 6);
	A.setAE(3, 5, -1); A.setAE(5, 3, -1);


	A.setAE(4, 5, 9); A.setAE(5, 4, 9);
	A.Dijkstra(0);
	A.printgraph();

}

TEST(Graph, can_getelem)
{
	Graph A(6, 15); // как пример, граф с википедии

	A.setAE(0, 1, 7); A.setAE(1, 0, 7);
	A.setAE(0, 2, 9); A.setAE(2, 0, 9);
	A.setAE(0, 3, -1); A.setAE(3, 0, -1);
	A.setAE(0, 4, -1); A.setAE(4, 0, -1);
	A.setAE(0, 5, 14); A.setAE(5, 0, 14);


	A.setAE(1, 2, 10); A.setAE(2, 1, 10);
	A.setAE(1, 3, 15); A.setAE(3, 1, 15);
	A.setAE(1, 4, -1); A.setAE(4, 1, -1);
	A.setAE(1, 5, -1); A.setAE(5, 1, -1);


	A.setAE(2, 3, 11); A.setAE(3, 2, 11);
	A.setAE(2, 4, -1); A.setAE(4, 2, -1);
	A.setAE(2, 5, 2); A.setAE(5, 2, 2);


	A.setAE(3, 4, 6); A.setAE(4, 3, 6);
	A.setAE(3, 5, -1); A.setAE(5, 3, -1);


	A.setAE(4, 5, 9); A.setAE(5, 4, 9);
	EXPECT_EQ(A.getAE(0, 1), 7);
}

TEST(Graph, can_getnumnodes)
{
	Graph A(4, 6);
	EXPECT_EQ(A.getNN(), 4);
}

TEST(Graph, can_getnumedges)
{
	Graph A(4, 6);
	EXPECT_EQ(A.getNE(), 6);
}

TEST(Graph, can_setnum)
{
	Graph A(4, 6);
	A.setAE(0, 1, 9);
	EXPECT_EQ(A.getAE(0, 1), 9);
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
	EXPECT_EQ(4, A.getElem(1));
}

TEST(prior_queue, can_drop_elem_from_pqueue) 
{
	prior_queue A;
	A.drop();
	A.insert(4);
	A.insert(-1);
	A.insert(6);
	A.drop();
	EXPECT_EQ(4, A.getElem(0));
}

TEST(prior_queue, can_change_key)
{
	prior_queue A;
	A.changeKey(0, 1337);
	EXPECT_EQ(1337, A.getElem(0));
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




