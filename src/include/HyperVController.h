#include "IHypervisor.h"

// is-a (specific Hypervisor)
class HyperVController: public IHypervisor {
public:
    bool launch_vm(const VmConfig& config) override;
    bool stop_vm(const std::string& vm_name) override;
    bool list_vms(std::vector<VmStatus>& vms) override;
    // std::string get_type() const override;
};
