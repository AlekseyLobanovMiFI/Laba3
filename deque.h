#ifndef DEQUE_H
#define DEQUE_H

template<class T> class Deque{
private:
    ListSequence<T> data;

public:
    void PushFront(const T& item) {
        data.Prepend(item);
    }

    void PushBack(const T& item) {
        data.Append(item);
    }

    T PopFront() {
        if (IsEmpty()) {
            throw std::out_of_range("Empty deque");
        }

        T val = data.GetFirst();
        data.RemoveFirst();
        return val;
    }

    T PopBack() {
        if (IsEmpty()) {
            throw std::out_of_range("Empty deque");
        }

        T val = data.GetLast();
        data.RemoveLast();
        return val;
    }

    T Front() const {
        return data.GetFirst();
    }

    T Back() const {
        return data.GetLast();
    }

    bool IsEmpty() const {
        return data.GetLength() == 0;
    }

    int Size() const {
        return data.GetLength();
    }
};

#endif