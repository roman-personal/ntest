#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <vector>
#include "task3.h"

namespace {

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
        Delete(list);
    }

    List* FromVector(std::vector<int> v) {
        List* head = nullptr;
        for (auto i = v.rbegin(); i < v.rend(); ++i) {
            List* node = new List();
            node->payload = *i;
            node->next = head;
            head = node;
        }
        return head;
    }

    std::vector<int> ToVector(List* head) {
        std::vector<int> v;
        while (head != nullptr) {
            v.push_back(head->payload);
            head = head->next;
        }
        return v;
    }

    void Delete(List* head) {
        List* node;
        while (head != nullptr) {
            node = head->next;
            delete head;
            head = node;
        }
    }
};

TEST_F(Task3Test, EmptyList) {
    remove_every_fifth(list);
    EXPECT_EQ(list, nullptr);
}

TEST_F(Task3Test, LessThan5Nodes) {
    std::vector<int> v = { 1, 2, 3, 4};
    list = FromVector(v);
    remove_every_fifth(list);
    auto r = ToVector(list);
    EXPECT_THAT(r, ::testing::ElementsAre(1, 2, 3, 4));
}

TEST_F(Task3Test, FiveNodes) {
    std::vector<int> v = { 1, 2, 3, 4, 5};
    list = FromVector(v);
    remove_every_fifth(list);
    auto r = ToVector(list);
    EXPECT_THAT(r, ::testing::ElementsAre(1, 2, 3, 4));
}

TEST_F(Task3Test, TenNodes) {
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    list = FromVector(v);
    remove_every_fifth(list);
    auto r = ToVector(list);
    EXPECT_THAT(r, ::testing::ElementsAre(1, 2, 3, 4, 6, 7, 8, 9));
}
}