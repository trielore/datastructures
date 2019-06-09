extern "C"
{
#include "linkedlist.h"
};
#include <gtest/gtest.h>
#include <stdio.h>

int test_data[] = {10, 100, 15, 35};
int sz = sizeof(test_data) / sizeof(test_data[0]);

void create_test_list(linkedlist **ll)
{
    *ll = create_linkedlist();
    linkedlist *l = *ll;
    int v;
    for (int i = 0; i < sz; ++i)
    {
        printf("Testing with data point %d\n", i);
        insert_front(l, test_data[i]);
        boolean r = get_head(l, &v);
        ASSERT_TRUE(r);
        EXPECT_EQ(test_data[i], v);
        ASSERT_TRUE(get_tail(l, &v));
        EXPECT_EQ(test_data[0], v);
        EXPECT_EQ(i + 1, size_linkedlist(l));
    }
}

TEST(LinkedListTest, Insert2Front)
{
    printf("Dataset is of size: %d (head test)\n", sz);
    linkedlist *l;
    create_test_list(&l);
    int v;
    int i = sz - 1;
    while (remove_head(l, &v))
    {
        printf("Removing data point %d\n", i);
        EXPECT_EQ(test_data[i], v);
        EXPECT_EQ(i, size_linkedlist(l));
        --i;
    }
    EXPECT_EQ(0, size_linkedlist(l));
    delete_linkedlist(l);
}
TEST(LinkedListTest, Insert2Back)
{
    printf("Dataset is of size: %d (tail test)\n", sz);
    linkedlist *l;
    create_test_list(&l);
    int v;
    int i = 0;
    while (remove_tail(l, &v))
    {
        printf("Removing data point %d\n", i);
        EXPECT_EQ(test_data[i], v);
        ++i;
        EXPECT_EQ(sz - i, size_linkedlist(l));
    }
    EXPECT_EQ(0, size_linkedlist(l));
    delete_linkedlist(l);
}
