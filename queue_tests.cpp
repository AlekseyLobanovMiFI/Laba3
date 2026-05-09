#include <gtest/gtest.h>
#include "queue.h"

// ====================== POSITIVE ======================

TEST(QueueTest, CreateEmpty) {
    Queue<int> q;

    EXPECT_TRUE(q.IsEmpty());
    EXPECT_EQ(q.Size(), 0);
}

TEST(QueueTest, EnqueueOneElement) {
    Queue<int> q;

    q.Enqueue(10);

    EXPECT_FALSE(q.IsEmpty());
    EXPECT_EQ(q.Size(), 1);
    EXPECT_EQ(q.Front(), 10);
    EXPECT_EQ(q.Back(), 10);
}

TEST(QueueTest, EnqueueSeveralElements) {
    Queue<int> q;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);

    EXPECT_EQ(q.Size(), 3);
    EXPECT_EQ(q.Front(), 1);
    EXPECT_EQ(q.Back(), 3);
}

TEST(QueueTest, DequeueReturnsFirstElement) {
    Queue<int> q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    EXPECT_EQ(q.Dequeue(), 10);
    EXPECT_EQ(q.Dequeue(), 20);
    EXPECT_EQ(q.Dequeue(), 30);
}

TEST(QueueTest, FifoOrder) {
    Queue<int> q;

    for (int i = 0; i < 20; i++) {
        q.Enqueue(i);
    }

    for (int i = 0; i < 20; i++) {
        EXPECT_EQ(q.Dequeue(), i);
    }

    EXPECT_TRUE(q.IsEmpty());
}

TEST(QueueTest, FrontDoesNotRemoveElement) {
    Queue<int> q;

    q.Enqueue(5);
    q.Enqueue(9);

    EXPECT_EQ(q.Front(), 5);
    EXPECT_EQ(q.Size(), 2);

    EXPECT_EQ(q.Front(), 5);
    EXPECT_EQ(q.Size(), 2);
}

TEST(QueueTest, BackDoesNotRemoveElement) {
    Queue<int> q;

    q.Enqueue(5);
    q.Enqueue(9);

    EXPECT_EQ(q.Back(), 9);
    EXPECT_EQ(q.Size(), 2);

    EXPECT_EQ(q.Back(), 9);
    EXPECT_EQ(q.Size(), 2);
}

TEST(QueueTest, GetByIndex) {
    Queue<int> q;

    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);

    EXPECT_EQ(q.Get(0), 10);
    EXPECT_EQ(q.Get(1), 20);
    EXPECT_EQ(q.Get(2), 30);
}

TEST(QueueTest, Clear) {
    Queue<int> q;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);

    q.Clear();

    EXPECT_TRUE(q.IsEmpty());
    EXPECT_EQ(q.Size(), 0);
}

TEST(QueueTest, PushAfterClear) {
    Queue<int> q;

    q.Enqueue(1);
    q.Enqueue(2);
    q.Clear();

    q.Enqueue(100);

    EXPECT_EQ(q.Size(), 1);
    EXPECT_EQ(q.Front(), 100);
    EXPECT_EQ(q.Back(), 100);
}

TEST(QueueTest, ResizeWorks) {
    Queue<int> q(2);

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);

    EXPECT_EQ(q.Size(), 5);

    EXPECT_EQ(q.Get(0), 1);
    EXPECT_EQ(q.Get(1), 2);
    EXPECT_EQ(q.Get(2), 3);
    EXPECT_EQ(q.Get(3), 4);
    EXPECT_EQ(q.Get(4), 5);
}

TEST(QueueTest, WrapAroundWorks) {
    Queue<int> q(4);

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);

    EXPECT_EQ(q.Dequeue(), 1);
    EXPECT_EQ(q.Dequeue(), 2);

    q.Enqueue(5);
    q.Enqueue(6);

    EXPECT_EQ(q.Size(), 4);

    EXPECT_EQ(q.Get(0), 3);
    EXPECT_EQ(q.Get(1), 4);
    EXPECT_EQ(q.Get(2), 5);
    EXPECT_EQ(q.Get(3), 6);

    EXPECT_EQ(q.Dequeue(), 3);
    EXPECT_EQ(q.Dequeue(), 4);
    EXPECT_EQ(q.Dequeue(), 5);
    EXPECT_EQ(q.Dequeue(), 6);
}

TEST(QueueTest, StressEnqueueDequeue) {
    Queue<int> q(3);

    for (int i = 0; i < 200; i++) {
        q.Enqueue(i);
    }

    EXPECT_EQ(q.Size(), 200);
    EXPECT_EQ(q.Front(), 0);
    EXPECT_EQ(q.Back(), 199);

    for (int i = 0; i < 200; i++) {
        EXPECT_EQ(q.Dequeue(), i);
    }

    EXPECT_TRUE(q.IsEmpty());
}

// ====================== NEGATIVE ======================

TEST(QueueTest, DequeueFromEmptyThrows) {
    Queue<int> q;

    EXPECT_THROW(q.Dequeue(), std::out_of_range);
}

TEST(QueueTest, FrontFromEmptyThrows) {
    Queue<int> q;

    EXPECT_THROW(q.Front(), std::out_of_range);
}

TEST(QueueTest, BackFromEmptyThrows) {
    Queue<int> q;

    EXPECT_THROW(q.Back(), std::out_of_range);
}

TEST(QueueTest, GetFromEmptyThrows) {
    Queue<int> q;

    EXPECT_THROW(q.Get(0), std::out_of_range);
}

TEST(QueueTest, GetNegativeIndexThrows) {
    Queue<int> q;

    q.Enqueue(1);
    q.Enqueue(2);

    EXPECT_THROW(q.Get(-1), std::out_of_range);
}

TEST(QueueTest, GetTooLargeIndexThrows) {
    Queue<int> q;

    q.Enqueue(1);
    q.Enqueue(2);

    EXPECT_THROW(q.Get(2), std::out_of_range);
}

TEST(QueueTest, InvalidCapacityZeroThrows) {
    EXPECT_THROW(Queue<int> q(0), std::invalid_argument);
}

TEST(QueueTest, InvalidCapacityNegativeThrows) {
    EXPECT_THROW(Queue<int> q(-5), std::invalid_argument);
}