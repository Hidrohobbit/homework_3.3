#include <iostream>
//Первое и второе задание 
class smart_array
{
public:
	void add_element(const int element)
	{
		if (count < size)
		{
			arr[count] = element;
			++count;
		}
		else
		{
			throw std::exception("add_element Выход за границы массива");
		}
	}
	int get_element(const int index)
	{
		if (index < size)
		{
			return arr[index];
		}
		else
		{
			throw std::exception("get_element Выход за границы массива");
		}
		
	}
	smart_array &operator = (const smart_array &other)
	{
		this->size = other.size;
		if (this->arr!=nullptr)
		{
			delete[] this->arr;
		}

		this->arr = new int[other.size];

		for (int i = 0; i < other.size; ++i)
		{
			this->arr[i] = other.arr[i];
		}
		return *this;
	}
	smart_array(int size)
	{
		int* arr = new int[size]();
		this->size = size;
		this->arr = arr;
	}
	~smart_array()
	{
		delete[] arr;
	}
private:
	int size;
	int* arr;
	int count = 0;

};

int main () 
{
	setlocale(LC_ALL, "Russian");
	
	try {
		smart_array arr0(5);
		arr0.add_element(1);
		arr0.add_element(4);
		arr0.add_element(155);
		arr0.add_element(14);
		arr0.add_element(15);

		smart_array arr1(2);
		arr1.add_element(9);
		arr1.add_element(99);

		smart_array arr2(3);
		arr2.add_element(9);
		arr2.add_element(99);
		arr2.add_element(999);

		arr0 = arr1 = arr2;

		std::cout <<arr0.get_element(0)	<< std::endl;
		std::cout <<arr0.get_element(1)	<< std::endl;
		std::cout <<arr0.get_element(2) << std::endl;
		std::cout <<arr1.get_element(0)	<< std::endl;
		std::cout <<arr1.get_element(1)	<< std::endl;
		std::cout <<arr1.get_element(2) << std::endl;
		std::cout <<arr2.get_element(0) << std::endl;
		std::cout <<arr2.get_element(1) << std::endl;
		std::cout <<arr2.get_element(2) << std::endl;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
	}

	return 0;
}