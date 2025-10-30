#include "executor.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

void executeCommand(const std::vector<std::string>& tokens) {
    if (tokens.empty()) return;

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
