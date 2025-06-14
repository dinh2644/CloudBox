#pragma once
#include "IHypervisor.h"
#include <memory>
#include <string>
#include <vector>


class VmManager {
public:
    explicit VmManager(std::unique_ptr<IHypervisor> controller); // explicit = disables implicit type conversion

    // virtual = allows for polymorphism
    virtual bool launch_vm(const VmConfig& config); 
    virtual bool stop_vm(const std::string& vmName);     
    virtual bool list_vms(std::vector<VmStatus>& vms);
private:
    std::unique_ptr<IHypervisor> hypervisor_controller;
};


