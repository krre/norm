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

    Code code() const override { return Code::SumOperator; }
    std::string description() const override;
};

}
