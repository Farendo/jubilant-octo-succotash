#pragma once
#include <iostream>
#include <cstddef>


template<class T>
class MyVector {
public:
    MyVector() = default;
    MyVector(size_t _size, T _value = 0);
    ~MyVector();

    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector other);
    T& operator[](int index);
    friend std::ostream& operator<<(ostream& out, const MyVector& v);

    void My_push_back(T number);
    void My_pop_back();
    size_t My_size();
    void My_insert(T xValue, int index);
    void My_erase(int index);


private:
    size_t size;
    T* array;
    int capacity;
    const int increaseCapacity = 2;

    void UpdateCapacity();
};

std::ostream& operator<<(ostream& out, const MyVector& v);


#include "MyVector.tpp"