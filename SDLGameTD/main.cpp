#include "AutoReleasePool.hpp"
#include "Director.hpp"
#include "Heroine.hpp"

int main(int argc, char* args[])
{
    try
    {
        Window::Init("SDL2");
    }
    catch (const std::runtime_error &e){
        std::cout << e.what() << std::endl;
        Window::Quit();
        return -1;
    }
    
    GameEntity* currentScene = Director::getInstance()->getCurrentScene();
    
    SDL_Event e;
    
    bool quit = false;
    while (!quit)
    {
        long start = Window::GetCurrentTime();
        
        SDL_PollEvent(&e);
        
        Window::Clear();

        Director::LevelOrderTraversal (currentScene, e);
        
        Window::Present();
        
        PoolManager::getInstance()->getCurPool()->autoDelete();
        
        long sleepTime = start + 1000 / Window::FPS - Window::GetCurrentTime();
        
        Window::Sleep((int)sleepTime);
    }
    
    return 0;
}