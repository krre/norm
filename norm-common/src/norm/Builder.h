#pragma once
#include <string>

namespace Norm {

class Project;

class Builder {
public:
    Builder(const std::string& filePath);

    Project* build();

private:
    std::string m_filePath;
};

}
