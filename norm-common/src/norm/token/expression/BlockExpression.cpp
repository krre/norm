#include "BlockExpression.h"
#include "norm/token/statement/Statement.h"

namespace Norm {

BlockExpression::BlockExpression() {

}

BlockExpression::~BlockExpression() {

}

std::string BlockExpression::description() const {
    return "Block expression";
}

void BlockExpression::addStatement(std::unique_ptr<Statement> statement) {
    m_statements.push_back(std::move(statement));
}

}
