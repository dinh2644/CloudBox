#pragma once
#include "CLI11.hpp"
#include "VmManager.h"

class CLIParser {
public:
    CLIParser(int argc, char** argv, VmManager& manager) : argc_(argc), argv_(argv), manager_(manager){};
    bool run();

private:
    int argc_;
    char** argv_;
    VmManager& manager_;

};