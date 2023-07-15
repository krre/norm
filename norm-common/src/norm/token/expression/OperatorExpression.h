#pragma once
#include "Expression.h"
#include <vector>
#include <memory>

namespace Norm {

class OperatorExpression : public Expression {
public:
    OperatorExpression();

    void addExpression(Expression* expression);
};

class SumOperator : public OperatorExpression {
public:
    SumOperator() {}

    std::string description() const override;
};

}
