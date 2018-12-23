//
// Created by rootreddragon on 12/23/2018.
//

#include "TProc.h"
#include <gtest.h>

TEST(TProc, can_create_object)
{
ASSERT_NO_THROW(TProc());
}

TEST(TProc, can_return_count_of_work_tacts_and_check_for_execution)
{
TProc p;
TQueue q(1);
q.Put(4);
p.BusynessOfProc(q);
EXPECT_EQ(1, p.GetCountOfWorkTacts());
}

TEST(TProc, can_return_count_of_free_tact_and_check_for_executions)
{
TProc p;
TQueue q(1);
p.BusynessOfProc(q);
EXPECT_EQ(1, p.GetCountOfFreeTacts());
}