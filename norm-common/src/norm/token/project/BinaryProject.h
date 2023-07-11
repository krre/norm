#pragma once
#include "Project.h"
#include <memory>

namespace Norm {

class Function;

class BinaryProject : public Project {
public:
    BinaryProject(const std::string& name);

    std::string description() const override;
    Function* main() const { return m_main.get(); }

private:
    std::unique_ptr<Function> m_main;
};

}
