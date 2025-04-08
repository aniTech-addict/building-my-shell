#include <iostream>

bool run = true;

int main() {
  // Flush after every std::cout / std:cerr
  while(run){
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  std::cout << "$ ";


  std::string input;
  std::getline(std::cin, input);
  if(input == "exit 0") return 0;
  std::cout<<input<<": command not found"<<std::endl;
}
}
