#pragma once
#include "Target.h"
#include <memory>

namespace Norm {

class Function;

class BinaryTarget : public Target {
public:
    BinaryTarget(const std::string& name);

    std::string description() const override;
    Function* main() const { return m_main; }

private:
    Function* m_main = nullptr;
};

}
