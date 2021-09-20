#include <iostream>
#include "shared/hello.h"

void Hello::print()
{
	std::cout << "Hello, Shared Library! (DLL)" << std::endl;
}