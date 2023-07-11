#include "Project.h"
#include "BinaryProject.h"
#include "norm/token/item/Item.h"
#include <fstream>

namespace Norm {

Project::Project(const std::string& name) : m_name(name) {

}

Project::~Project() {

}

Project* Project::read(const std::string& filePath) {
    return new BinaryProject("");
}

void Project::write(const std::string& filePath) {
    std::ofstream fs(filePath, std::ios::out | std::ios::binary | std::ios::app);
    int magic = 42;
    fs.write(reinterpret_cast<const char*>(&magic), sizeof magic);
    fs.close();
}

void Project::addItem(std::unique_ptr<Item> item) {
    m_items.push_back(std::move(item));
}

}
