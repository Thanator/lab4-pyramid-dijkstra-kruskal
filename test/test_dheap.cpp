
#include <gtest.h>
#include <dheap.h>


TEST(DHeap, can_create_default_heap)
{
	ASSERT_NO_THROW(DHeap<int> a);
}

TEST(DHeap, can_copy_other_heap)
{
	DHeap<int> a;
	ASSERT_NO_THROW(DHeap<int> b(a));
}

TEST(DHeap, can_create_heap_with_good_options)
{
	ASSERT_NO_THROW(DHeap<int> a(2, 5));
}

TEST(DHeap, throw_when_wrong_size)
{
	ASSERT_ANY_THROW(DHeap<int> a(4, 0));
}

TEST(DHeap, throw_when_wrong_dimension)
{
	ASSERT_ANY_THROW(DHeap<int> a(0, 5));
}

TEST(DHeap, can_insert_node)
{
	DHeap<int> a;
	ASSERT_NO_THROW(a.insert(2));
	
}

TEST(DHeap, can_transposition)
{
	DHeap<int> a(3, 4);
	a.changeKey(1, 3);
	a.changeKey(3, 4);
	a.transposition(a.keys[3], a.keys[1]);
	ASSERT_EQ(a.keys[1], 4);
	

}

TEST(DHeap, can_pop_keys)
{
	DHeap<int> a(2, 3);
	a.changeKey(0, 1);
	a.changeKey(1, -1);
	a.pop(1);
	ASSERT_EQ(a.keys[0], -1);
}

TEST(DHeap, throw_when_wrong_pos_pop)
{
	DHeap<int> a(2, 3);
	ASSERT_ANY_THROW(a.pop(-1));
}

TEST(DHeap, can_search_minchild)
{
	DHeap<int> a(4, 5);
	a.changeKey(2, -4);
	a.changeKey(4, 5);
	int s = a.minchild(0);
	ASSERT_EQ(s, 2);
}

TEST(DHeap, throw_then_wrong_pos_minchild)
{
	DHeap<int> a(4, 5);
	ASSERT_ANY_THROW(a.minchild(-1));
}

TEST(DHeap, can_dip_keys)
{
	DHeap<int> a(2, 6);
	a.changeKey(0, 5);
	a.dip(0);
	ASSERT_EQ(a.keys[3], 5);
}

TEST(DHeap, throw_when_wrong_pos_dip)
{
	DHeap<int> a(2, 6);
	ASSERT_ANY_THROW(a.dip(6));
}

TEST(DHeap, can_drop_node)
{
	DHeap<int> a(2, 6);
	a.changeKey(2, 6);
	a.changeKey(5, -1);
	a.drop(2);
	ASSERT_EQ(a.keys[0], -1);
}

TEST(DHeap, throw_when_wrong_pos_drop)
{
	DHeap<int> a(2, 6);
	ASSERT_ANY_THROW(a.drop(6));
}

TEST(DHeap, can_changekey)
{
	DHeap<int> a(2, 6);
	a.changeKey(5, 5);
	ASSERT_EQ(a.keys[5], 5);
}

TEST(DHeap, throw_when_wrong_pos_changekey)
{
	DHeap<int> a(2, 5);
	ASSERT_ANY_THROW(a.changeKey(-4, 5));
}

TEST(DHeap, can_heapfy)
{
	DHeap<int> a(2, 5);
	a.changeKey(0, 4);
	a.changeKey(1, -2);
	a.changeKey(2, 0);
	a.changeKey(3, 9);
	a.changeKey(4, 1488);
	a.heapfy();
	int r[5] = { -2, 4, 0, 9, 1488 };
	int count = 0;
	for (int i = 0; i < 5; i++)
	{
		if (a.keys[i] == r[i])
			count++;
	}
	ASSERT_EQ(count, 5);
}

TEST(DHeap, droplast)
{
	DHeap<int> a;
	ASSERT_NO_THROW(a.drop(0));
	
}