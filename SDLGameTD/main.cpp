#include "Director.hpp"
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
    currentScene->addChild(new Sprite ("./images/sprite.png", 100, 100));
    
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&e))
        {
            handler->handleInput(e);
//            if (e.type == SDL_QUIT)
//            {
//                quit = true;
//            }
//            if (e.type == SDL_KEYDOWN)
//            {
//                switch (e.key.keysym.sym)
//                {
//                    case SDLK_d:
//                        angle += 2;
//                        break;
//                    case SDLK_a:
//                        angle -= 2;
//                        break;
//                }
//            }
        }
        
        Window::Clear();

        Director::LevelOrderDraw(currentScene);
        
        Window::Present();
    }
    
    return 0;
}