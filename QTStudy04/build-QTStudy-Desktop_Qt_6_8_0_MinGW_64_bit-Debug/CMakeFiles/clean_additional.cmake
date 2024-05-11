# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\QTStudy_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\QTStudy_autogen.dir\\ParseCache.txt"
  "QTStudy_autogen"
  )
endif()
