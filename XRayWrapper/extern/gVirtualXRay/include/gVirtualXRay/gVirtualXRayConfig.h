/*

Copyright (c) 2014, Dr Franck P. Vidal (franck.p.vidal@fpvidal.net),
http://www.fpvidal.net/
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

3. Neither the name of the Bangor University nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/


#ifndef __gVirtualXRayConfig_h
#define __gVirtualXRayConfig_h

// the configured options and settings for gVirtualXRay
#define gVirtualXRay_VERSION_MAJOR "2"
#define gVirtualXRay_VERSION_MINOR "0"
#define gVirtualXRay_VERSION_PATCH "0"

#if defined(_WIN32) || defined(_WIN64)
#define _USE_MATH_DEFINES
#endif

//#ifdef HAS_GLEW

#if defined(_WIN32) || defined(_WIN64)
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

#define GLEW_EGL
//#include <GL/glew.h>

//#else // HAS_GLEW

#ifdef __APPLE__
#ifndef GL3_PROTOTYPES
#define GL3_PROTOTYPES 1
#endif // GL3_PROTOTYPES
#include <OpenGL/gl3.h>
#else // __APPLE__
#ifndef GL_GLEXT_PROTOTYPES
#define GL_GLEXT_PROTOTYPES 1
#endif // GL_GLEXT_PROTOTYPES
#ifndef HAS_GLEW
#include <GL/glcorearb.h>
#endif // HAS_GLEW
#endif // __APPLE__

#if (defined(_MSC_VER) && (_MSC_VER <= 1600))
#define isnan(x) _isnan(x)
#define isinf(x) (!_finite(x))
#endif

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#define gvxr_VERSION "gVirtualXRay core library (gvxr) 2.0.0 (2022-08-03T22:00:45) [Compiler: Microsoft Visual Studio] on Windows"


//#endif // HAS_GLEW

#endif //__gVirtualXRayConfig_h
