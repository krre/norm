#pragma once
#include "Token.h"
#include <string>
#include <vector>

namespace Norm {

class Function;

class Project : public Token {
public:
    enum class Type {
        Binary,
        Library
    };

    Project(const std::string& name, Type type);
    ~Project();

    const std::string& name() const { return m_name; }
    Type type() const { return m_type; }

    static Project* read(const std::string& filePath);
    void write(const std::string& filePath);

    // Take ownership of Function.
    void addFunction(Function* function);

    void setMain(Function* main);
    Function* main() const { return m_main; }

private:
    std::string m_name;
    Type m_type;
    std::vector<Function*> m_functions;
    Function* m_main;
};

}
