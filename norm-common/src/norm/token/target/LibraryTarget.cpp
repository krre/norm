#include "LibraryTarget.h"

namespace Norm {

LibraryTarget::LibraryTarget(const std::string& name) : Target(name) {
}

std::string LibraryTarget::description() const {
    return "Library target";
}

}
