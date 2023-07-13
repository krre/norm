#pragma once
#include "Expression.h"

namespace Norm {

class Integer;

class LiteralExpression : public Expression {
public:
    LiteralExpression(const std::string& literal);
    const std::string& literal() const { return m_literal; }

private:
    std::string m_literal;
};

class IntegerLiteral : private LiteralExpression {
public:
    IntegerLiteral(const std::string& literal) : LiteralExpression(literal) {}
};

}
