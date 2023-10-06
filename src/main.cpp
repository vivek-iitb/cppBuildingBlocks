#include "tests.hpp"


int main() {
  // Seed the random number generator with the current time
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
  std::cout<<"Main call\n";
 // linked_list_test();
  geom_test();
  return 0;
}
