#include "AutoReleasePool.hpp"
#include "Director.hpp"
#include "Heroine.hpp"
#include "InputHandler.hpp"

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
    
    SDL_Event e;
    std::unique_ptr<InputHandler> handler(new InputHandler());
    
    GameEntity* currentScene = Director::getInstance()->getCurrentScene();
    currentScene->addChild(Heroine::create("./images/sprite.png", 100, 100));
    
    bool quit = false;
    while (!quit)
    {
        SDL_PollEvent(&e);
        
        Window::Clear();

        Director::LevelOrder(currentScene, e);
        
        Window::Present();
        
        PoolManager::getInstance()->getCurPool()->autoDelete();
    }
    
    return 0;
}