#pragma once
#include "CLI11.hpp"
#include "VmManager.h"

class CLIParser {
public:
    CLIParser(int argc, char** argv, VmManager& manager) : argc_(argc), argv_(argv), manager_(manager){};
    int run();

    bool launch_cmd(CLI::App& app, VmConfig& config, CLI::App* launch);
    bool stop_cmd();
    bool list_cmd();

private:
    int argc_;
    char** argv_;
    VmManager& manager_;

};