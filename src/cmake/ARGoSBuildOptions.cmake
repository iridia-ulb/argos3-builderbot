#
# What is ARGoS being built for?
#
set(ARGOS_BUILD_FOR "builderbot")
set(ARGOS_BUILD_FOR_SIMULATOR FALSE)

#
# Optimize code for current platform?
#
if(NOT DEFINED ARGOS_BUILD_NATIVE)
  option(ARGOS_BUILD_NATIVE "ON -> compile with platform-specific optimizations, OFF -> compile to portable binary" OFF)
endif(NOT DEFINED ARGOS_BUILD_NATIVE)
