#pragma once
#include "IHypervisor.h"

class VmManager {
public:
    explicit VmManager(std::unique_ptr<IHypervisor> controller);   
    bool launch_vm(const VmConfig& config); 
    bool stop_vm(const std::string& vmName);     
    bool list_vms(std::vector<VmStatus>& vms);
    std::string get_hypervisor_type() const; 
    // IHypervisor* get_controller() const;
    void DisplayConfig(VmConfig& config);

private:
    std::unique_ptr<IHypervisor> hypervisor_controller; 
    std::string os;
};


/*
notes:

this is a 'has-a' class which manages hypervisors
explicit = disables implicit type conversion
virtual = allows for runtime polymorphism
careful w/ returning a unique_ptr type since it implies transferring ownership

*/

