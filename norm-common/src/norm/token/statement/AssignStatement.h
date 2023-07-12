#pragma once
#include "Statement.h"
#include <memory>

namespace Norm {

class Identifier;
class Expression;

class AssignStatement : public Statement {
public:
    AssignStatement();
    ~AssignStatement();

    std::string description() const override;

    void setIdentifier(std::unique_ptr<Identifier> identifier);
    Identifier* identifier() const { return m_identifier.get(); }

    void setExpression(std::unique_ptr<Expression> expression);
    Expression* expression() const { return m_expression.get(); }

private:
    std::unique_ptr<Identifier> m_identifier;
    std::unique_ptr<Expression> m_expression;
};

}
