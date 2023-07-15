#pragma once
#include "Expression.h"
#include <vector>
#include <memory>

namespace Norm {

class OperatorExpression : public Expression {
public:
    OperatorExpression();

    void addExpression(std::unique_ptr<Expression> expression);
    const std::vector<std::unique_ptr<Expression>>& expressions() const { return m_expressions; }

private:
    std::vector<std::unique_ptr<Expression>> m_expressions;
};

class SumOperator : public OperatorExpression {
public:
    SumOperator() {}

    std::string description() const override;
};

}
