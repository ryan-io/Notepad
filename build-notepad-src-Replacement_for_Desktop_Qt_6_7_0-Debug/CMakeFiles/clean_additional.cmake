# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/notepad-src_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/notepad-src_autogen.dir/ParseCache.txt"
  "notepad-src_autogen"
  )
endif()
