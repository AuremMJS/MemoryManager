#pragma once
#include "MemoryDataStructure.h"
#include <iostream>

// Class to represent the Pool Allocator
class PoolMemoryDataStructure :
	public MemoryDataStructure
{
private:
	typedef void* SBLOCK; // A Memory Block
	typedef uint32_t marker;

	// A node to represent the free memory block in the linked list
	struct  Node
	{
		void* Address;
		struct Node* next;
	};

	SBLOCK* memBlocks;
	int index = -1;
	uint32_t sizeOfEachBlock;
	int poolSize; // Number of memory blocks

	struct Node* head = NULL; // Represents the head of the linked list
	void insert(void* new_data);
	void* remove();

public:
	PoolMemoryDataStructure(uint32_t initialBytesToAllocate);
	~PoolMemoryDataStructure();
	void* AllocateMemory(bool& success, uint32_t bytesToAllocate = 0) override;
	bool DeallocateMemory(void* address) override;
	bool IsMemoryFull() override;
	bool ClearAll() override;
	void SetPoolSize(int poolSize);
};

