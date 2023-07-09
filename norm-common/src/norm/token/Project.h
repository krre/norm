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

    static Project* read(const std::string& filePath);

private:
    std::string m_name;
    Type m_type;
};

}
