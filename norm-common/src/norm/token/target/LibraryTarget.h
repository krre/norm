#pragma once
#include "Target.h"

namespace Norm {

class LibraryTarget : public Target {
public:
    LibraryTarget(const std::string& name);

    std::string description() const override;
};

}
