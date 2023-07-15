#pragma once
#include "Item.h"
#include <string>
#include <memory>

namespace Norm {

class BlockExpression;

class Function : public Item {
public:
    Function(const std::string& name);

    std::string description() const override;

    void setBlock(BlockExpression* block);
    BlockExpression* block() const { return m_block; }

private:
    std::string m_name;
    BlockExpression* m_block = nullptr;
};

}
