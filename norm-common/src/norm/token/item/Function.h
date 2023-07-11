#pragma once
#include "Item.h"
#include <string>
#include <memory>

namespace Norm {

class BlockExpression;

class Function : public Item {
public:
    Function(const std::string& name);
    virtual ~Function();

    std::string description() const override;

    void setBlock(std::unique_ptr<BlockExpression> block);
    BlockExpression* block() const { return m_block.get(); }

private:
    std::string m_name;
    std::unique_ptr<BlockExpression> m_block;
};

}
