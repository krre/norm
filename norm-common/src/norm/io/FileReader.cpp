#include "FileReader.h"
#include "norm/token/target/BinaryTarget.h"
#include "norm/token/target/LibraryTarget.h"
#include "norm/token/item/Function.h"
#include "norm/token/Identifier.h"
#include "norm/token/expression/BlockExpression.h"
#include "norm/token/expression/LiteralExpression.h"
#include "norm/token/expression/OperatorExpression.h"
#include "norm/token/statement/AssignStatement.h"
#include <fstream>

namespace Norm {

FileReader::FileReader() {
    addTokenCreator<BinaryTarget>(Token::Code::BinaryTarget);
    addTokenCreator<LibraryTarget>(Token::Code::LibraryTarget);
    addTokenCreator<Function>(Token::Code::Function);
    addTokenCreator<AssignStatement>(Token::Code::AssignStatement);
    addTokenCreator<BlockExpression>(Token::Code::BlockExpression);
    addTokenCreator<IntegerLiteral>(Token::Code::IntegerLiteral);
    addTokenCreator<SumOperator>(Token::Code::SumOperator);
    addTokenCreator<Integer>(Token::Code::Integer);
    addTokenCreator<Identifier>(Token::Code::Identifier);
}

Token* FileReader::read(const std::string& filePath) {
    std::ifstream stream(filePath, std::ios::binary);

    std::unordered_map<Token::Id, Token*> tokens;
    TokenProvider provider(&tokens);

    Token* startToken = nullptr;

    while (!stream.eof()) {
        Token* token = readToken(&stream);
        tokens[token->id()] = token;

        if (!startToken && (token->code() == Token::Code::BinaryTarget || token->code() == Token::Code::LibraryTarget)) {
            startToken = token;
        }
    }

    return startToken;
}

Token* FileReader::readToken(std::ifstream* stream) {
    Token::Code code;
    stream->read(reinterpret_cast<char*>(&code), sizeof code);

    if (!m_tokenCreators.contains(code)) {
        std::string error = std::string("Token code [") + std::to_string(int(code)) + "] not found";
        throw std::runtime_error(error);
    }

    Token* token = m_tokenCreators.at(code)();
    token->deserialize(stream);
    return token;
}

Token* TokenProvider::token(Token::Id id) const {
    if (!m_tokens->contains(id)) {
        std::string error = std::string("Token with id [") + std::to_string(id) + "] not found";
        throw std::runtime_error(error);
    }

    return m_tokens->at(id);
}

}
