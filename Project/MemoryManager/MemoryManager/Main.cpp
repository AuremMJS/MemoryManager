#include <iostream>
#include "MemoryManager.h"
#include "Smart_Ptr.cpp"
class cat
{

public:
	char* name;
	cat()
	{
		name = "Cat";
	}
	void setname(char* newname)
	{
		name = newname;
	}
};
int main()
{
	MemoryDataStructureTypes memDSType;
	uint32_t bytesToAllocate;
	char byteUnits;
	int memchoice;
	std::cout << std::endl << "Enter the type of mem manager!\n1. Stack\n2. Double Stack\n3. Pool";
	std::cin >> memchoice;
	switch (memchoice)
	{
	case 1:
		memDSType = MemoryDataStructureTypes::Stack;
		break;
	case 2:
		memDSType = MemoryDataStructureTypes::DoubleStack;
		break;
	case 3:
		memDSType = MemoryDataStructureTypes::Pool;
		break;
	default:
		memDSType = MemoryDataStructureTypes::Stack;
		break;
	}
	std::cout << std::endl << std::endl << "Enter the amount of memory to allocate";
	std::cin >> bytesToAllocate;
	std::cout << std::endl << std::endl << "Units:\nB:Bytes\nK:KB\nM:MB\nG:GB";
	std::cin >> byteUnits;
	switch (byteUnits)
	{
	case 'K':
		bytesToAllocate *= 256;
		break;
	case 'k':
		bytesToAllocate *= 256;
		break;
	case 'M':
		bytesToAllocate *= 1024 * 256;
		break;
	case 'm':
		bytesToAllocate *= 1024 * 256;
		break;
	case 'G':
		bytesToAllocate *= 1024 * 1024 * 256;
		break;
	case 'g':
		bytesToAllocate *= 1024 * 1024 * 256;
		break;
	default:
		bytesToAllocate /= 4;
		break;
	}
	MemoryManager::SetPoolSize(10);
	MemoryManager* m = MemoryManager::getInstance(memDSType, bytesToAllocate);


	{
		Smart_Ptr<int> s2(5);
		Smart_Ptr<int> s3(50);
		s2.setValue(6);
		int z = *s2;
		delete &s2;
		std::cout << std::endl << "z value" << *s2;
	}
	cat Fi;
	Smart_Ptr<cat> c(Fi);
	std::cout << c.getValue()->name;

}
