#include "UMap.h"

int main()
{
	UMap* myUMap = CreateUMap(100);
	SetUMapValue(myUMap, "test1", 1);
	SetUMapValue(myUMap, "test2", 2);
	SetUMapValue(myUMap, "test3", 3);
	printf("1: %d", GetFromUMap(myUMap, "test1"));
	printf("2: %d", GetFromUMap(myUMap, "test2"));
	printf("3: %d", GetFromUMap(myUMap, "test3"));
	return 0;
}
