#pragma once
#include "Statement.h"

namespace Norm {

class Identifier;
class Expression;

class AssignStatement : public Statement {
public:
    AssignStatement();

    Code code() const override { return Code::AssignStatement; }
    std::string description() const override;

    void setIdentifier(Identifier* identifier);
    Identifier* identifier() const { return m_identifier; }

    void setExpression(Expression* expression);
    Expression* expression() const { return m_expression; }

private:
    Identifier* m_identifier = nullptr;
    Expression* m_expression = nullptr;
};

}
