#pragma once
#include "Expression.h"

namespace Norm {

class LiteralExpression : public Expression {
public:
    LiteralExpression();
};

class IntegerLiteral : private LiteralExpression {
public:
    IntegerLiteral(int literal) : m_literal(literal) {}
    int literal() const { return m_literal; }

private:
    int m_literal = 0;
};

}
