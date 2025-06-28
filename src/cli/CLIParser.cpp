#include "CLIParser.h"
#include <string>
#include <typeinfo>


int CLIParser::run(){
    VmConfig config;

    // [Init app]
    CLI::App app{"CloudBox, a lightweight crossplatform vm manager"};
    app.require_subcommand(1);
    auto launch = app.add_subcommand("launch", "Launch a new VM instance");
    auto stop = app.add_subcommand("stop", "Terminate a VM");
    auto list = app.add_subcommand("list", "Display all running VMs");

    // Check command type
    if(std::string(argv_[1]) == "launch"){
        launch_cmd(app, config, launch);
    }

    return 0;
} 

/*
To do:
-vaildate for negative inputs
*/
bool CLIParser::launch_cmd(CLI::App& app, VmConfig& config, CLI::App* launch){
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
    // [Parse]
    CLI11_PARSE(app, argc_, argv_);

    manager_.DisplayConfig(config);
    return true;
}
bool CLIParser::stop_cmd(){return true;}
bool CLIParser::list_cmd(){return true;}