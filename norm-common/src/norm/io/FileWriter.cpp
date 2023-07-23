#include "FileWriter.h"
#include <fstream>

namespace Norm {

FileWriter::FileWriter() {

}

void FileWriter::write(const std::string& filePath, Token* token) {
    std::ofstream fs(filePath, std::ios::out | std::ios::binary | std::ios::app);
    int magic = 42;
    fs.write(reinterpret_cast<const char*>(&magic), sizeof magic);
    fs.close();
}

}
