#pragma once
#include <iostream>
#include "MemoryDataStructure.h"
#include "MemoryDataStructureTypes.h"

// Factory class to initialise MemoryDataStructure to handle memory allocations and deallocations
class MemoryDataStructureFactory
{
public:
	static MemoryDataStructure* GenerateMemoryDataStructure(MemoryDataStructureTypes memoryDataStructureType, uint32_t initialBytesToAllocate);
};

