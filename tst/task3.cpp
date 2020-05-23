#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <vector>
#include "task3.h"

class Task3Test : public ::testing::Test
{
protected:
    List* list;

    Task3Test() {}

    ~Task3Test() override {}

    void SetUp() override {
        list = nullptr;
    }

    void TearDown() override {
        destruct_list(list);
    }

    List* create_list(std::initializer_list<int> v) {
        List* head = nullptr;
        List* tail = nullptr;
        for (auto i = v.begin(); i < v.end(); ++i) {
            List* node = new List();
            node->payload = *i;
            node->next = nullptr;
            if (head == nullptr) {
                head = node;
                tail = node;
            }
            else {
                tail->next = node;
                tail = node;
            }
        }
        return head;
    }

    void destruct_list(List* head) {
        List* node;
        while (head != nullptr) {
            node = head->next;
            delete head;
            head = node;
        }
    }

    bool is_same(List* head, std::initializer_list<int> l) {
        for (auto i = l.begin(); i < l.end(); ++i) {
            if (head == nullptr)
                return false;
            if (head->payload != *i)
                return false;
            head = head->next;
        }
        return head == nullptr;
    }

};

TEST_F(Task3Test, EmptyList) {
    remove_every_fifth(list);
    EXPECT_EQ(list, nullptr);
}

TEST_F(Task3Test, LessThanFiveNodes) {
    list = create_list({ 1, 2, 3, 4});
    remove_every_fifth(list);
    EXPECT_TRUE(is_same(list, {1, 2, 3, 4}));
}

TEST_F(Task3Test, FiveNodes) {
    list = create_list({ 1, 2, 3, 4, 5});
    remove_every_fifth(list);
    EXPECT_TRUE(is_same(list, {1, 2, 3, 4}));
}

TEST_F(Task3Test, MoreThanFiveNodes) {
    list = create_list({ 1, 2, 3, 4, 5, 6});
    remove_every_fifth(list);
    EXPECT_TRUE(is_same(list, {1, 2, 3, 4, 6}));
}

TEST_F(Task3Test, LessThanTenNodes) {
    list = create_list({ 1, 2, 3, 4, 5, 6, 7, 8, 9});
    remove_every_fifth(list);
    EXPECT_TRUE(is_same(list, {1, 2, 3, 4, 6, 7, 8, 9}));
}

TEST_F(Task3Test, TenNodes) {
    list = create_list({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    remove_every_fifth(list);
    EXPECT_TRUE(is_same(list, {1, 2, 3, 4, 6, 7, 8, 9}));
}

TEST_F(Task3Test, MoreThanTenNodes) {
    list = create_list({ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});
    remove_every_fifth(list);
    EXPECT_TRUE(is_same(list, {1, 2, 3, 4, 6, 7, 8, 9, 11}));
}
