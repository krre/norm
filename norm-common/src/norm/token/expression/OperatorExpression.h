#pragma once
#include "Expression.h"

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
};

}
