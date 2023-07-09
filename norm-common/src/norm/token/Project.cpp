#include "Project.h"
#include "Function.h"
#include <fstream>

namespace Norm {

Project::Project(const std::string& name, Type type) : m_name(name), m_type(type) {

}

Project::~Project() {
    for (auto func : m_functions) {
        delete func;
    }
}

Project* Project::read(const std::string& filePath) {
    return new Project("", Project::Type::Binary);
}

void Project::write(const std::string& filePath) {
    std::ofstream fs(filePath, std::ios::out | std::ios::binary | std::ios::app);
    int magic = 42;
    fs.write(reinterpret_cast<const char*>(&magic), sizeof magic);
    fs.close();
}

void Project::addFunction(Function* function) {
    m_functions.push_back(function);
}

void Project::setMain(Function* main) {
    m_main = main;
}

}
