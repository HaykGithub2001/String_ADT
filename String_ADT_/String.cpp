#include"String.h"
#include <string>
String::String()
{
	size = 0;
	arr = nullptr;
}
String::String(const char* arr,const int length)
{
	size = length;
	this->arr = new char[size];
	for (int i = 0; i < length; i++)
	{
		this->arr[i] = arr[i];
	}
}
String::String(const String& other)
{
	size = other.size;
	this->arr = new char[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
}
String& String::operator=(String& const other) 
{
	size = other.size;
	this->arr = new char[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
	return *this;
}
String& String::operator=(String const other)
{
	size = other.size;
	this->arr = new char[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = other.arr[i];
	}
	return *this;
}

char& String::operator[](const int index)
{
	return arr[index];
}
String String:: operator+(String const& other) const
{
		char* arr_new = new char[size + other.size];
		int i = 0;
		for (; i < size; i++)
		{
			arr_new[i] = arr[i];
		}
		i = 0;
		for (; i < other.size; i++)
		{
			arr_new[i+size] = other.arr[i];
		}
	
	String concatenation(arr_new, size + other.size);

	return concatenation;
}
String& String::operator+=(String& const other)
{
	char* arr_new = new char[size];
	for (int i = 0; i < size; i++)
	{
		arr_new[i] = arr[i];
	}
	int length = size;
	size = length + other.size;
	arr = new char[size + other.size];
	int i = 0;
	for (; i < length; i++)
	{
		arr[i] = arr_new[i];
	}
	i = 0;
	for (; i < other.size; i++)
	{
		arr[i+length] = other.arr[i];
	}
	return *this;
}
bool String::operator==(String& const other) const
{
	if (size != other.size)
		return false;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != other.arr[i])
			return false;
	}
	return true;
}
std::istream& operator >>(std::istream& is, String& other)
{
	std::cout << "please enter length" << std::endl;
	int length; is >> length;
	other.size = length;
	other.arr = new char[length];
	for (int i = 0; i < length; i++)
	{
		is >> other.arr[i];
	}
	return is;
}
std::ostream& operator<<(std::ostream&  os, const String& other)
{
	for (int i = 0; i < other.size; i++)
	{
		os << other.arr[i];
	}
	return os;

}
String::~String()
{
	size = 0;
	delete arr;
}
int String::is_substring(String& const other) const
{

	if (size < other.size)
		return -1;
	if (other.size == 0)
		return -1;
	int i = 0;
	for (; i <= size-other.size; i++)
	{
		for (int j = 0; j < other.size; j++)
		{
			if (arr[i + j] != other.arr[j])
			{
				break;
			}
			if (arr[i + j] == other.arr[j] && j == other.size-1)
			{
				return i;
			}
		}
	}
	return -1;
}
bool String::substring(String& const other) const
{
	if (this->is_substring(other) == -1)
		return false;

	return true;
}
void String::change_substring(String& const poxvox,String& const poxenq)
{
	if (!this->substring(poxvox))
	{
		return;
	}
	int length = size - poxvox.size + poxenq.size;
	int length_0 = this->is_substring(poxvox);
	char* new_arr = new char[length];
	
	for ( int i =0; i < length_0; i++)
	{
		new_arr[i] = arr[i];
	}
	for (int i = 0; i < poxenq.size; i++)
	{
		new_arr[i+length_0]=poxenq.arr[i];

	}
	for (int i = poxenq.size+length_0; i < length; i++)
	{
		new_arr[i] = arr[i - poxenq.size +poxvox.size];
	}
	arr = new char[length];
	size = length;
	for (int i = 0; i < size; i++)
	{
		arr[i] = new_arr[i];
	}


}
String String::get_substring(const int index, const int length) const
{
	if (index + length <= size)
	{
		char* new_arr = new char[length];
		for (int i = 0; i < length; i++)
		{
			new_arr[i] = arr[index + i];
		}
		String a(new_arr, length);
		return a;
	}
	String a(nullptr, 0);
	return a;


}