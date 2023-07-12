#pragma once
#include "Statement.h"

namespace Norm {

class AssignStatement : public Statement {
public:
    AssignStatement();

    std::string description() const override;

private:
};

}
