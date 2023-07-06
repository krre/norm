#pragma once
#include "Token.h"
#include <string>

namespace Norm {

class Project : public Token {
public:
    Project(const std::string& name);

    const std::string& name() const { return m_name; }

private:
    std::string m_name;
};

}
