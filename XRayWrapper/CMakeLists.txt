# CMakeList.txt : CMake project for XRayWrapper, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("XRayWrapper")

# Add source to this project's executable.
add_executable (XRayWrapper "XRayWrapper.cpp" "XRayWrapper.h" "Vector3.cpp" "Vector3.h")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
set(EXTERN_LIB ${CMAKE_SOURCE_DIR}/extern)
target_link_directories(XRayWrapper 
	PUBLIC  ${EXTERN_LIB}/SimpleGVXR/lib 
			${EXTERN_LIB}/gVirtualXRay/lib 
			${EXTERN_LIB}/xraylib/lib
			${EXTERN_LIB}/contrib/assimp-install/lib
			${EXTERN_LIB}/contrib/glew-install/lib
			${EXTERN_LIB}/contrib/glfw-install/lib
			${EXTERN_LIB}/contrib/LibTIFF-install/lib
			${EXTERN_LIB}/contrib/zlib-install/lib

)
#target_link_directories(XRayWrapper ${CMAKE_SOURCE_DIR}/extern/SimpleGVXR/lib)
target_link_libraries(XRayWrapper SimpleGVXR gVirtualXRay libxrl-11 OpenGL32 assimp-vc140-mt irrXML libglew32 glfw3 tiff tiffxx zlibstatic)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET XRayWrapper PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
