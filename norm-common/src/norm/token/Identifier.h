#pragma once
#include "Token.h"

namespace Norm {

class Type;

class Identifier : public Token  {
public:
    Identifier(const std::string& name, Type* type);

    const std::string& name() const { return m_name; }
    Type* type() const { return m_type; }

    Code code() const override { return Code::Identifier; }
    std::string description() const override;

private:
    std::string m_name;
    Type* m_type = nullptr;
};

}
