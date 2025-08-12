#include <iostream>

using namespace std;

class MyVector{
public:

    int size;
    int value;
    int* array;
    
        MyVector() = default;
        MyVector(int _size, int _value) : size(_size), value(_value){
            capacity = (size > 0) ? size * 2 : 1;
            array = new int[capacity];
            for(int i = 0; i < size; i++)
            {
                array[i] = value;
            }
        };
        
        ~MyVector(){
            delete[] array;
        }
        
        MyVector(const MyVector& other) : size(other.size), value(other.value), capacity(other.size * 2), array(new int[other.capacity]){
            for(int i = 0; i < other.size; i++)
            {
                array[i] = other.array[i];
            }
        }
        
        MyVector& operator=(const MyVector other){
            if(&other == this)
                return *this;
            size = other.size;
            value = other.value;
            capacity = other.size * 2;
            array = new int[other.capacity];
            for(int i = 0; i < other.size; i++)
            {
                array[i] = other.array[i];
            }
        }
        
        
        
        void out(){
            for(int i = 0; i < size; i++)
            {
                cout << array[i];
            }
        }
        
         void UpdateCapacity() {
            capacity = capacity * 2;
            int* tempArray = new int[capacity];
            
            for (int i = 0; i < size; i++) {
                tempArray[i] = array[i];
            }
            
            delete[] array;
            array = tempArray;
        }
        
        void My_push_back(int number) {
            if (size == capacity) {
                UpdateCapacity();
            }
            array[size] = number;
            size++;
        }
        
        void My_pop_back()
        {
            if(size < 0){
                cout << "Массив не может быть меньше нуля, размер массива остался с прежним значением";
                size++;
            }
            array[size] = 0;
            size--;
        }
        
        int My_size(){
            return size;
        }
        
        //erase, оператор[]
        void My_insert(int xValue,int index){
            if(size > index && index > 0)
            {
                int* tempArray = new int[size];
                for(int i = 0; i < size; i++)
                {
                    tempArray[i] = array[i];
                }
                if(size==capacity)
                    UpdateCapacity();
                array[index] = xValue;
                for(int i =  index; i < size; i++)
                {
                  
                    array[i + 1] = tempArray[i];
                }
                delete[] tempArray;
                size++;
            }
            else cout << "Допущена ошибка!";
        }
        
        void My_erase(int index){
            if(size > index && index > 0)
            {
                int* tempArray = new int[size];
                for(int i = 0; i < size; i++)
                {
                    tempArray[i] = array[i];
                }
                for(int i =  index; i < size; i++)
                {
                  
                    array[i - 1] = tempArray[i];
                }
                delete[] tempArray;
                size--;
            }
            
        }
        
            int& operator[](int index) {return array[index];}
            const int& operator[](int index) const {return array[index];}
    
        
private:
    int capacity;
};


int main()
{

    return 0;
}