// MemoryManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include "MemoryManager.h"
#include "MemoryDataStructureTypes.h"
#include "MemoryDataStructureFactory.h"
#include "StackMemoryDataStructure.h"
#include "PoolMemoryDataStructure.h"
#include "DoubleStackMemoryDataStructure.h"
#include "Smart_Ptr.h"
#include "Smart_Ptr.cpp"

using namespace std;

// Static variable to represent the Instance in Singleton pattern
MemoryManager *MemoryManager::Instance = 0;

// Pool Size to specify the number of memory blocks to be allocated in PoolMemoryDataStructure. This variable is insignificant in Stack and Double Stack
int MemoryManager::poolSize = 100;

// Constructor
MemoryManager::MemoryManager(MemoryDataStructureTypes memoryDataStructureType, uint32_t initialBytesToAllocate)
{
		if (initialBytesToAllocate < 1)
		{
			// Throw exception if the memory requested to pre allocate is zero or negative
			throw "Memory Manager cannot allocate a memory less than 1";
			exit(-1);
		}
		memDataStructure = MemoryDataStructureFactory::GenerateMemoryDataStructure(memoryDataStructureType, initialBytesToAllocate);
		memDataStructureType = memoryDataStructureType;
		if (memDataStructureType == MemoryDataStructureTypes::Pool)
			((PoolMemoryDataStructure *)memDataStructure)->SetPoolSize(MemoryManager::poolSize);
}

// Static function to fetch Singleton Instance.
MemoryManager* MemoryManager::getInstance(MemoryDataStructureTypes memoryDataStructureType, uint32_t initialBytesToAllocate)
{
	if (!MemoryManager::Instance)
		MemoryManager::Instance = new MemoryManager(memoryDataStructureType, initialBytesToAllocate); // Create an instance if it is not available
	return MemoryManager::Instance;
}

// Static function to fetch Singleton Instance.
MemoryManager* MemoryManager::getInstance()
{
	if (!MemoryManager::Instance)
		MemoryManager::Instance = new MemoryManager(MemoryDataStructureTypes::Stack, 100 * 1024 * 256); // Default Memory Manager has type Stack and 100 MB memory
	return MemoryManager::Instance;
}

// Static function to set pool size for PoolMemoryDataStructure
void MemoryManager::SetPoolSize(int poolSize)
{
	MemoryManager::poolSize = poolSize;
}

// Function to allocate memory to a smart pointer
void* MemoryManager::Allocate(uint32_t bytesToAllocate)
{
	void* address;
	bool success = false;
	address = memDataStructure->AllocateMemory(success, bytesToAllocate);
	if (address == NULL)
		return nullptr;
	return address;
}

// Function to deallocate memory for a smart pointer
bool MemoryManager::Deallocate(void* address)
{
		if (address == NULL)
			return false;
	return memDataStructure->DeallocateMemory(address);
}

// Destructor
MemoryManager::~MemoryManager()
{
	if (memDataStructureType == MemoryDataStructureTypes::Stack)
		delete (StackMemoryDataStructure *)memDataStructure;
	else if (memDataStructureType == MemoryDataStructureTypes::DoubleStack)
		delete (DoubleStackMemoryDataStructure *)memDataStructure;
	else if (memDataStructureType == MemoryDataStructureTypes::Pool)
		delete (PoolMemoryDataStructure *)memDataStructure;
}