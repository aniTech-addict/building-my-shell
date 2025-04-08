#include <iostream>
#include <string>
#include <map>

#include "type.hpp"

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
    if (!input.substr(0,5).compare("type ")) 
    {
        std::string command = input.substr(5,input.length());
        if (commands.find(command) != commands.end()) {
            std::cout << command << ": " << commands[command] << std::endl;
        } else {
            std::cout << command << ": command not found" << std::endl;
        }
    }

    else std::cout<<input<<": command not found"<<std::endl;
}
}
