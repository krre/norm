#pragma once
#include "Token.h"

namespace Norm {

class Type;

class Identifier : public Token  {
public:
    Identifier(const std::string& name, Type* type);
    Identifier() = default;

    const std::string& name() const { return m_name; }
    void setName(const std::string& name) { m_name = name; }

    Type* type() const { return m_type; }

    Code code() const override { return Code::Identifier; }

private:
    std::string m_name;
    Type* m_type = nullptr;
};

}
