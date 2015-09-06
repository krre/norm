#include "defines.h"

Defines::Defines()
{

}

QMap<QString, int> Defines::version()
{
    QMap<QString, int> map;
    map["major"] = 0;
    map["minor"] = 1;
    map["patch"] = 0;
    return map;
}

