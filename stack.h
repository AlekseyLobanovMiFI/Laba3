#ifndef STACK_H
#define STACK_H

template<class T> class Stack {
private:
    MutableArraySequence<T> data;

public:
    void Push(const T& item){
        data.Append(item);
    }

    T Pop() {
        if (data.GetLength() == 0){
            throw std::out_of_range("Empty stack");
        }

        T val = data.GetLast();
        data = data.RemoveLast();
        return val;
    }

    T Top() const {
        return data.GetLast();
    }

    bool IsEmpty() const {
        return data.GetLength() == 0;
    }
};

#endif
