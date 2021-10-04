#include "DoubleStackMemoryDataStructure.h"


// Initialises a Double Ended Stack Memory Allocator
DoubleStackMemoryDataStructure::DoubleStackMemoryDataStructure(uint32_t initialBytesToAllocate)
{
	memBlocks = (SBLOCK*)malloc(sizeof(SBLOCK) * initialBytesToAllocate);
	mLeft = 0;
	mRight = 0;
	TotalBytesReserved = sizeof(SBLOCK) * initialBytesToAllocate;
}


// Allocates Memory from reserved Space
void* DoubleStackMemoryDataStructure::AllocateMemory(bool& success, uint32_t bytesToAllocate)
{
	void* address = nullptr;
	if (IsMemoryFull() || TotalBytesReserved < mLeft+bytesToAllocate || TotalBytesReserved - mRight < bytesToAllocate || mLeft - bytesToAllocate > TotalBytesReserved - mRight)
	{
		// Throw error if Memory is Full or memory requested exceeds total bytes reserved
		throw "Memory requirement exceeds the memory reserved";
		success = false;
		return address;
	}
	if (bytesToAllocate > 16)
	{
		// Allocate Memory in Left End of Stack if the memory requirement is greater than 16 bytes
		address = memBlocks + mLeft;
		currentLeftOfStack++; // Update the current Left of Stack
		mLeft += bytesToAllocate; // Left Marker is moved
		LeftData[currentLeftOfStack] = bytesToAllocate;
		success = true;
		return address;
	}
	else
	{
		// Allocate Memory in Right End of Stack if the memory requirement is less than 16 bytes
		address = (memBlocks + TotalBytesReserved) - mRight- bytesToAllocate;
		currentRightOfStack++; // Update the current Right of Stack
		mRight += bytesToAllocate; // Right Markeris moved
		RightData[currentRightOfStack] = bytesToAllocate;
		success = true;
		return address;
	}


}

// Deallocate Memory from reserved memory
bool DoubleStackMemoryDataStructure::DeallocateMemory(void* address)
{
	bool isDeallocationDirLeft; // Checks whether deallocation has to be done from left-end or right-end
	if (address == memBlocks + mLeft - LeftData[currentLeftOfStack] )
	{
		// Dealllocate from Left End if the address in the Left End matches the address requested to be deallocated
		isDeallocationDirLeft = true;
	}
	else if (address == memBlocks + TotalBytesReserved - mRight)
	{
		// Deallocate from Right End if the address in the Right End matches the address requested to be deallocated
		isDeallocationDirLeft = false;
	}
	else
	{
		// Addresses in the both the ends does not match with the requested address, so deallocating fails
		return false;
	}
	if (isDeallocationDirLeft)
	{
		// Deallocation from Left
		if (currentLeftOfStack < 0)
			return false;
		mLeft -= LeftData[currentLeftOfStack];
		currentLeftOfStack--; // Update current Left of Stack
		return true;
	}
	else
	{
		// Deallocation from Right
		if (currentRightOfStack < 0)
			return false;
		mRight -= RightData[currentRightOfStack];
		currentRightOfStack--; // Update current Right of Stack
		return true;
	}
}

// Checks whether Memory is Full
bool DoubleStackMemoryDataStructure::IsMemoryFull()
{
	bool isFull = currentLeftOfStack > 4998 || currentRightOfStack > 4998 || mLeft >= TotalBytesReserved || mRight >= TotalBytesReserved || mLeft >= TotalBytesReserved - mRight;
	if (isFull)
		throw "Memory Full!"; // Throw exception if the memory is full
	return isFull;
}

// Clears all entries
bool DoubleStackMemoryDataStructure::ClearAll()
{
	mLeft = 0;
	currentLeftOfStack = -1;
	mRight = 0;
	currentRightOfStack = -1;
	return true;
}

// Destructs a Double Ended Stack Memory Allocator
DoubleStackMemoryDataStructure::~DoubleStackMemoryDataStructure()
{
	ClearAll();
	free(memBlocks);
}
