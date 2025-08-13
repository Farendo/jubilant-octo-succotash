#include <iostream>

using namespace std;

class MyVector{
public:
        MyVector() = default;
        MyVector(size_t _size, int _value = 0) : size(_size){
            capacity = (size > 0) ? size * increaseCapacity : 1;
            array = new int[capacity];
            for(int i = 0; i < size; i++)
            {
                array[i] = _value;
            }
        };
        
        ~MyVector(){
            delete[] array;
        }
        
        MyVector(const MyVector& other) : size(other.size), capacity(other.capacity), array(new int[other.capacity]){
            for(int i = 0; i < other.size; i++)
            {
                array[i] = other.array[i];
            }
        }
        
        MyVector& operator=(const MyVector other){
            if(&other == this)
                return *this;
            size = other.size;
            capacity = other.capacity;
            array = new int[other.capacity];
            for(int i = 0; i < other.size; i++)
            {
                array[i] = other.array[i];
            }
        }
        
        friend std::ostream& operator<<(ostream& out, const MyVector& v);
        
        void My_push_back(int number) {
            if (size == capacity) {
                UpdateCapacity();
            }
            array[size] = number;
            size++;
        }
        
        void My_pop_back()
        {
            if(size == 0){
                cout << "Массив не может быть меньше нуля, размер массива остался с прежним значением";
                size++;
            }
            size--;
        }
        
        int My_size(){
            return size;
        }
        
        void My_insert(int xValue,size_t index){
            if(size==capacity)
                UpdateCapacity();
            if(size > index)
            {
                for(int i = size; i >= index; i--)
                {
                    array[i] = array[i-1];
                }

                array[index] = xValue;
                size++;
            }
            else cout << "Допущена ошибка!";
        }
        
        void My_erase(size_t index){
            if(size > index)
            {
                for(int i = index; i < size; i++)
                {
                    array[i - 1] = array[i];
                }
                size--;
            }
            
        }
        
        int& operator[](int index) {return array[index];}
        const int& operator[](int index) const {return array[index];}
    
        
private:
    size_t size;
    int* array;
    int capacity;
    int increaseCapacity = 2;
    
    void UpdateCapacity() {
        capacity = capacity * increaseCapacity;
        int* tempArray = new int[capacity];
            
        for (int i = 0; i < size; i++) {
            tempArray[i] = array[i];
        }
            
        delete[] array;
        array = tempArray;
    }
};

        std::ostream& operator<<(ostream& out, const MyVector& v){
            for(int i = 0; i < v.size; i++)
            {
                out << v.array[i] << " ";
            }
            return out;
        }

int main()
{

    return 0;
}