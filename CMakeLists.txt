cmake_minimum_required (VERSION 3.9)

get_filename_component(PROJECT_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project (${PROJECT_NAME})

project (${PROJECT_NAME})

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
set(CMAKE_SHARED_LINKER_FLAGS_RELEASE "${CMAKE_SHARED_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")
set(CMAKE_CXX_STANDARD 14)

add_definitions(-DUNICODE -D_UNICODE -DELPP_THREAD_SAFE)

include_directories (
	.
)


# Build static
#
add_definitions(
	-D _DISABLE_EXTENDED_ALIGNED_STORAGE
)

# Find source files
#
file (GLOB h_src "*.h" "*.hpp")
file (GLOB cpp_src "*.cpp" "*.c")



# Make Source groups
source_group ("include" FILES ${h_src})
source_group ("src" FILES ${cpp_src})

# Main executable
#
add_executable (${PROJECT_NAME} 
	${h_src}
	${cpp_src}
)

INSTALL (TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)