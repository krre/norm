#pragma once
#include "norm/token/Token.h"

namespace Norm {

class Type : public Token {
public:
    Type(const std::string& name);

private:
    std::string m_name;
};

}
