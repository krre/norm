#include "BlockExpression.h"
#include "norm/token/statement/Statement.h"

namespace Norm {

BlockExpression::BlockExpression() {

}

void BlockExpression::addStatement(Statement* statement) {
    addChild(statement);
}

}
