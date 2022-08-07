#ifndef __ResourceManager_h
#define __ResourceManager_h


//******************************************************************************
//  Include
//******************************************************************************
#include <vector>

#ifdef HAS_GLEW
#include "GL/glew.h"
#endif

#ifndef __Shader_h
#include <gVirtualXRay/Shader.h>
#endif

#ifndef __OpenGL2VBO_h
#include <gVirtualXRay/OpenGL2VBO.h>
#endif

#ifndef __OpenGL3VBO_h
#include <gVirtualXRay/OpenGL3VBO.h>
#endif

#ifndef __Context_h
#include <gVirtualXRay/Context.h>
#endif


//******************************************************************************
//	namespace
//******************************************************************************
using namespace gVirtualXRay;


class FramebufferObject;


class ResourceManager
{
    public:
        static ResourceManager& getInstance()
        {
            static ResourceManager    instance; // Guaranteed to be destroyed.
                                  // Instantiated on first use.
            return instance;
        }

        ResourceManager(ResourceManager const&) = delete;
        void operator=(ResourceManager const&)  = delete;

        void releaseResources();

        void addShader(Shader* apShader);
        void addFBO(FramebufferObject* apFBO);
        void addVBO(OpenGL2VBO* apVBO);
        void addVBO(OpenGL3VBO* apVBO);

        void destroyAndRemoveShader(Shader* apShader);
        void destroyAndRemoveFBO(FramebufferObject* apFBO);
        void destroyAndRemoveVBO(OpenGL2VBO* apVBO);
        void destroyAndRemoveVBO(OpenGL3VBO* apVBO);

        void setGraphicsContext(Context* apContext);
        Context* getGraphicsContext();
        void destroyAndRemoveContext();

      private:
        ResourceManager();

        std::vector<Shader*> m_p_shader_set;
        std::vector<FramebufferObject*> m_p_FBO_set;

        std::vector<OpenGL2VBO*> m_p_gl2_vbo;
        std::vector<OpenGL3VBO*> m_p_gl3_vbo;

        Context* m_p_context;
};

#endif
