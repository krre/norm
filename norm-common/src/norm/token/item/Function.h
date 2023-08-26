#pragma once
#include "Item.h"

namespace Norm {

class BlockExpression;

class Function : public Item {
public:
    Function(const std::string& name);
    Function() = default;

    Code code() const override { return Code::Function; }

    const std::string& name() const { return m_name; }
    void setName(const std::string& name) { m_name = name; }

    void setBlock(BlockExpression* block);
    BlockExpression* block() const { return m_block; }

private:
    std::string m_name;
    BlockExpression* m_block = nullptr;
};

}
