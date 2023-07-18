#pragma once
#include "Expression.h"
#include <vector>
#include <memory>

namespace Norm {

class Statement;

class BlockExpression : public Expression {
public:
    BlockExpression();

    Code code() const override { return Code::BlockExpression; }
    std::string description() const override;

    void addStatement(Statement* statement);
};

}
