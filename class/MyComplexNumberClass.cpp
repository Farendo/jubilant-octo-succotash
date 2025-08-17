#include <iostream>
#include <math.h>


using namespace std;

class MyComplexNumber {
public: MyComplexNumber() = default;
	  MyComplexNumber(float _real, float _imaginary) : realNumber(_real), imaginaryNumber(_imaginary) {};
	  MyComplexNumber(MyComplexNumber& other) : realNumber(other.realNumber), imaginaryNumber(other.imaginaryNumber) {};
	  MyComplexNumber& operator = (const MyComplexNumber other)
	  {
		  if (&other == this)
			  return *this;
		  realNumber = other.realNumber;
		  imaginaryNumber = other.imaginaryNumber;
	  }

	  MyComplexNumber& operator+=(const MyComplexNumber& other)
	  {
		  realNumber += other.realNumber;
		  imaginaryNumber += other.imaginaryNumber;
		  return *this;
	  }
	  MyComplexNumber& operator-=(const MyComplexNumber& other)
	  {
		  realNumber -= other.realNumber;
		  imaginaryNumber -= other.imaginaryNumber;
		  return *this;
	  }
	  MyComplexNumber& operator*=(const MyComplexNumber& other)
	  {
		  realNumber *= other.realNumber;
		  imaginaryNumber *= other.imaginaryNumber;
		  return *this;
	  }
	  MyComplexNumber& operator/=(MyComplexNumber& other)
	  {
		  if (pow(other.realNumber, 2) + pow(other.imaginaryNumber, 2) != 0)
		  {
			  realNumber = (realNumber * other.realNumber + imaginaryNumber * other.imaginaryNumber) / (pow(other.realNumber, 2) + pow(other.imaginaryNumber, 2));
			  imaginaryNumber = (imaginaryNumber * other.realNumber - realNumber * other.imaginaryNumber) / (pow(other.realNumber, 2) + pow(other.imaginaryNumber, 2));
		  }
		  else
			  cout << "Деление невозможно";
		  return *this;
	  }
	  MyComplexNumber& operator++()
	  {
		  realNumber++;
		  imaginaryNumber++;
		  return *this;
	  }
	  MyComplexNumber& operator--()
	  {
		  realNumber--;
		  imaginaryNumber--;
		  return *this;
	  }
	  MyComplexNumber operator++(int)
	  {
		  MyComplexNumber temp = *this;
		  realNumber++;
		  imaginaryNumber++;
		  return temp;
	  }
	  MyComplexNumber operator--(int)
	  {
		  MyComplexNumber temp = *this;
		  realNumber--;
		  imaginaryNumber--;
		  return temp;
	  }

	  bool operator==(const MyComplexNumber& other) const
	  {
		  return realNumber == other.realNumber && imaginaryNumber == other.imaginaryNumber;
	  }
	  bool operator!=(const MyComplexNumber& other) const
	  {
		  return realNumber != other.realNumber || imaginaryNumber != other.imaginaryNumber;
	  }

	  operator int() const {
		  return realNumber;
	  }

	  friend MyComplexNumber operator+ (const MyComplexNumber& firstCN, const MyComplexNumber& secondCN);
	  friend MyComplexNumber operator- (const MyComplexNumber& firstCN, const MyComplexNumber& secondCN);
	  friend MyComplexNumber operator* (const MyComplexNumber& firstCN, const MyComplexNumber& secondCN);
	  friend MyComplexNumber operator/ (MyComplexNumber& firstCN, MyComplexNumber& secondCN);

	  friend ostream& operator << (ostream& out, const MyComplexNumber& c);
	  friend istream& operator >> (istream& in, MyComplexNumber& c);



private:
	float realNumber = 0;
	float imaginaryNumber = 0;

};

MyComplexNumber operator+ (MyComplexNumber& firstCN, const MyComplexNumber& secondCN)
{
	MyComplexNumber temp(firstCN);
	temp += secondCN;
	return temp;
}
MyComplexNumber operator- (MyComplexNumber& firstCN, const MyComplexNumber& secondCN)
{
	MyComplexNumber temp(firstCN);
	temp -= secondCN;
	return temp;
}
MyComplexNumber operator* (MyComplexNumber& firstCN, const MyComplexNumber& secondCN)
{
	MyComplexNumber temp(firstCN);
	temp *= secondCN;
	return temp;
}
MyComplexNumber operator/ (MyComplexNumber& firstCN, MyComplexNumber& secondCN)
{
	MyComplexNumber temp(firstCN);
	temp /= secondCN;
	return temp;
}


ostream& operator << (ostream& out, const MyComplexNumber& c) {
	if (c.realNumber != 0)
		out << c.realNumber;
	if (c.imaginaryNumber != 0)
		if (c.imaginaryNumber > 0)
		{
			out << "+";
			out << c.imaginaryNumber;
			out << "i";
		}
		else
		{
			out << c.imaginaryNumber;
			out << "i";
		}
	return out;
}

istream& operator >> (istream& in, MyComplexNumber& c) {
	in >> c.realNumber;
	in >> c.imaginaryNumber;
	return in;
}


int main() {
	MyComplexNumber n;
	cin >> n;
	cout << n;
	return 0;
}