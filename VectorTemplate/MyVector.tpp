    #include "MyVector.hpp"
    #include <iostream>


    template<class T>
    MyVector<T>::MyVector() : size(0), capacity(0), array(nullptr) {}

    template<class T>
    MyVector<T>::MyVector(size_t _size, T _value) : size(_size), capacity(_size > 0 ? _size * 2 : 1) {
        array = new T[capacity];
        for (size_t i = 0; i < size; i++) {
            array[i] = _value;
        }
    }

    template<class T>
    MyVector<T>::~MyVector() {
        delete[] array;
    }

    template<class T>
    MyVector<T>& MyVector<T>::operator=(const MyVector& other) {
        if (this != &other) {
            delete[] array;
        
            size = other.size;
            capacity = other.capacity;
            array = new T[capacity];
        
            for (size_t i = 0; i < size; i++) {
                array[i] = other.array[i];
            }
        }
        return *this;
    }

    template<class T>
    T& MyVector<T>::operator[](size_t index) { return array[index]; }
    
    template<class T>
    MyVector<T>::friend std::ostream& operator<<(ostream& out, const MyVector& v);

    template<class T>
    void MyVector<T>::My_push_back(T number) {
        if (size >= capacity) {
            UpdateCapacity();
        }
        array[size++] = number;
    }

    template<class T>
    void MyVector<T>::My_pop_back() {
        if (size > 0) {
            --size;
        } else {
            std::cout << "array dont can be 0";
        }
    }


    template<class T>
    size_t MyVector<T>::My_size() {
        return size;
    }

    template<class T>
    void MyVector<T>::My_insert(T xValue, size_t index) {
        if (size == capacity)
            UpdateCapacity();
        if (size > index)
        {
            for (size_t i = size; i >= index; i--)
            {
                array[i] = array[i - 1];
            }

            array[index] = xValue;
            size++;
        }
        else cout << "Error!";
    }

    template<class T>
    void MyVector<T>::My_erase(size_t index) {
        if (size > index)
        {
            for (size_t i = index; i < size; i++)
            {
                array[i - 1] = array[i];
            }
            size--;
        }
    }




    template<class T>
    void MyVector<T>::UpdateCapacity() {
        capacity = (capacity == 0) ? 1 : capacity * increaseCapacity;
        T* newArray = new T[capacity];
    
        for (size_t i = 0; i < size; ++i) {
            newArray[i] = array[i];
        }
    
        delete[] array;
        array = newArray;
    }

    template<class T>
    std::ostream& operator<<(std::ostream& out, const MyVector<T>& v) {
        for (size_t i = 0; i < v.size; i++)
        {
            out << v.array[i] << " ";
        }
        return out;
    }