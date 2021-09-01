#include <iostream>
#include <string>
#include <cmath>

// this header file gen by CMakeLists::configure_file(helloWorld.h.in src/helloWorld.h)
#include "helloWorld.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Welcome to CMake!" << endl;
	
	cout << argv[0] << " Version:" << helloWorld_VERSION_MAJOR << "." << helloWorld_VERSION_MINOR << endl;
	
	cout << "Hello, World!" << endl;
	
	
	if(argc < 2)
	{
		cout << "Usage: " << argv[0] << " Number" << endl;
		//return -1;
		cout << "输入一个数字用于求它的平方根:" << endl;
		string inputValue;
		cin >> inputValue;
		const double input = std::stod(inputValue);
		const double output = sqrt(input);
		cout << "The square root of " << input << " is " << output << endl;
	}
	else
	{
		const double input = std::stod(argv[1]);
		const double output = sqrt(input);
		cout << "The square root of " << input << " is " << output << endl;
	}
	
	return 0;
}