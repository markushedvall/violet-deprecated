#include <iostream>
#include <violet.h>

class PackageTest {
public:
  void launch() {
    std::cout << "Hello World!" << std::endl;
  }
};

VIOLET_APP(PackageTest)
