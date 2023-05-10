#pragma once
#include<iostream>
class String 
{
public:
	String();
	String(const char* arr, const int size);
	String(const String& other);
	~String();
	String& operator=(String& const other);
	String& operator=(String const other);
	char& operator[](const int index);
	friend std::istream& operator>>(std::istream&  is, String& other);
	friend std::ostream& operator<<(std::ostream& os, const String& other);
	String operator+(String const& other) const;
	String& operator+=(String& const other);
	bool operator==(String& const other) const;
	int get_size() { return size; }
	bool substring(String& const other) const;
	void change_substring(String& const other,String& const others);
	String get_substring(const int index,const int length) const;

private:
	char* arr;
	int size;
	int is_substring(String& const other) const;
};