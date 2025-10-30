#include <iostream>
#include <string>

// ------------USER DEFINED LIBRARIES -----------//

#include "parser.h"      // handles token genration 
#include "executor.h"    //handles creating child and parent processes

// ************USER-DEFINED-LIBRARIES-END**********

using namespace std;

int main(){

    string input;

    while(true){
        cout<<"my_shell> ";
        getline(cin, input);

        // Special commands
        if(input.empty()) continue;
        if(input == "exit") exit(0);
        
        auto tokens = parseInput(input);

        executeCommand(tokens);
    }

    return 0;
}