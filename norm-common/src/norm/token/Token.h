#pragma once
#include <string>

namespace Norm {

class Token {
public:
    Token(Token* parent = nullptr);

    virtual std::string description() const = 0;
    Token* parent() const { return m_parent; }

private:
    Token* m_parent = nullptr;
};

}
