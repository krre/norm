#include "Identifier.h"

namespace Norm {

Identifier::Identifier(const std::string& name, Type* type) : m_name(name), m_type(type) {

}

std::string Identifier::description() const {
    return "Identifier";
}

}
