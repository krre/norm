#include "BinaryTarget.h"
#include "norm/token/item/Function.h"

namespace Norm {

BinaryTarget::BinaryTarget(const std::string& name) : Target(name) {
    m_main = std::make_unique<Function>("Main");
}

std::string BinaryTarget::description() const {
    return "Binary target";
}

}
