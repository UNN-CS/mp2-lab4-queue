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


