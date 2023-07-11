#include "Function.h"
#include "norm/token/expression/BlockExpression.h"

namespace Norm {

Function::Function(const std::string& name) : m_name(name) {

}

Function::~Function() {

}

std::string Function::description() const {
    return "Function";
}

void Function::setBlock(std::unique_ptr<BlockExpression> block) {
    m_block = std::move(block);
}

}
