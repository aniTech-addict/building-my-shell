#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>    // fork(), execvp()
#include <sys/wait.h>    // wait()
#include <sys/types.h>    // pid_t

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
        vector<string> tokens;
        stringstream ss(input);
        string token;
        while (ss >> token) {
            tokens.push_back(token);
        }

        vector<char*> args;
        for(auto& token : tokens){
            args.push_back(&token[0]);
        }
        args.push_back(nullptr);

        //child process
        pid_t pid = fork();

        if(pid < 0){
            perror("fork");
            exit(1);
        }

        if(pid == 0){
            execvp(args[0],args.data()); // if err , execvp would return -1 else nothing and we would just jump 
            cerr << "Command not found: " << args[0] << endl;
            exit(1); 
        }

        int status;
        waitpid(pid, &status, 0);


    }

    return 0;
}