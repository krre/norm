#include "Function.h"
#include "norm/token/expression/BlockExpression.h"

namespace Norm {

Function::Function(const std::string& name) : m_name(name) {

}

std::string Function::description() const {
    return "Function";
}

void Function::setBlock(BlockExpression* block) {
    m_block = block;
    addChild(block);
}

}
