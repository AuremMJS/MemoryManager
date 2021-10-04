#pragma once

// Class to represent the reference count
class ReferenceCount
{
private:
	int mRefCount = 0; // Reference count
public:
	ReferenceCount();
	~ReferenceCount();
	void Increment();
	void Decrement();
	int GetCount();
};

