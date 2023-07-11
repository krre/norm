#pragma once
#include "Expression.h"
#include <vector>
#include <memory>

namespace Norm {

class Statement;

class BlockExpression : public Expression {
public:
    BlockExpression();
    ~BlockExpression();

    std::string description() const override;

    void addStatement(std::unique_ptr<Statement> statement);

private:
    std::vector<std::unique_ptr<Statement>> m_statements;
};

}
