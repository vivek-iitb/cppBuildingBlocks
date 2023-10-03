#include "tests.hpp"

//--templates: https://isocpp.org/wiki/faq/templates
//--compiler: https://stackoverflow.com/questions/24836183/what-is-the-difference-between-clang-and-llvm-and-gcc-g
//--https://stackoverflow.com/questions/2351148/explicit-template-instantiation-when-is-it-used
//--Your compiler probably doesn’t remember the details of one .cpp file while it is compiling another .cpp file. It could, but most do not and if you are reading this FAQ, it almost definitely does not. BTW this is called the “separate compilation model.”

int main() {
  // Seed the random number generator with the current time
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  std::cout<<"Main call\n";
 // linked_list_test();
  geom_test();
  return 0;
}
