#pragma once
#include "norm/token/Token.h"
#include <string>

namespace Norm {

class Item;

class Target : public Token {
public:
    Target(const std::string& name);
    Target() = default;

    const std::string& name() const { return m_name; }
    void setName(const std::string& name) { m_name = name; }

    void addItem(Item* item);

private:
    std::string m_name;
};

}
