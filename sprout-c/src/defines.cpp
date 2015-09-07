#include "defines.h"

Defines::Defines()
{

}

QVariantMap Defines::version()
{
    QVariantMap map;
    map["major"] = 0;
    map["minor"] = 1;
    map["patch"] = 0;
    return map;
}
