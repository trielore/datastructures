extern "C"
{
#include "linkedlist.h"
};
#include <gtest/gtest.h>
#include <stdio.h>

TEST(LinkedListTest, Insert2Front)
{
    linkedlist *l = create_linkedlist();
    insert_front(l, 154);
    int v;
    ASSERT_TRUE(get_head(l, &v));
    EXPECT_EQ(154, v);
    delete_linkedlist(l);
}
