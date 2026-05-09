#include <gtest/gtest.h>
#include "stack.h"

// ====================== POSITIVE ======================

TEST(StackTest, CreateEmpty) {
    Stack<int> st;

    EXPECT_TRUE(st.IsEmpty());
    EXPECT_EQ(st.Size(), 0);
}

TEST(StackTest, PushOneElement) {
    Stack<int> st;

    st.Push(10);

    EXPECT_FALSE(st.IsEmpty());
    EXPECT_EQ(st.Size(), 1);
    EXPECT_EQ(st.Top(), 10);
}

TEST(StackTest, PushSeveralElements) {
    Stack<int> st;

    st.Push(1);
    st.Push(2);
    st.Push(3);

    EXPECT_EQ(st.Size(), 3);
    EXPECT_EQ(st.Top(), 3);
}

TEST(StackTest, PopReturnsLastElement) {
    Stack<int> st;

    st.Push(10);
    st.Push(20);
    st.Push(30);

    EXPECT_EQ(st.Pop(), 30);
    EXPECT_EQ(st.Pop(), 20);
    EXPECT_EQ(st.Pop(), 10);
}

TEST(StackTest, LifoOrder) {
    Stack<int> st;

    for (int i = 0; i < 10; i++) {
        st.Push(i);
    }

    for (int i = 9; i >= 0; i--) {
        EXPECT_EQ(st.Pop(), i);
    }

    EXPECT_TRUE(st.IsEmpty());
}

TEST(StackTest, TopDoesNotRemoveElement) {
    Stack<int> st;

    st.Push(5);
    st.Push(9);

    EXPECT_EQ(st.Top(), 9);
    EXPECT_EQ(st.Size(), 2);

    EXPECT_EQ(st.Top(), 9);
    EXPECT_EQ(st.Size(), 2);
}

TEST(StackTest, GetByIndex) {
    Stack<int> st;

    st.Push(10);
    st.Push(20);
    st.Push(30);

    EXPECT_EQ(st.Get(0), 10);
    EXPECT_EQ(st.Get(1), 20);
    EXPECT_EQ(st.Get(2), 30);
}

TEST(StackTest, Clear) {
    Stack<int> st;

    st.Push(1);
    st.Push(2);
    st.Push(3);

    st.Clear();

    EXPECT_TRUE(st.IsEmpty());
    EXPECT_EQ(st.Size(), 0);
}

TEST(StackTest, PushAfterClear) {
    Stack<int> st;

    st.Push(1);
    st.Push(2);
    st.Clear();

    st.Push(100);

    EXPECT_EQ(st.Size(), 1);
    EXPECT_EQ(st.Top(), 100);
    EXPECT_EQ(st.Pop(), 100);
}

TEST(StackTest, StressPushPop) {
    Stack<int> st;

    for (int i = 0; i < 100; i++) {
        st.Push(i);
    }

    EXPECT_EQ(st.Size(), 100);
    EXPECT_EQ(st.Top(), 99);

    for (int i = 99; i >= 0; i--) {
        EXPECT_EQ(st.Pop(), i);
    }

    EXPECT_TRUE(st.IsEmpty());
}

// ====================== NEGATIVE ======================

TEST(StackTest, PopFromEmptyThrows) {
    Stack<int> st;

    EXPECT_THROW(st.Pop(), std::out_of_range);
}

TEST(StackTest, TopFromEmptyThrows) {
    Stack<int> st;

    EXPECT_THROW(st.Top(), std::out_of_range);
}

TEST(StackTest, GetFromEmptyThrows) {
    Stack<int> st;

    EXPECT_THROW(st.Get(0), std::out_of_range);
}

TEST(StackTest, GetNegativeIndexThrows) {
    Stack<int> st;

    st.Push(1);
    st.Push(2);

    EXPECT_THROW(st.Get(-1), std::out_of_range);
}

TEST(StackTest, GetTooLargeIndexThrows) {
    Stack<int> st;

    st.Push(1);
    st.Push(2);

    EXPECT_THROW(st.Get(2), std::out_of_range);
}
