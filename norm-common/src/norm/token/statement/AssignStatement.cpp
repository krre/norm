#include "AssignStatement.h"
#include "norm/token/Identifier.h"
#include "norm/token/expression/Expression.h"

namespace Norm {

AssignStatement::AssignStatement() {

}

AssignStatement::~AssignStatement() {

}

std::string AssignStatement::description() const {
    return "Assign statement";
}

void AssignStatement::setIdentifier(std::unique_ptr<Identifier> identifier) {
    m_identifier = std::move(identifier);
}

void AssignStatement::setExpression(std::unique_ptr<Expression> expression) {
    m_expression = std::move(expression);
}

}
