#pragma once
#include <string>
#include <vector>

namespace Norm {

class Token {
public:
    enum class Code : int8_t {
        BinaryTarget =      0x00,
        LibraryTarget =     0x01,
        Function =          0x02,
        AssignStatement =   0x03,
        BlockExpression =   0x04,
        IntegerLiteral =    0x05,
        SumOperator =       0x06,
        Integer =           0x07,
        Identifier =        0x08,
    };

    using Id = uint16_t;

    explicit Token(Id id);
    explicit Token();

    Token(const Token& other) = delete;
    Token& operator=(const Token& other) = delete;

    virtual ~Token();

    virtual Code code() const = 0;
    virtual std::string description() const = 0;

    Id id() const { return m_id; }
    void setId(Id id) { m_id = id; }

    static Id maxId() { return s_maxId; }
    static void setMaxId(Id maxId) { s_maxId = maxId; }

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

    Id m_id = 0;
    Token* m_parent = nullptr;
    std::vector<Token*> m_children;

    static Id s_maxId;
};

}
