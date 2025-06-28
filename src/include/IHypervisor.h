#pragma once
#include <iostream>
#include <memory>
#include <utility>
#include <string>
#include <vector>

// #if defined(_WIN32)
// #define PLATFORM_NAME "windows"
// #elif defined(__linux__)
// #define PLATFORM_NAME "linux"
// #elif defined(__APPLE__)
// #define PLATFORM_NAME "darwin"
// #else
// #define PLATFORM_NAME "null"
// #endif

struct VmConfig {
    std::string name;
    int cpu_cores;
    int ram;
    int disk;
};

struct VmStatus {
    std::string id;
    std::string name;
    std::string state; // RUNNING | STOPPED
};

class IHypervisor {
public:
    virtual ~IHypervisor() = default;

    // virtual = allows for runtime polymorphism
    virtual bool launch_vm(const VmConfig& config) = 0; 
    virtual bool stop_vm(const std::string& vmName) = 0;     
    virtual bool list_vms(std::vector<VmStatus>& vms) = 0;
    virtual std::string get_type() const = 0;
};

/*
notes:

VmConfig = data required to launch vm (depends on hypervisors)
VmStatus = info we need about a VM
virtual = allows for runtime polymorphism
destructor must require virtual keyword anytime inheritence/polymorphism is involved

*/

