#pragma once
#include "Target.h"

namespace Norm {

class Function;

class BinaryTarget : public Target {
public:
    BinaryTarget(const std::string& name);
    BinaryTarget() = default;

    Code code() const override { return Code::BinaryTarget; }

    Function* main() const { return m_main; }

private:
    Function* m_main = nullptr;
};

}
