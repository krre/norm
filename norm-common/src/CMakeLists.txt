add_library(common STATIC
    norm/token/Token.h norm/token/Token.cpp
    norm/token/Project.h norm/token/Project.cpp
)

set_target_properties(common PROPERTIES OUTPUT_NAME norm)
