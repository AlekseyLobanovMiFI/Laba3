#include <gtest/gtest.h>
#include "deque.h"

// ====================== POSITIVE ======================

TEST(DequeTest, CreateEmpty) {
    Deque<int> dq;

    EXPECT_TRUE(dq.IsEmpty());
    EXPECT_EQ(dq.Size(), 0);
}

TEST(DequeTest, PushBackOneElement) {
    Deque<int> dq;

    dq.PushBack(10);

    EXPECT_FALSE(dq.IsEmpty());
    EXPECT_EQ(dq.Size(), 1);
    EXPECT_EQ(dq.Front(), 10);
    EXPECT_EQ(dq.Back(), 10);
    EXPECT_EQ(dq.Get(0), 10);
}

TEST(DequeTest, PushFrontOneElement) {
    Deque<int> dq;

    dq.PushFront(10);

    EXPECT_FALSE(dq.IsEmpty());
    EXPECT_EQ(dq.Size(), 1);
    EXPECT_EQ(dq.Front(), 10);
    EXPECT_EQ(dq.Back(), 10);
    EXPECT_EQ(dq.Get(0), 10);
}

TEST(DequeTest, PushBackSeveralElements) {
    Deque<int> dq;

    dq.PushBack(1);
    dq.PushBack(2);
    dq.PushBack(3);
    dq.PushBack(4);
    dq.PushBack(5);

    EXPECT_EQ(dq.Size(), 5);

    EXPECT_EQ(dq.Get(0), 1);
    EXPECT_EQ(dq.Get(1), 2);
    EXPECT_EQ(dq.Get(2), 3);
    EXPECT_EQ(dq.Get(3), 4);
    EXPECT_EQ(dq.Get(4), 5);

    EXPECT_EQ(dq.Front(), 1);
    EXPECT_EQ(dq.Back(), 5);
}

TEST(DequeTest, PushFrontSeveralElements) {
    Deque<int> dq;

    dq.PushFront(1);
    dq.PushFront(2);
    dq.PushFront(3);
    dq.PushFront(4);
    dq.PushFront(5);

    EXPECT_EQ(dq.Size(), 5);

    EXPECT_EQ(dq.Get(0), 5);
    EXPECT_EQ(dq.Get(1), 4);
    EXPECT_EQ(dq.Get(2), 3);
    EXPECT_EQ(dq.Get(3), 2);
    EXPECT_EQ(dq.Get(4), 1);

    EXPECT_EQ(dq.Front(), 5);
    EXPECT_EQ(dq.Back(), 1);
}

TEST(DequeTest, MixedPushFrontAndPushBack) {
    Deque<int> dq;

    dq.PushBack(10);
    dq.PushBack(20);
    dq.PushFront(5);
    dq.PushFront(1);
    dq.PushBack(30);

    EXPECT_EQ(dq.Size(), 5);

    EXPECT_EQ(dq.Get(0), 1);
    EXPECT_EQ(dq.Get(1), 5);
    EXPECT_EQ(dq.Get(2), 10);
    EXPECT_EQ(dq.Get(3), 20);
    EXPECT_EQ(dq.Get(4), 30);

    EXPECT_EQ(dq.Front(), 1);
    EXPECT_EQ(dq.Back(), 30);
}

TEST(DequeTest, PopFrontReturnsFirstElement) {
    Deque<int> dq;

    dq.PushBack(1);
    dq.PushBack(2);
    dq.PushBack(3);

    EXPECT_EQ(dq.PopFront(), 1);
    EXPECT_EQ(dq.PopFront(), 2);
    EXPECT_EQ(dq.PopFront(), 3);

    EXPECT_TRUE(dq.IsEmpty());
}

TEST(DequeTest, PopBackReturnsLastElement) {
    Deque<int> dq;

    dq.PushBack(1);
    dq.PushBack(2);
    dq.PushBack(3);

    EXPECT_EQ(dq.PopBack(), 3);
    EXPECT_EQ(dq.PopBack(), 2);
    EXPECT_EQ(dq.PopBack(), 1);

    EXPECT_TRUE(dq.IsEmpty());
}

TEST(DequeTest, MixedPopFrontAndPopBack) {
    Deque<int> dq;

    dq.PushBack(1);
    dq.PushBack(2);
    dq.PushBack(3);
    dq.PushBack(4);
    dq.PushBack(5);

    EXPECT_EQ(dq.PopFront(), 1);
    EXPECT_EQ(dq.PopBack(), 5);
    EXPECT_EQ(dq.PopFront(), 2);
    EXPECT_EQ(dq.PopBack(), 4);
    EXPECT_EQ(dq.PopFront(), 3);

    EXPECT_TRUE(dq.IsEmpty());
}

