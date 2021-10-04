#pragma 
#include "MemoryDataStructure.h"

using namespace std;

// Class to represent Stack Allocator
class StackMemoryDataStructure :
	public MemoryDataStructure
{
private:
	typedef void* SBLOCK; // Memory block
	SBLOCK* memBlocks;
	typedef uint32_t marker;
	marker m; // Marker
	marker Data[10000];
	int currentTopOfStack = -1;
public:
	StackMemoryDataStructure(uint32_t initialBytesToAllocate);
	~StackMemoryDataStructure();
	void* AllocateMemory(bool& success, uint32_t bytesToAllocate) override;
	bool DeallocateMemory(void* address) override;
	bool IsMemoryFull() override;
	bool ClearAll() override;
};

