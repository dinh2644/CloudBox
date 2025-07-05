#include "CLIParser.h"
#include <string>
#include <typeinfo>

CLIParser::CLIParser(int argc, char** argv, VmManager& manager) 
    : app("CloudBox"),
      argc_(argc),
      argv_(argv),
      manager_(manager)
    {
        setup_launch();
        setup_stop();
        setup_list();
    // auto stop = app.add_subcommand("stop", "Terminate a VM");
    // auto list = app.add_subcommand("list", "Display all running VMs");
};

int CLIParser::run(){

    try
    {
        app.parse(argc_, argv_);
    }
    catch(CLI::ParseError& e)
    {
        return app.exit(e);
    }
       
    return 0;
} 

/*
To do:
-vaildate for negative inputs
*/
void CLIParser::setup_launch(){
    VmConfig config;
    app.require_subcommand(1);
    auto launch = app.add_subcommand("launch", "Launch a new VM instance");

    // [Launch]
    std::string cnfg_name;
    std::uint32_t cnfg_cpu{2};
    std::uint32_t cnfg_ram{2000};
    std::uint32_t cnfg_disk{10};
    launch->add_option("--name", cnfg_name, "Set VM name")->required();
    launch->add_option("--cpu", cnfg_cpu, "Set CPU cores (Default: 2 vCPU)");
    launch->add_option("--ram", cnfg_ram, "Set ram (Default: 2GB)");
    launch->add_option("--disk", cnfg_disk, "(Default: 10GB)");

    launch->callback([&]() { 
        config.name = cnfg_name;
        config.cpu_cores = cnfg_cpu;
        config.ram = cnfg_ram;
        config.disk =  cnfg_disk;
    
        manager_.launch_vm(config);
    });

}