TEST(DequeTest, FrontDoesNotRemoveElement) {
    Deque<int> dq;

    dq.PushBack(10);
    dq.PushBack(20);

    EXPECT_EQ(dq.Front(), 10);
    EXPECT_EQ(dq.Size(), 2);

    EXPECT_EQ(dq.Front(), 10);
    EXPECT_EQ(dq.Size(), 2);
}

TEST(DequeTest, BackDoesNotRemoveElement) {
    Deque<int> dq;

    dq.PushBack(10);
    dq.PushBack(20);

    EXPECT_EQ(dq.Back(), 20);
    EXPECT_EQ(dq.Size(), 2);

    EXPECT_EQ(dq.Back(), 20);
    EXPECT_EQ(dq.Size(), 2);
}

TEST(DequeTest, Clear) {
    Deque<int> dq;

    dq.PushBack(1);
    dq.PushBack(2);
    dq.PushFront(0);

    dq.Clear();

    EXPECT_TRUE(dq.IsEmpty());
    EXPECT_EQ(dq.Size(), 0);
}

TEST(DequeTest, PushAfterClear) {
    Deque<int> dq;

    dq.PushBack(1);
    dq.PushBack(2);
    dq.Clear();

    dq.PushBack(100);

    EXPECT_EQ(dq.Size(), 1);
    EXPECT_EQ(dq.Front(), 100);
    EXPECT_EQ(dq.Back(), 100);
    EXPECT_EQ(dq.Get(0), 100);
}

TEST(DequeTest, SegmentGrowthBack) {
    Deque<int> dq;

    for (int i = 0; i < 20; i++) {
        dq.PushBack(i);
    }

    EXPECT_EQ(dq.Size(), 20);

    for (int i = 0; i < 20; i++) {
        EXPECT_EQ(dq.Get(i), i);
    }
}

TEST(DequeTest, SegmentGrowthFront) {
    Deque<int> dq;

    for (int i = 0; i < 20; i++) {
        dq.PushFront(i);
    }

    EXPECT_EQ(dq.Size(), 20);

    for (int i = 0; i < 20; i++) {
        EXPECT_EQ(dq.Get(i), 19 - i);
    }
}

TEST(DequeTest, AlternatingPushes) {
    Deque<int> dq;

    dq.PushBack(10);
    dq.PushFront(5);
    dq.PushBack(20);
    dq.PushFront(1);
    dq.PushBack(30);
    dq.PushFront(0);

    EXPECT_EQ(dq.Size(), 6);

    EXPECT_EQ(dq.Get(0), 0);
    EXPECT_EQ(dq.Get(1), 1);
    EXPECT_EQ(dq.Get(2), 5);
    EXPECT_EQ(dq.Get(3), 10);
    EXPECT_EQ(dq.Get(4), 20);
    EXPECT_EQ(dq.Get(5), 30);
}

TEST(DequeTest, StressPopFront) {
    Deque<int> dq;

    for (int i = 0; i < 100; i++) {
        dq.PushBack(i);
    }

    for (int i = 0; i < 100; i++) {
        EXPECT_EQ(dq.PopFront(), i);
    }

    EXPECT_TRUE(dq.IsEmpty());
}

TEST(DequeTest, StressPopBack) {
    Deque<int> dq;

    for (int i = 0; i < 100; i++) {
        dq.PushBack(i);
    }

    for (int i = 99; i >= 0; i--) {
        EXPECT_EQ(dq.PopBack(), i);
    }

    EXPECT_TRUE(dq.IsEmpty());
}

// ====================== NEGATIVE ======================

TEST(DequeTest, PopFrontFromEmptyThrows) {
    Deque<int> dq;

    EXPECT_THROW(dq.PopFront(), std::out_of_range);
}

TEST(DequeTest, PopBackFromEmptyThrows) {
    Deque<int> dq;

    EXPECT_THROW(dq.PopBack(), std::out_of_range);
}

TEST(DequeTest, FrontFromEmptyThrows) {
    Deque<int> dq;

    EXPECT_THROW(dq.Front(), std::out_of_range);
}

TEST(DequeTest, BackFromEmptyThrows) {
    Deque<int> dq;

    EXPECT_THROW(dq.Back(), std::out_of_range);
}

TEST(DequeTest, GetFromEmptyThrows) {
    Deque<int> dq;

    EXPECT_THROW(dq.Get(0), std::out_of_range);
}

TEST(DequeTest, GetNegativeIndexThrows) {
    Deque<int> dq;

    dq.PushBack(1);
    dq.PushBack(2);

    EXPECT_THROW(dq.Get(-1), std::out_of_range);
}

TEST(DequeTest, GetTooLargeIndexThrows) {
    Deque<int> dq;

    dq.PushBack(1);
    dq.PushBack(2);

    EXPECT_THROW(dq.Get(2), std::out_of_range);
}
