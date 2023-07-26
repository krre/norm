#pragma once
#include "norm/token/Token.h"
#include <string>
#include <unordered_map>
#include <functional>

namespace Norm {

class Token;

using Tokens = std::unordered_map<Token::Id, Token*>;

class TokenProvider {
public:
    TokenProvider(Tokens* tokens) : m_tokens(tokens) {}
    Token* token(Token::Id id) const;

private:
    Tokens* m_tokens = nullptr;
};

class FileReader {
public:
    FileReader();
    Token* read(const std::string& filePath);

private:
    template <class T>
    void addTokenCreator(Token::Code code) {
        m_tokenCreators[code] = [] { return new T; };
    }

    Token* readToken(std::ifstream* stream);

    std::unordered_map<Token::Code, std::function<Token*()>> m_tokenCreators;
};

}
