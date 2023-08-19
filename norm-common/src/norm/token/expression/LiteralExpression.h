#pragma once
#include "Expression.h"
#include "norm/token/type/Integer.h"

namespace Norm {

template <typename T>
class LiteralExpression : public Expression {
public:
    LiteralExpression(const std::string& literal) : m_literal(literal) {
        m_type = new T;
        addChild(m_type);
    }

    LiteralExpression() = default;

    const std::string& literal() const { return m_literal; }
    T* type() const  { return m_type; }

private:
    std::string m_literal;
    T* m_type = nullptr;
};

class IntegerLiteral : public LiteralExpression<Integer> {
public:
    IntegerLiteral(const std::string& literal) : LiteralExpression(literal) {}
    IntegerLiteral() = default;

    Code code() const override { return Code::IntegerLiteral; }
};

}
