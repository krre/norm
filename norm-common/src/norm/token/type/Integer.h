#pragma once
#include "Type.h"

namespace Norm {

class Integer : public Type {
public:
    Integer();
    std::string description() const override;
};

}
