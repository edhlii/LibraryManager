cmake_minimum_required(VERSION 3.22.0)
project(LibraryManager)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Thư mục output (file exe sẽ nằm trong bin/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
# Include headers
include_directories(${CMAKE_SOURCE_DIR}/include)
# Link thư viện ngoài (nếu có trong lib/)
link_directories(${CMAKE_SOURCE_DIR}/lib)
# Lấy tất cả file .cpp trong src/
file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
# Tạo executable
add_executable(LibraryManager ${SRC_FILES})