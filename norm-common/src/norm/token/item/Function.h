#pragma once
#include "Item.h"

namespace Norm {

class BlockExpression;

class Function : public Item {
public:
    Function(const std::string& name);
    Function() = default;

    Code code() const override { return Code::Function; }
    std::string description() const override;

    void setBlock(BlockExpression* block);
    BlockExpression* block() const { return m_block; }

private:
    std::string m_name;
    BlockExpression* m_block = nullptr;
};

}
