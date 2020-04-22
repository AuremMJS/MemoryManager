#pragma once
#include <iostream>

// Parent class  to represent Stack, Double ended stack and pool allocators
class MemoryDataStructure
{
protected:
	uint32_t TotalBytesReserved; // Total Bytes pre-allocated in memory
public:
	MemoryDataStructure();
	MemoryDataStructure(uint32_t initialBytesToAllocate);
	~MemoryDataStructure();
	virtual void* AllocateMemory(bool& success, uint32_t bytesToAllocate);
	virtual bool DeallocateMemory(void* address);
	virtual bool IsMemoryFull();
	virtual bool ClearAll();
}; 
