#pragma once
#include <iostream>
#include <iterator>
#include <stdexcept>

template<typename Buff, typename Tp, typename Distance = ptrdiff_t, typename Pointer = Tp*, typename Reference = Tp&>
class CircularIterator : public std::iterator<std::random_access_iterator_tag, Tp> {
private:
    Buff* buff;
    int index_;

public:
    typedef typename std::iterator<std::random_access_iterator_tag, Tp, Distance, Pointer, Reference> base_iterator;

    typedef typename std::random_access_iterator_tag ;
    typedef typename base_iterator::value_type;
    typedef typename base_iterator::difference_type ;
    typedef typename base_iterator::pointer;
    typedef typename base_iterator::reference ;

    CircularIterator(const CircularIterator&) = default;
    ~CircularIterator() = default;
    CircularIterator(Buff& buff, int index) : buff(&buff), index_(index) {}

    CircularIterator& operator=(const CircularIterator& it) {
        buff = it.buff;
        index_ = it.index_;
        return *this;
    }

    Tp& operator*() {
        return (*buff)[index_];
    }

    Tp* operator->() {
        return &(*buff)[index_];
    }

    bool operator==(const CircularIterator& it) const {
        return index_ == it.index_;
    }

    bool operator!=(const CircularIterator& it) const {
        return index_ != it.index_;
    }

    bool operator>=(const CircularIterator& it) const {
        return index_ >= it.index_;
    }

    bool operator>(const CircularIterator& it) const {
        return index_ > it.index_;
    }

    bool operator<=(const CircularIterator& it) const {
        return index_ <= it.index_;
    }

    bool operator<(const CircularIterator& it) const {
        return index_ < it.index_;
    }

    CircularIterator operator++() {
        ++index_;
        return *this;
    }

    CircularIterator operator++(int) {
        CircularIterator temp = *this;
        ++index_;
        return temp;
    }

    CircularIterator operator--() {
        --index_;
        return *this;
    }

    CircularIterator operator--(int) {
        CircularIterator temp = *this;
        --index_;
        return temp;
    }

    CircularIterator operator+=(const int n) {
        index_ += n;
        return *this;
    }

    CircularIterator operator-=(const int n) {
        index_ -= n;
        return *this;
    }

    CircularIterator operator+(const int n) const {
        CircularIterator result = *this;
        result += n;
        return result;
    }

    CircularIterator operator-(const int n) const {
        CircularIterator result = *this;
        result -= n;
        return result;
    }

    int operator-(const CircularIterator& it) const {
        return index_ - it.index_;
    }
};

template <typename T>
class CircularBuffer {
private:
    int capacity_;
    int size_;
    T* begin_;
    int num_;

public:
    CircularBuffer() {
        capacity_ = 0;
        size_ = 0;
        begin_ = nullptr;
        num_ = 0;
    }

    CircularBuffer(int n) {
        capacity_ = n;
        size_ = 0;
        begin_ = new T[capacity_];
        num_ = 0;
    }

    ~CircularBuffer() {
        delete[] begin_;
    }

    typedef CircularIterator<CircularBuffer<T>, T> iterator;

    T& operator[](int index) {
        return *(begin_ + (num_ + index) % capacity_);
    }

    iterator begin() {
        return iterator(*this, 0);
    }

    iterator end() {
        return iterator(*this, size_);
    }

    void insertBegin(T element) {
        if (size_ == capacity_)
            throw std::runtime_error("Buffer is full");
        else {
            num_ = (num_ - 1 + capacity_) % capacity_;
            begin_[num_] = element;
            size_++;
        }
    }

    void deleteBegin() {
        if (size_ == 0)
            throw std::runtime_error("Buffer is empty");
        else {
            size_--;
            num_ = (num_ + 1 + capacity_) % capacity_;
        }
    }

    void insertEnd(T element) {
        if (size_ == capacity_)
            throw std::runtime_error("Buffer is full");
        else {
            int new_num = (num_ + size_ + capacity_) % capacity_;
            begin_[new_num] = element;
            size_++;
        }
    }

    void deleteEnd() {
        if (size_ == 0)
            throw std::runtime_error("Buffer is empty");
        else {
            size_--;
        }
    }

    void insertIt(iterator&& it, T element) {
        if (it > end())
            throw std::runtime_error("Insert position is after end");
        else {
            insertEnd(*(end() - 1));
            iterator temp = end() - 2;
            while (temp != it) {
                *temp = *(temp - 1);
                temp--;
            }
            *it = element;
        }
    }

    void deleteIt(iterator&& it) {
        if (it >= end())
            throw std::runtime_error("Delete position is after end");
        else {
            while (it != end() - 1) {
                *it = *(it + 1);
                it++;
            }
            deleteEnd();
        }
    }

    void changeCap(int value) {
        if (value < size_)
            throw std::runtime_error("Not enough space for the new capacity");
        else {
            T* new_begin = new T[value];
            int i = num_, j = 0;
            for (; i < capacity_ && j < size_; i++, j++) {
                new_begin[j] = begin_[i];
            }
            for (i = 0; i < (num_ + size_ - 1 + capacity_) % capacity_ && j < size_; i++, j++) {
                new_begin[j] = begin_[i];
            }
            num_ = 0;
            capacity_ = value;
            delete[] begin_;
            begin_ = new_begin;
        }
    }
};
