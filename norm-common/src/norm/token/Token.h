#pragma once
#include <string>
#include <vector>

namespace Norm {

class Token {
public:
    explicit Token() = default;
    Token(const Token& other) = delete;
    Token& operator=(const Token& other) = delete;

    virtual ~Token();

    virtual std::string description() const = 0;

protected:
    explicit Token(Token* parent);

    Token* parent() const { return m_parent; }
    void setParent(Token* parent);

    const std::vector<Token*> children() const { return m_children; }

    void addChild(Token* child);
    void insertChild(size_t index, Token* child);

    void removeChild(Token* child);
    Token* removeChild(size_t index);

    void deleteChild(Token* child);
    void deleteChild(size_t index);

    void deleteChildren();

private:
    void setupNewChild(Token* child);

    Token* m_parent = nullptr;
    std::vector<Token*> m_children;
};

}
