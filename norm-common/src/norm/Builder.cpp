#include "Builder.h"
#include "token/Project.h"

namespace Norm {

Builder::Builder(const std::string& filePath) : m_filePath(filePath) {

}

Project* Builder::build() {
    return new Project("", Project::Type::Binary);
}

}
