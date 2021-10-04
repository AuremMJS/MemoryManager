#pragma once
#include <iostream>
#include "MemoryDataStructure.h"

// Double Ended Stack Memory Allocator
class DoubleStackMemoryDataStructure :
	public MemoryDataStructure
{
private:
	typedef void* SBLOCK; // Represents a Memory Block
	SBLOCK* memBlocks;
	typedef uint32_t marker; // Marker
	marker mLeft; // Left Marker
	marker mRight; // Right Marker
	marker LeftData[5000];
	marker RightData[5000];
	int currentLeftOfStack = -1;
	int currentRightOfStack = -1;
public:
	DoubleStackMemoryDataStructure(uint32_t initialBytesToAllocate);
	~DoubleStackMemoryDataStructure();
	void* AllocateMemory(bool &success, uint32_t bytesToAllocate) override;
	bool DeallocateMemory(void* address) override;
	bool IsMemoryFull() override;
	bool ClearAll() override;
};

