#pragma once
#include "norm/token/Token.h"
#include <string>
#include <vector>
#include <memory>

namespace Norm {

class Item;

class Target : public Token {
public:
    Target(const std::string& name);
    ~Target();

    const std::string& name() const { return m_name; }

    static Target* read(const std::string& filePath);
    void write(const std::string& filePath);

    void addItem(Item* item);

private:
    std::string m_name;
};

}
