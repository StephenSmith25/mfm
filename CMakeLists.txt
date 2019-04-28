project(mfm LANGUAGES CXX)

# Require C++14-compliant compiler; only available for CMake v. 3.1 and up
set(CMAKE_CXX_STANDARD 14)




# include eigen 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../libs/include)
# Include directories
include_directories(BEFORE
  ${mfm_SOURCE_DIR}/include/
)

add_executable(mpm ${mpm_SOURCE_DIR}/src/main.cc)

