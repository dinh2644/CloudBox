#include "VmManager.h"

/*

VMs Orchestrator (Pass through layer (SRP))


To do later:
-logging
-validation (vm name check, etc)
-resource check (ram, etc)
-caching (listed vms)
*/

VmManager::VmManager(std::unique_ptr<IHypervisor> controller) : hypervisor_controller(std::move(controller)){
    if(!hypervisor_controller){
        throw std::runtime_error("hyper_controller cannot be null");
    }
}

bool VmManager::launch_vm(const VmConfig& config){
    std::cout << "Launched" << std::endl;
    return hypervisor_controller->launch_vm(config); 
}

bool VmManager::stop_vm(const std::string& vmName){
    std::cout << "Stopped" << std::endl;
    return hypervisor_controller->stop_vm(vmName); 
}

bool VmManager::list_vms(std::vector<VmStatus>& vms){
    std::cout << "List of VMs:" << std::endl;
    return hypervisor_controller->list_vms(vms); 

}

std::string VmManager::get_hypervisor_type() const{
    return hypervisor_controller->get_type();
}

IHypervisor* VmManager::get_controller() const{
    return hypervisor_controller.get();
}