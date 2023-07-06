#pragma once

namespace Norm {

class Token {
public:
    Token(Token* parent = nullptr);

    Token parent() const { return m_parent; }

private:
    Token* m_parent = nullptr;
};

}
