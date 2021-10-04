
#include "ReferenceCount.h"

// Constructor
ReferenceCount::ReferenceCount()
{
}

// Destructor
ReferenceCount::~ReferenceCount()
{
}

// Increments reference count
void ReferenceCount::Increment()
{
	++mRefCount;
}

// Decrements reference count
void ReferenceCount::Decrement()
{
	--mRefCount;
}

// Gets the reference count
int ReferenceCount::GetCount()
{
	return mRefCount;
}