#pragma once
#include <cstdint>
#include "MemoryDataStructureTypes.h"
#include "MemoryDataStructure.h"
#include "Smart_Ptr.h"

// MemoryManager class that takes care of all memory allocations and deallocation through smart pointer
class MemoryManager
{
private:
	static MemoryManager* Instance;
	MemoryDataStructure* memDataStructure;
	MemoryDataStructureTypes memDataStructureType;
	static int poolSize;
	void* Allocate(uint32_t bytesToAllocate);
	bool Deallocate(void* address);
	template <typename T>
	friend class Smart_Ptr; // Smart_Ptr is friend to MemoryManager class and access its private functions Allocate and Deallocate
public:
	
	MemoryManager(MemoryDataStructureTypes memoryDataStructureType, uint32_t initialBytesToAllocate);
	MemoryManager(MemoryManager const&) = delete; // Restricting copy constructor to maintain singleton pattern
	void operator=(MemoryManager const&) = delete; // Restricting assignment operator to maintain singleton pattern
	~MemoryManager();
	static MemoryManager* getInstance(MemoryDataStructureTypes memoryDataStructureType, uint32_t initialBytesToAllocate);
	static MemoryManager* getInstance();
	static void SetPoolSize(int poolSize);

};