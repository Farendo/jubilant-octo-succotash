#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

class MyString{
public:
    MyString() = default;
    MyString(char* _stringArray){
            size = strlen(_stringArray);
            UpdateCapacity(size);
            stringArray = new char[capacity];
            for(int i = 0; i < size; i++){
                stringArray[i] = _stringArray[i];
            }
    };

    ~MyString(){
        delete[] stringArray;
    }
    
    MyString(const MyString& other) : capacity(other.capacity), size(other.size)
    {
        for(int i = 0; i < other.size; i++)
        {
            stringArray[i] = other.stringArray[i];
        }
    }
    
    MyString& operator=(const MyString other)
    {
        capacity = other.capacity;
        size = other.size;
        for(int i = 0; i < other.size; i++)
        {
            stringArray[i] = other.stringArray[i];
        }
    }
    
    MyString& operator+=(const MyString& other)
    {
        size += other.size;
        UpdateCapacity(size);
        UpdateArray();
        strcat(stringArray, other.stringArray);
        
        return *this;
    }
    
    char& operator[](int index) {return stringArray[index];}
    const char& operator[](int index) const {return stringArray[index];}
    friend std::ostream& operator<<(ostream& out, const MyString& s);
    friend std::istream& operator>>(istream& in, MyString& s);
    friend MyString operator+(const MyString& firstLine, const MyString& secondLine);


    
    
private:
    char* stringArray = nullptr;
    size_t capacity = 1;
    size_t size = 0;
    int increaseCapacity = 2;
    
    void UpdateCapacity(size_t _size) {
        while(capacity <= _size){
            capacity *= increaseCapacity;
        }
    }
    
    void UpdateArray()
    {
        if(stringArray != nullptr)
        {
            char* tempArray = new char[size];
            for (int i = 0; i < size; i++) {
                tempArray[i] = stringArray[i];
            }
            delete[] stringArray;
            stringArray = tempArray;
        }
    }
};

    MyString operator+(const MyString& firstLine, const MyString& secondLine)
    {
        MyString result;
        result.size = firstLine.size + secondLine.size;
        result.UpdateCapacity(result.size);
        result.stringArray = new char[result.capacity];
        strcpy(result.stringArray, firstLine.stringArray);
        strcat(result.stringArray, secondLine.stringArray);
        return result;
    }
    


    std::ostream& operator<<(ostream& out, const MyString& s)
    {
        for(int i = 0; i < s.size; i++)
        {
            out << s.stringArray[i];
        }
        return out;
    }
    
    std::istream& operator>>(istream& in, MyString& s)
    {
        char tempBuffer[1024];
        in >> std::setw(1024) >> tempBuffer;
        s.stringArray = new char[strlen(tempBuffer) + 1];
        strcpy(s.stringArray, tempBuffer);
        return in;
    }
    
    
  
int main()
{

    return 0;
}