extern "C"
{
#include "linkedlist.h"
};
#include <gtest/gtest.h>
#include <stdio.h>

TEST(LinkedListTest, InsertOneElement)
{
    linkedlist *l = create_linkedlist();
    ASSERT_EQ(0, size_linkedlist(l));
    ASSERT_EQ(0, get_head_node(l));


    insert_front(l, 154);

    ASSERT_EQ(1, size_linkedlist(l)); 
    node* it = get_head_node(l);
    ASSERT_NE(nullptr, it);
    EXPECT_EQ(154, get_node_value(it));

    EXPECT_EQ(nullptr, get_next(it));

    int v;
    ASSERT_TRUE(get_head_value(l, &v));
    ASSERT_EQ(154, v);
    v = -1;
    ASSERT_TRUE(get_tail_value(l, &v));
    ASSERT_EQ(154, v);

    delete_linkedlist(l);
}

TEST(LinkedListTest, InsertThreeElement)
{
linkedlist *l = create_linkedlist();
    ASSERT_EQ(0, size_linkedlist(l));
    insert_front(l, 99);
    insert_front(l, 154);
    insert_front(l, 23);

    // 23->154->99
    
    ASSERT_EQ(3, size_linkedlist(l)); 
    node* it = get_head_node(l);  
    ASSERT_NE(nullptr, it);
    EXPECT_EQ(23, get_node_value(it));

    it = get_next(it);
    EXPECT_EQ(154, get_node_value(it));

    it = get_next(it);
    EXPECT_EQ(99, get_node_value(it));

    EXPECT_EQ(nullptr, get_next(it));

    int v;
    ASSERT_TRUE(get_head_value(l, &v));
    ASSERT_EQ(23, v);

    v = -1;
    ASSERT_TRUE(get_tail_value(l, &v));
    ASSERT_EQ(99, v);

    v = -1;
    remove_head(l, &v); // 154 -> 99 // v == 23
    ASSERT_EQ(23, v);
    ASSERT_EQ(2, size_linkedlist(l)); 
    v = -1;
    ASSERT_TRUE(get_head_value(l, &v));
    ASSERT_EQ(154, v);

    it = get_head_node(l);
    ASSERT_NE(nullptr, it);
    ASSERT_EQ(154, get_node_value(it));

    it = get_next(it);
    ASSERT_EQ(99, get_node_value(it));
    ASSERT_EQ(nullptr, get_next(it));

    v = -1;
    remove_tail(l, &v); // 154 // v = 99
    ASSERT_EQ(99, v);
    ASSERT_EQ(1, size_linkedlist(l)); 
    ASSERT_TRUE(get_head_value(l, &v));
    ASSERT_EQ(154, v);

    v = -1;
    remove_tail(l, &v); // empty // v = 154
    ASSERT_EQ(154, v);
    ASSERT_EQ(0, size_linkedlist(l));

    ASSERT_FALSE(remove_head(l, &v)); // empty // return false
    ASSERT_FALSE(remove_tail(l, &v)); // empty // return false
    ASSERT_EQ(nullptr, get_head_node(l));
    ASSERT_FALSE(get_tail_value(l, &v));
    ASSERT_FALSE(get_head_value(l, &v));

    insert_front(l, 876); // 876
    ASSERT_EQ(1, size_linkedlist(l)); 
     v= -1;
    ASSERT_TRUE(get_head_value(l, &v));
    ASSERT_EQ(876, v);

    replace_value_with(get_head_node(l), 987); // 987
    ASSERT_EQ(1, size_linkedlist(l));
    v = -1;
    ASSERT_TRUE(get_tail_value(l, &v));
    ASSERT_EQ(987, v);

    insert_back(l, 400); // 987 -> 400
    insert_front(l, 2367); //  2367 -> 987 -> 400
    it = get_head_node(l);
    it = get_next(it);
    insert_after(it, 101001); // 2367 -> 987 -> 101001 -> 400

    ASSERT_EQ(4, size_linkedlist(l));
    ASSERT_NE(nullptr, it = get_head_node(l));
    ASSERT_EQ(2367, get_node_value(it));

    ASSERT_NE(nullptr, it = get_next(it));
    ASSERT_EQ(987, get_node_value(it));

    ASSERT_NE(nullptr, it = get_next(it));
    ASSERT_EQ(101001, get_node_value(it));

    ASSERT_NE(nullptr, it = get_next(it));
    ASSERT_EQ(400, get_node_value(it));

    ASSERT_EQ(nullptr, it = get_next(it));

    delete_linkedlist(l);
}

TEST(LinkedListTest, InsertFrontNBack)
{
    linkedlist *l = create_linkedlist();
    insert_front(l, 154);
    insert_back(l, 55);
    int v;
    ASSERT_TRUE(get_head_value(l, &v));
    EXPECT_EQ(154, v);
    ASSERT_TRUE(get_tail_value(l, &v));
    EXPECT_EQ(55, v);
    delete_linkedlist(l); 
}
