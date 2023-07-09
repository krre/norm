#pragma once
#include "Token.h"
#include <string>

namespace Norm {

class Function : public Token {
public:
    Function(const std::string& name);

private:
    std::string m_name;
};

}
