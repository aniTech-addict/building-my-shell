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
    if (!input.compare("exit 0")) return 0;
    if (!input.substr(0,5).compare("echo ")) std::cout << input.substr(5,input.length())<<std::endl;

    std::cout<<input<<": command not found"<<std::endl;
}
}
