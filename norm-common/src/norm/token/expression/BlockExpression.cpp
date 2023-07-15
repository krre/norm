#include "BlockExpression.h"
#include "norm/token/statement/Statement.h"

namespace Norm {

BlockExpression::BlockExpression() {

}

std::string BlockExpression::description() const {
    return "Block expression";
}

void BlockExpression::addStatement(Statement* statement) {
    addChild(statement);
}

}
