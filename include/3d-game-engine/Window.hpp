#ifndef CBB9864F_8D47_4591_AA20_5F63134195E3
#define CBB9864F_8D47_4591_AA20_5F63134195E3

#include <GLFW/glfw3.h>
#include <string_view>

namespace n3DGE {
    
    // A Basic wrapper class around the GLFW library
    class Window {
    private:
        GLFWwindow* window;
        
        unsigned int width;
        unsigned int height;
        
    public:
        // Default constructor, which constructs a window half the size of it's host monitor
        Window();
        
        // Constructor
        Window(unsigned int width, unsigned int height, std::string_view title, bool isFullscreen = false);
        
        // Show the window, as it's hidden by default
        void show();
        
        // Returns if the window is open or not
        bool isOpen();
        
        // Update the window
        void update();
        
        // Set the title
        void setTitle(std::string_view newTitle);
        
        // Framebuffer size callback
        static void framebufferSizeCallback(GLFWwindow* window, int width, int height);
        
        // Destroys the window
        ~Window();
    };
}

#endif /* CBB9864F_8D47_4591_AA20_5F63134195E3 */
