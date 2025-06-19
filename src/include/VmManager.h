#pragma once
#include "IHypervisor.h"

// has-a (manages hypervisors)
class VmManager {
public:
    explicit VmManager(std::unique_ptr<IHypervisor> controller); // explicit = disables implicit type conversion

    // virtual = allows for runtime polymorphism
    bool launch_vm(const VmConfig& config); 
    bool stop_vm(const std::string& vmName);     
    bool list_vms(std::vector<VmStatus>& vms);
    std::string get_hypervisor_type() const; // The idea of const functions is not to allow them to modify the object on which they are called. It is recommended practice to make as many functions const as possible so that accidental changes to objects are avoided.
    IHypervisor* get_controller() const;

private:
    std::unique_ptr<IHypervisor> hypervisor_controller; // careful w/ returning a unique_ptr type since it implies transferring ownership?
};

