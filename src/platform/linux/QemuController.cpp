#include "QemuController.h"


bool QemuController::launch_vm(const VmConfig& config){
    std::cout << "Checkpoint 1 - Launched!" << "\n";
    return true;
}
bool QemuController::stop_vm(const std::string& vm_name){return true;}
bool QemuController::list_vms(std::vector<VmStatus>& vms){return true;}
std::string QemuController::get_type() const {return "(Linux) QEMU";}
