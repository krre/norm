#pragma once
#include "norm/token/Token.h"
#include <string>
#include <vector>
#include <memory>

namespace Norm {

class Function;

class Project : public Token {
public:
    Project(const std::string& name);
    ~Project();

    const std::string& name() const { return m_name; }

    static Project* read(const std::string& filePath);
    void write(const std::string& filePath);

    void addFunction(std::unique_ptr<Function> function);

private:
    std::string m_name;
    std::vector<std::unique_ptr<Function>> m_functions;
};

}
