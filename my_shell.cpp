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

        if(input == "exit"){
            exit(0);
        }
    }

    return 0;
}