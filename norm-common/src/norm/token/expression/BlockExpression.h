#pragma once
#include "Expression.h"
#include <vector>
#include <memory>

namespace Norm {

class Statement;

class BlockExpression : public Expression {
public:
    BlockExpression();

    std::string description() const override;

    void addStatement(Statement* statement);
};

}
