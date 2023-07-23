#include "Target.h"
#include "norm/token/item/Item.h"

namespace Norm {

Target::Target(const std::string& name) : m_name(name) {

}

void Target::addItem(Item* item) {
    addChild(item);
}

}
