#include "OperatorExpression.h"

namespace Norm {

OperatorExpression::OperatorExpression() {

}

void OperatorExpression::addExpression(std::unique_ptr<Expression> expression) {
    m_expressions.push_back(std::move(expression));
}

}
