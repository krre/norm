#include "Project.h"

namespace Norm {

Project::Project(const std::string& name, Type type) : m_name(name), m_type(type) {

}

Project* Project::read(const std::string& filePath) {
    return new Project("", Project::Type::Binary);
}

}
