
#include "MemoryDataStructureFactory.h"
#include "MemoryDataStructureTypes.h"
#include "MemoryDataStructure.h"
#include "StackMemoryDataStructure.h"
#include "DoubleStackMemoryDataStructure.h"
#include "PoolMemoryDataStructure.h"

// function to initialise the Memory Data Structure based on the type - Stack, Double ended Stack or Pool
MemoryDataStructure* MemoryDataStructureFactory::GenerateMemoryDataStructure(MemoryDataStructureTypes memoryDataStructureType,uint32_t initialBytesToAllocate)
{
	if (memoryDataStructureType == Stack)
	{
		return new StackMemoryDataStructure(initialBytesToAllocate);
	}
	else if (memoryDataStructureType == DoubleStack)
	{
		return new DoubleStackMemoryDataStructure(initialBytesToAllocate);
	}
	else if (memoryDataStructureType == Pool)
	{
		return new PoolMemoryDataStructure(initialBytesToAllocate);
	}
	return nullptr;
}