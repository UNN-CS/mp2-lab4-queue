#include "tqueue.h"
#include <gtest.h>
#include <iostream>

using namespace std;

TEST(TQueue, can_create_queue_with_positive_length)
{
	ASSERT_NO_THROW(TQueue q(3));
}

TEST(TQueue, can_put_element)
{
	TQueue q(3);
	ASSERT_NO_THROW(q.Put(2));
}

TEST(TQueue, can_get_element)
{
	TQueue q(3);
	q.Put(3);
	ASSERT_NO_THROW(q.Get());
}

TEST(TQueue, can_get_correct_element)
{
	TQueue q(3);
	q.Put(3);
	EXPECT_EQ(3, q.Get());
}

TEST(TQueue, can_get_correct_element2)
{
	TQueue q(3);
	q.Put(3);
	q.Put(2);
	q.Put(1);
	EXPECT_EQ(3, q.Get());
}

TEST(TQueue, can_get_correct_element_after_get)
{
	TQueue q(3);
	q.Put(3);
	q.Put(2);
	q.Put(1);
	q.Get();
	EXPECT_EQ (2, q.Get());
}

TEST(TQueue, put_correct_element)
{
	TQueue q(3);
	q.Put(1);
	EXPECT_EQ(1, q.TopElem());
}

TEST(TQueue, can_put_element_multiple_times)
{
	TQueue q(3);
	q.Put(1);
	q.Put(2);
	q.Put(3);
	q.Get();
	ASSERT_NO_THROW(q.Put(2));
}


TEST(TQueue, create_empty_queue)
{
	TQueue q(3);

	EXPECT_EQ(true, q.IsEmpty());
}

TEST(TQueue, can_create_queue_with_empty_argument)
{
	ASSERT_NO_THROW(TQueue q());

}

TEST(TQueue, correct_topelem)
{
	TQueue q(3);
	q.Put(3);
	q.Put(2);
	EXPECT_EQ(3, q.TopElem());
}

TEST(TQueue, topelem_dont_delete_elem)
{
	TQueue q(3);
	q.Put(3);
	q.Put(2);
	q.TopElem();
	q.TopElem();
	EXPECT_EQ(3, q.TopElem());
}

TEST(TQueue, queue_with_zero_length_isnt_valid)
{
	TQueue q(0);
	EXPECT_EQ(false, q.IsValid());
}

TEST(TQueue, queue_with_negative_length_isnt_valid)
{
	TQueue q(-1);
	EXPECT_EQ(false, q.IsValid());
}

TEST(TQueue, overfulled_queue_isnt_valid)
{
	TQueue q(1);
	q.Put(3);
	q.Put(2);
	EXPECT_EQ(false, q.IsValid());
}

TEST(TQueue, can)
{
	system("pause");
}


