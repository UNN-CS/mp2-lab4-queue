//
// Created by rootreddragon on 12/23/2018.
//

#include "TJobStream.h"

#include <gtest.h>


TEST(TJobStream, can_create_object)
{
ASSERT_NO_THROW(TJobStream(0.7, 0.6));
}

TEST(TJobStream, cant_create_with_negative_values)
{
ASSERT_ANY_THROW(TJobStream(-0.5, 0.8));
}

TEST(TJobStream, can_generate_task)
{
TJobStream task(1, 1);
task.taskGeneration();
EXPECT_EQ(1, task.getTaskNum());
}

TEST(TJobStream, can_generate_task_completion)
{
TJobStream task(1, 1);
task.taskGeneration();
EXPECT_EQ(1, task.taskWork());
}

TEST(TJobStream, can_return_index_of_task)
{
TJobStream task(1, 1);
task.taskGeneration();
task.taskGeneration();
task.taskGeneration();
EXPECT_EQ(3, task.getTaskNum());
}

TEST(TJobStream, cant_return_index_of_nonexistent_task)
{
TJobStream task(1, 1);
ASSERT_ANY_THROW(task.getTaskNum());
}
