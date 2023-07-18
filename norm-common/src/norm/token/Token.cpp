#include "Token.h"
#include <assert.h>

namespace Norm {

Token::Id Token::s_maxId = 0;

Token::Token(Id id) : m_id(id) {

}

Token::Token() {
    m_id = ++s_maxId;
}

Token::Token(Token* parent) {
    setParent(parent);
}

Token::~Token() {
    setParent(nullptr);
    deleteChildren();
}

void Token::setParent(Token* parent) {
    if (m_parent == parent) return;

    // Remove self from children of previous parent.
    if (m_parent) {
        m_parent->removeChild(this);
    }

    if (parent) {
        parent->addChild(this);
    }

    m_parent = parent;
}

void Token::addChild(Token* child) {
    assert(child);
    m_children.push_back(child);
    setupNewChild(child);
}

void Token::insertChild(size_t index, Token* child) {
    assert(child);
    assert(index >= 0 && index < m_children.size());
    m_children.insert(m_children.begin() + index, child);
    setupNewChild(child);
}

void Token::removeChild(Token* child) {
    assert(child);
    m_children.erase(std::remove(m_children.begin(), m_children.end(), child), m_children.end());
    child->m_parent = nullptr;
}

Token* Token::removeChild(size_t index) {
    Token* child = m_children.at(index);
    assert(index >= 0 && index < m_children.size());
    removeChild(child);
    return child;
}

void Token::deleteChild(Token* child) {
    assert(child);
    removeChild(child);
    delete child;
}

void Token::deleteChild(size_t index) {
    assert(index >= 0 && index < m_children.size());
    Token* child = removeChild(index);
    delete child;
}

void Token::deleteChildren() {
    for (auto child : m_children) {
        delete child;
    }

    m_children.clear();
}

void Token::setupNewChild(Token* child) {
    //  Remove child from children of previous parent.
    if (child->m_parent) {
        child->m_parent->removeChild(child);
    }

    child->m_parent = this;
}

}
