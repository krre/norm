add_library(common STATIC
    norm/token/Token.h norm/token/Token.cpp
    norm/token/project/Project.h norm/token/project/Project.cpp
    norm/token/item/Function.h norm/token/item/Function.cpp
    norm/token/project/BinaryProject.h norm/token/project/BinaryProject.cpp
    norm/token/project/LibraryProject.h norm/token/project/LibraryProject.cpp
    norm/token/statement/Statement.h norm/token/statement/Statement.cpp
    norm/token/expression/Expression.h norm/token/expression/Expression.cpp
    norm/token/item/Item.h norm/token/item/Item.cpp
)

set_target_properties(common PROPERTIES OUTPUT_NAME norm)

target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
message(${CMAKE_CURRENT_SOURCE_DIR})
