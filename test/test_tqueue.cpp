//
// Created by rootreddragon on 12/23/2018.
//

#include "TQueue.h"
#include <gtest.h>


TEST(TQueue, can_create_the_queue)
{
ASSERT_NO_THROW(TQueue(3));
}

TEST(TQueue, cant_create_queue_with_negative_length)
{
ASSERT_ANY_THROW(TQueue(-1));
}

TEST(TQueue, can_put_the_element)
{
TQueue q(1);
q.Put(5);
ASSERT_NO_THROW(q.Get());
}



TEST(TQueue, can_return_element )
{
TQueue q(1);
q.Put(3);
EXPECT_EQ(3, q.Get());
}

TEST(TQueue, return_zero_when_queue_is_empty)
{
TQueue q(1);
EXPECT_EQ(0, q.Get());
}

TEST(TQueue, can_get_next_index)
{
TQueue q(3);
EXPECT_EQ(2, q.GetNextIndex(1));
}

TEST(TQueue, banding_of_queue)
{
TQueue q(3);
EXPECT_EQ(0, q.GetNextIndex(2));
}