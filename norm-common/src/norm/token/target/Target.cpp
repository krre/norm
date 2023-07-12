#include "Target.h"
#include "BinaryTarget.h"
#include "norm/token/item/Item.h"
#include <fstream>

namespace Norm {

Target::Target(const std::string& name) : m_name(name) {

}

Target::~Target() {

}

Target* Target::read(const std::string& filePath) {
    return new BinaryTarget("");
}

void Target::write(const std::string& filePath) {
    std::ofstream fs(filePath, std::ios::out | std::ios::binary | std::ios::app);
    int magic = 42;
    fs.write(reinterpret_cast<const char*>(&magic), sizeof magic);
    fs.close();
}

void Target::addItem(std::unique_ptr<Item> item) {
    m_items.push_back(std::move(item));
}

}
