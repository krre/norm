#pragma once
#include "Token.h"
#include <string>

namespace Norm {

class Project : public Token {
public:
    enum class Type {
        Binary,
        Library
    };

    Project(const std::string& name, Type type);

    const std::string& name() const { return m_name; }
    Type type() const { return m_type; }

private:
    std::string m_name;
    Type m_type;
};

}
