#pragma once
#include <string>

namespace Norm {

class Token;

class FileWriter {
public:
    FileWriter();
    void write(const std::string& filePath, Token* token);

private:
    void writeToken(std::ofstream* stream, Token* token);
};

}
