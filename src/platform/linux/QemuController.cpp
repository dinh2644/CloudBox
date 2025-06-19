#include "QemuController.h"


bool QemuController::launch_vm(const VmConfig& config){
    std::cout << "Name: " <<  config.name << "\n"; 
    std::cout << "Cores: " <<  config.cpu_cores << "\n"; 
    std::cout << "Ram: " <<  config.ram_mb << "\n"; 
    std::cout << "Disk: " <<  config.disk_gb << "\n"; 
    return true;
}
bool QemuController::stop_vm(const std::string& vm_name){return true;}
bool QemuController::list_vms(std::vector<VmStatus>& vms){return true;}
std::string QemuController::get_type() const {return "(Linux) QEMU";}
