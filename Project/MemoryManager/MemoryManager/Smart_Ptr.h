#pragma once
#include "ReferenceCount.h";
#include "MemoryManager.h"

// Class to represent Smart Pointer
template <typename T>
class Smart_Ptr
{
private:
	ReferenceCount* refCount;
	void* address;
public:
	Smart_Ptr() = delete;
	Smart_Ptr(T obj);
	Smart_Ptr(const Smart_Ptr<T>& other);
	Smart_Ptr<T>& operator= (const Smart_Ptr<T>& other);
	~Smart_Ptr();
	T& operator*();
	T* getValue();
	void setValue(T obj);
	void operator delete(void*);
};

