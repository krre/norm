#pragma once
#include "norm/token/Token.h"

namespace Norm {

class Type;

class Expression : public Token {
public:
    Expression();

    void setResult(Type* result);
    Type* result() const { return m_result; }

private:
    Type* m_result = nullptr;
};

}
