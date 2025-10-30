#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <vector>
#include <string>

bool handleBuiltIn(const std::vector<std::string>& tokens);
void executeCommand(const std::vector<std::string>& tokens);

#endif
