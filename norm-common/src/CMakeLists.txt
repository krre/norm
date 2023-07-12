add_library(common STATIC
    norm/token/Token.h norm/token/Token.cpp
    norm/token/target/Target.h norm/token/target/Target.cpp
    norm/token/target/BinaryTarget.h norm/token/target/BinaryTarget.cpp
    norm/token/target/LibraryTarget.h norm/token/target/LibraryTarget.cpp
    norm/token/item/Function.h norm/token/item/Function.cpp
    norm/token/statement/Statement.h norm/token/statement/Statement.cpp
    norm/token/expression/Expression.h norm/token/expression/Expression.cpp
    norm/token/item/Item.h norm/token/item/Item.cpp
    norm/token/expression/BlockExpression.h norm/token/expression/BlockExpression.cpp
)

set_target_properties(common PROPERTIES OUTPUT_NAME norm)

target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
message(${CMAKE_CURRENT_SOURCE_DIR})
