#pragma once
#include <iostream>
#include <memory>
#include <utility>
#include <string>
#include <vector>

// Data needed for VM launch
struct VmConfig {
    std::string name;
    int cpu_cores{1};
    int ram_mb{2048};
    int disk_gb{10};
};

// What we need back about a VM
struct VmStatus {
    std::string id;
    std::string name;
    std::string state; // RUNNING | STOPPED
};

class IHypervisor {
public:
    // Virtual destructors needed anytime inheritence/polymorphism is involved
    virtual ~IHypervisor() = default;

    // virtual = allows for runtime polymorphism
    virtual bool launch_vm(const VmConfig& config) = 0; 
    virtual bool stop_vm(const std::string& vmName) = 0;     
    virtual bool list_vms(std::vector<VmStatus>& vms) = 0;
    virtual std::string get_type() const = 0;
};