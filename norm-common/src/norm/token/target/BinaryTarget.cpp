#include "BinaryTarget.h"
#include "norm/token/item/Function.h"

namespace Norm {

BinaryTarget::BinaryTarget(const std::string& name) : Target(name) {
    m_main = new Function("Main");
    addChild(m_main);
}

std::string BinaryTarget::description() const {
    return "Binary target";
}

}
