#pragma once
#include "Expression.h"

namespace Norm {

class Statement;

class BlockExpression : public Expression {
public:
    BlockExpression();

    Code code() const override { return Code::BlockExpression; }

    void addStatement(Statement* statement);
};

}
