#pragma once
#include<iostream>
using namespace std;
template<class T>
class MyArray
{
public:
	MyArray(int capacity)
	{
		this->m_Capacity = capacity;
		this->m_size = 0;
		this->pAddress = new T[this->m_Capacity];
	}
	MyArray(const MyArray& arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < arr.m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}
	MyArray& operator=(const MyArray& arr)
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_size = arr.m_size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_size; i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}
	void Push_Back(const T& val)
	{
		if (this->m_size == this->m_Capacity)
		{
			return;
		}
		this->pAddress[this->m_size] = val;
		this->m_size++;
	}
	void Pop_Back()
	{
		if (this->m_size == 0)
		{
			return;
		}
		this->m_size--;
	}
	int get_size()
	{
		return this->m_size;
	}
	int get_capacity()
	{
		return this->m_Capacity;
	}
	T& operator[](int idex)
	{
		return this->pAddress[idex];
	}
	~MyArray()
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
private:
	T* pAddress;
	int m_Capacity;
	int m_size;
};