#include "OperatorExpression.h"

namespace Norm {

OperatorExpression::OperatorExpression() {

}

void OperatorExpression::addExpression(Expression* expression) {
    addChild(expression);
}

std::string SumOperator::description() const {
    return "Sum operator";
}

}
