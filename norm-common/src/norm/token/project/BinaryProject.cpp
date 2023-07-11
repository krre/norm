#include "BinaryProject.h"
#include "norm/token/item/Function.h"

namespace Norm {

BinaryProject::BinaryProject(const std::string& name) : Project(name) {
    m_main = std::make_unique<Function>("Main");
}

std::string BinaryProject::description() const {
    return "Binary project";
}

}
