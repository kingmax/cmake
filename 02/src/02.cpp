// https://gitlab.kitware.com/cmake/cmake/-/blob/master/Help/guide/tutorial/Step3/tutorial.cxx

// A simple program that computes the square root of a number
#include <cmath>
#include <iostream>
#include <string>

#include "TutorialConfig.h"

// should we include the MathFunctions header?
#ifdef USE_MYMATH
#  include "MathFunctions.h"
#endif

int main(int argc, char* argv[])
{
  if (argc < 2) {
    // report version
    std::cout << argv[0] << " Version " << Step2_VERSION_MAJOR << "."
              << Step2_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " number" << std::endl;
    return 1;
  }

  // convert input to double
  const double inputValue = std::stod(argv[1]);

  // which square root function should we use?
#ifdef USE_MYMATH
	std::cout << "use mysqrt" << std::endl;
  const double outputValue = mysqrt(inputValue);
#else
	std::cout << "use sqrt" << std::endl;
  const double outputValue = sqrt(inputValue);
#endif

  std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
  return 0;
}
