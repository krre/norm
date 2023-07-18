#pragma once
#include "Type.h"

namespace Norm {

class Integer : public Type {
public:
    Integer();

    Code code() const override { return Code::Integer; }
    std::string description() const override;
};

}
