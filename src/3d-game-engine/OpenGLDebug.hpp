#ifndef A99F83C7_1861_4AE9_9220_4985DEECD8F2
#define A99F83C7_1861_4AE9_9220_4985DEECD8F2

#include <cmake_configuration.hpp>
#if OPENGL_DEBUG == 1
    #define glCall(x, ...) n3DGE::OGLD::glCallImpl(x, __VA_ARGS__)
    #define glCallR(x, ...) n3DGE::OGLD::glCallImplR(x, __VA_ARGS__)
    #define glCallN(x) n3DGE::OGLD::glCallImpl(x)
    #define glCallRN(x) n3DGE::OGLD::glCallImplR(x)
#else
    #define glCall(x, ...) x(__VA_ARGS__)
    #define glCallR(x, ...) x(__VA_ARGS__)
    #define glCallN(x) x()
    #define glCallRN(x) x()
#endif

// A namespace containing a set of utilities that are related to debugging in OpenGL.
namespace n3DGE::OGLD {
    // Print out all of the errors generated by the previous OpenGL calls
    void printErrors();
    
    // Break the debugger
    void debugBreak();
    
    // Check the OpenGL call for errors
    template<typename callType, typename... argsType>
    void glCallImpl(callType call, argsType... args) {
        call(args...);
        printErrors();
    }
    
    // Same as the previous one, but this one returns a value
    template<typename callType, typename... argsType>
    auto glCallImplR(callType call, argsType... args) {
        auto result = call(args...);
        printErrors();
        return result;
    }
}

#endif /* A99F83C7_1861_4AE9_9220_4985DEECD8F2 */
