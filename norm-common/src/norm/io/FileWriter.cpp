#include "FileWriter.h"
#include "norm/token/Token.h"
#include <fstream>

namespace Norm {

FileWriter::FileWriter() {

}

void FileWriter::write(const std::string& filePath, Token* token) {
    std::ofstream stream(filePath, std::ios::out | std::ios::binary | std::ios::app);
    writeToken(&stream, token);
    stream.close();
}

void FileWriter::writeToken(std::ofstream* stream, Token* token) {
    Token::Code code = token->code();
    stream->write(reinterpret_cast<const char*>(&code), sizeof code);
    token->serialize(stream);

    for (auto child : token->children()) {
        writeToken(stream, child);
    }
}

}
