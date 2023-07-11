#include "Function.h"
#include "norm/token/statement/Statement.h"

namespace Norm {

Function::Function(const std::string& name) : m_name(name) {

}

Function::~Function() {

}

std::string Function::description() const {
    return "Function";
}

void Function::addStatement(std::unique_ptr<Statement> statement) {
    m_statements.push_back(std::move(statement));
}

}
