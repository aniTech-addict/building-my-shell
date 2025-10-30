#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>    // fork(), execvp()
#include <sys/wait.h>    // wait()
#include <sys/types.h>    // pid_t

// user defined header files
#include "parser.h" 

using namespace std;

int main(){

    string input;

    while(true){
        cout<<"my_shell> ";
        getline(cin, input);

        // Special commands
        if(input.empty()) continue;
        if(input == "exit") exit(0);


        // parsing input into tokens
        std::vector<std::string> args = parseInput(input);

        vector<char*> args;
        for(auto& token : tokens){ // execvp expects char* thus conversion from string to char* [l][s][][-][l][null]
            args.push_back(&token[0]);
        }
        args.push_back(nullptr); // acts as ending marker

        //child process
        pid_t pid = fork(); // create a duplicate instance of the parent(shell) same memory/variables etc

        if(pid < 0){ // -1 when creation of child process fails, thus process id returned is -1
            perror("fork");
            exit(1);
        }

        if(pid == 0){ // 0 represents child  process while parent would have a +ve process id
            execvp(args[0],args.data()); // if err , execvp would return -1 else nothing and we would just jump 
            cerr << "Command not found: " << args[0] << endl;
            exit(1);  // exe only when fails in execvp
        } 
        else{
            int status;
            waitpid(pid, &status, 0); // awaits the end of the child process and status holds the exit code of child
        }

    }

    return 0;
}