#include "Integer.h"

namespace Norm {

Integer::Integer() : Type("Integer") {

}

std::string Integer::description() const {
    return "Integer type";
}

}
