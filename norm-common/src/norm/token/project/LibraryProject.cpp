#include "LibraryProject.h"

namespace Norm {

LibraryProject::LibraryProject(const std::string& name) : Project(name) {
}

std::string LibraryProject::description() const {
    return "Library project";
}

}
