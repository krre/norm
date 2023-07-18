#pragma once
#include "Target.h"

namespace Norm {

class LibraryTarget : public Target {
public:
    LibraryTarget(const std::string& name);

    Code code() const override { return Code::LibraryTarget; }
    std::string description() const override;
};

}
