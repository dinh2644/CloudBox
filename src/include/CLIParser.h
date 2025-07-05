#pragma once
#include "CLI11.hpp"
#include "VmManager.h"

class CLIParser {
public:
    CLIParser(int argc, char** argv, VmManager& manager);
    int run();

    
private:
    void setup_launch();
    void setup_stop();
    void setup_list();
    CLI::App app;
    int argc_;
    char** argv_;
    VmManager& manager_;

};