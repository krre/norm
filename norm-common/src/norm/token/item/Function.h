#pragma once
#include "Item.h"
#include <string>
#include <vector>
#include <memory>

namespace Norm {

class Statement;

class Function : public Item {
public:
    Function(const std::string& name);
    virtual ~Function();

    std::string description() const override;

    void addStatement(std::unique_ptr<Statement> statement);

private:
    std::string m_name;
    std::vector<std::unique_ptr<Statement>> m_statements;
};

}
