#pragma once
#include <string>

namespace Norm {

class Token;

class FileReader {
public:
    FileReader();
    Token* read(const std::string& filePath);
};

}
