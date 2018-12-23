//
// Created by rootreddragon on 12/23/2018.
//

#include <gtest.h>

#include "TStack.h"



TEST(TStack, can_create_the_stack)
{
ASSERT_NO_THROW(TStack(3));
}

TEST(TStack, cant_create_with_negative_length)
{
ASSERT_ANY_THROW(TStack(-1));
}

TEST(TStack, can_put_the_element)
{
TStack q(1);
q.Put(5);
ASSERT_NO_THROW(q.Get());
}

TEST(TStack, cant_put_the_element_in_full)
{
	TStack q(1);
	q.Put(5);
	EXPECT_EQ(q.Put(2), SetRetCode(DataFull));
}

TEST(TStack, can_return_element)
{
TStack q(1);
q.Put(3);
EXPECT_EQ(3, q.Get());
}

TEST(TStack, return_zero_when_queue_is_empty)
{
TStack q(1);
EXPECT_EQ(0, q.Get());
}

TEST(TStack, can_get_next_index)
{
TStack q(3);
EXPECT_EQ(2, q.GetNextIndex(1));
}

TEST(TStack, banding_of_stack)
{
IF_TYPE_STACKTOSTACK q(3);
EXPECT_EQ(0, q.GetNextIndex(2));
}