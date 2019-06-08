#include <iostream>
#include <violet.h>

using violet::App;

class PackageTest {
public:
  void launch() {
    std::cout << "Hello World!" << std::endl;
    std::cout << App::info().name() << std::endl;
  }
};

VIOLET_APP(PackageTest, "PackageTest App")
