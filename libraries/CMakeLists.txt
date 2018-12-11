#include_directories()

set(LIBRARIES_SRCS
  Account.h Account.cpp
  AccountActions.h AccountActions.cpp
)

set(LIB_TYPE STATIC)

add_library(libraries ${LIB_TYPE} ${LIBRARIES_SRCS})
