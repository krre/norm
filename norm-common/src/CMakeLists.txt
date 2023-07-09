add_library(common STATIC
    norm/token/Token.h norm/token/Token.cpp
    norm/token/Project.h norm/token/Project.cpp
    norm/Builder.h norm/Builder.cpp
)

set_target_properties(common PROPERTIES OUTPUT_NAME norm)
