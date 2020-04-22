#include <iostream>

#include "MemoryDataStructure.h"
using namespace std;

// Constructor
MemoryDataStructure::MemoryDataStructure()
{

}

// Constructor with parameter on initial bytes to allocate
MemoryDataStructure::MemoryDataStructure(uint32_t initialBytesToAllocate)
{

}

// Destructor
MemoryDataStructure::~MemoryDataStructure()
{

}

// Allocates Memory
void* MemoryDataStructure::AllocateMemory(bool& success, uint32_t bytesToAllocate)
{
	return nullptr;
}

// Deallocates Memory
bool MemoryDataStructure::DeallocateMemory(void* address)
{
	return true;
}

// Checks whether Memory is Full
bool MemoryDataStructure::IsMemoryFull()
{
	return false;
}

// Clears all entries
bool MemoryDataStructure::ClearAll()
{
	return true;
}