
#include "Smart_Ptr.h"

// Constructor
template <typename T>
Smart_Ptr<T>::Smart_Ptr(T obj) : refCount{ new ReferenceCount() }
{

	address = MemoryManager::getInstance()->Allocate(sizeof(obj));
	if (address == nullptr)
		throw "There is no sufficient memory or pool size to allocate this";
	refCount->Increment();
	T* val = static_cast<T*>(address);
	(*val) = obj;
}

// Copy Constructor
template <typename T>
Smart_Ptr<T>::Smart_Ptr(const Smart_Ptr<T>& other) : address{ other.address }, refCount{ other.refCount }
{
	refCount->Increment();
}

// Overloaded Assignment operator
template <typename T>
Smart_Ptr<T>& Smart_Ptr<T>::operator= (const Smart_Ptr<T>& other)
{
	if (this != &other)
	{
		refCount->Decrement();
		if (refCount &&  refCount->GetCount() == 0)
		{
			MemoryManager::getInstance()->Deallocate(index);
			delete refCount;
			address = nullptr;
		}
		address = other.address;
		refCount = other.refCount;
		refCount->Increment();
	}

	return this*;
}

// Overloaded dereference operator
template <typename T>
T& Smart_Ptr<T>::operator*()
{
	if (address == nullptr)
		throw "Null Reference Exception";
	T value;
	T* val = static_cast<T*>(address);
	value = (*val);
	return value;
}

// Function to get value
template <typename T>
T* Smart_Ptr<T>::getValue()
{
	if (address == nullptr)
		throw "Null Reference Exception";
	T value;
	T* val = static_cast<T*>(address);
	value = (*val);
	return &value;
}

// Function to set value
template <typename T>
void Smart_Ptr<T>::setValue(T obj)
{
	if (address == nullptr)
		throw "Null Reference Exception";
	T value;
	T* val = static_cast<T*>(address);
	(*val) = obj;
}

// Destructor
template <typename T>
Smart_Ptr<T>::~Smart_Ptr()
{
	if (refCount != nullptr)
	{
		refCount->Decrement();
		if (refCount->GetCount() <= 0)
		{
			if (MemoryManager::getInstance()->Deallocate(address))
			{
				address = nullptr;
				delete refCount;
			}
			else
			{
				refCount->Increment();
			}
		}
	}
}

// Overloaded Delete operator
template <typename T>
void Smart_Ptr<T>::operator delete(void* addr)
{

}