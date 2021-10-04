#include "StackMemoryDataStructure.h"
#include "MemoryDataStructure.h"
#include <iostream>

using namespace std;

// Constructor
StackMemoryDataStructure::StackMemoryDataStructure(uint32_t initialBytesToAllocate)
{
	memBlocks =(SBLOCK*) malloc(sizeof(SBLOCK) * initialBytesToAllocate);
	m = 0;
	TotalBytesReserved = sizeof(SBLOCK) * initialBytesToAllocate;
}

// Allocates memory
void* StackMemoryDataStructure::AllocateMemory(bool& success, uint32_t bytesToAllocate)
{
	void* address = nullptr;
	if (IsMemoryFull() || TotalBytesReserved < m+bytesToAllocate)
	{
		success = false;
		return address;
	}
	address = memBlocks + m;
	currentTopOfStack++; // Update current top of stack
	m += bytesToAllocate; // Update marker
	Data[currentTopOfStack] = bytesToAllocate;
	success = true;
	return address;
}

// Deallocates memory
bool StackMemoryDataStructure::DeallocateMemory(void* address)
{
	if (address != memBlocks + m - Data[currentTopOfStack])
	{
		return false;
	}
	if (currentTopOfStack < 0)
		return false;
	m -= Data[currentTopOfStack]; // Update Marker
	currentTopOfStack--; // Update current Top of Stack
	return true;
}

// Checks whether Memory is Full
bool StackMemoryDataStructure::IsMemoryFull()
{
	bool isFull = currentTopOfStack > 9998 || m >= TotalBytesReserved;
	if (isFull)
		throw "Memory Full";
	return isFull;
}

// Clears all entries
bool StackMemoryDataStructure::ClearAll()
{
	m = 0;
	currentTopOfStack = -1;
	return true;
}


// Destructor
StackMemoryDataStructure::~StackMemoryDataStructure()
{
	ClearAll();
	free(memBlocks);
}