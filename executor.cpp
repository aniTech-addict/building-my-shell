#include "executor.h"

#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib> 
#include <vector>
#include <cstring>

using namespace std;

bool handleBuiltIn(const vector<string>& tokens) {
    if (tokens.empty()) return false;

    const string& cmd = tokens[0];

    if (cmd == "cd") {
        if (tokens.size() < 2) {
            cerr << "cd: missing argument\n";
            return true;
        }
        if (chdir(tokens[1].c_str()) != 0) {
            perror("cd");
        }
        return true;
    }

    if (cmd == "pwd") {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != nullptr) {
            cout << cwd << endl;
        } else {
            perror("pwd");
        }
        return true;
    }

    if (cmd == "help") {
        cout << "Built-in commands:\n"
             << "  cd <dir>   Change directory\n"
             << "  pwd        Print working directory\n"
             << "  exit       Quit shell\n"
             << "  help       Show this message\n";
        return true;
    }

    return false; // not a built-in
}
void executeCommand(const std::vector<std::string>& tokens) {
    if (tokens.empty()) return;

    if (handleBuiltIn(tokens)) return;
    // Convert vector<string> → vector<char*> for execvp
    std::vector<char*> args;
    for (auto& token : tokens) {
        args.push_back(const_cast<char*>(token.c_str()));
    }
    args.push_back(nullptr);

    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return;
    }

    if (pid == 0) {
        execvp(args[0], args.data());
        perror("execvp"); // Only runs if execvp fails
        exit(1);
    } else {
        int status;
        waitpid(pid, &status, 0);
    }
}
