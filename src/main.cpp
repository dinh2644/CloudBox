#include <memory>
#include "VmManager.h"
#include "QemuController.h"
#include "HyperVController.h"
#include "CLIParser.h"


/*
TODO:


*/


int main(int argc, char** argv){
    // create hypervisor controller
    std::unique_ptr<IHypervisor> controller;

    // detect os
    #if defined(_WIN32)
        controller = std::make_unique<HyperVController>();
    #elif defined(__linux__)
        controller = std::make_unique<QemuController>();
    #elif defined(__APPLE__)
        controller = std::make_unique<QemuController>();
    #else
        controller = nullptr; 
    #endif
    if(controller == nullptr){
        std::cerr << "No compatible OS detected." << std::flush;
        return 0;
    }
    try
    {
        // setup vm manager and cli (& transfer controller to it)
        VmManager manager(std::move(controller)); 
        CLIParser cli(argc, argv, manager);
        return cli.run();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    
}

/*
notes:
the line: VmManager manager(std::move(qemu_controller));, here c++ following the "Most Vexing Parse" rule,
will see this as an object declaration due to the usage of args, otherwise c++ defaults to function declaration



*/