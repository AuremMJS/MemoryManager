#include <iostream>
#include "PoolMemoryDataStructure.h"
using namespace std;

// Constructor
PoolMemoryDataStructure::PoolMemoryDataStructure(uint32_t initialBytesToAllocate)
{
	memBlocks = (SBLOCK*)malloc(sizeof(SBLOCK) * initialBytesToAllocate);
	TotalBytesReserved = sizeof(SBLOCK) * initialBytesToAllocate;
}

// Allocates Memory
void* PoolMemoryDataStructure::AllocateMemory(bool& success, uint32_t bytesToAllocate)
{
	void* address = nullptr;
	if (IsMemoryFull())
	{
		// Check whether memory is full
		success = false;
		return address;
	}
	sizeOfEachBlock = TotalBytesReserved / poolSize;
	if (bytesToAllocate > sizeOfEachBlock) // If the memory requested is more than the size of each block, then allocation fails
		return address;

	if (index == -1)
	{
		int i = 0;
		while (i < poolSize)
		{
			insert(memBlocks + i * bytesToAllocate);
			i++;
		}
	}
	address = remove(); // Remove a node from the linked list
	index++;
	success = true;
	return address;
}

// Deallocates memory
bool PoolMemoryDataStructure::DeallocateMemory(void* address)
{
	insert(address); // Insert a node with this address to the linked list
	index--;
	return true;
}

// Checks whether memory is full
bool PoolMemoryDataStructure::IsMemoryFull()
{
	bool isFull = head == NULL && index!=-1;
	if (isFull)
		throw "Memory Full";
	return isFull;
}

// Clears all entries
bool PoolMemoryDataStructure::ClearAll()
{
	if (index == -1)
		return false;
	int i = poolSize - index - 1;
	while (i < poolSize)
	{
		insert(memBlocks + i * sizeOfEachBlock);
		i++;
		index--;
	}
	return true;
}

// Sets the poolsize
void PoolMemoryDataStructure::SetPoolSize(int mpoolSize)
{
	poolSize = mpoolSize;
}

// Inserts a node into the linked list
void PoolMemoryDataStructure::insert(void* new_data) {
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->Address = new_data;
	new_node->next = head;
	head = new_node;
}

// Removes a node from the linked list
void* PoolMemoryDataStructure::remove() {
	struct Node* new_head = head->next;
	void* address = head->Address;
	head->next = NULL;
	struct Node* temp = head;
	head = new_head;
	free(temp);
	return address;
}

// Destructor
PoolMemoryDataStructure::~PoolMemoryDataStructure()
{
	ClearAll();
	free(memBlocks);
}
