#include "AssignStatement.h"
#include "norm/token/Identifier.h"
#include "norm/token/expression/Expression.h"

namespace Norm {

AssignStatement::AssignStatement() {

}

void AssignStatement::setIdentifier(Identifier* identifier) {
    m_identifier = identifier;
    addChild(identifier);
}

void AssignStatement::setExpression(Expression* expression) {
    m_expression = expression;
    addChild(expression);
}

}
