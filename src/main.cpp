#include "VmManager.h"
#include "QemuController.h"
#include <memory>

int main(){
    auto qemu_controller = std::make_unique<QemuController>();
    VmManager manager(std::move(qemu_controller));

    VmConfig config;
    config.name = "Linux";

    std::cout << manager.get_controller()->launch_vm(config) << std::endl;
    return 0;
}
