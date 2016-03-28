#include "Sprite.hpp"
#include "InputHandler.hpp"

void drawSprite (Sprite* ge);
void levelOrderDraw (GameEntity* root);

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
        
        //level order traverse the gameEntity tree, draw visible gameEntity
        levelOrderDraw(Window::currentScene);
        
        Window::Present();
    }
    
    return 0;
}

void drawSprite (Sprite* ge)
{
    Transform* trans = (Transform *)ge->getComponent("Transform");
    
    int x = trans->x;
    int y = trans->y;
    
    int w, h;
    SDL_Texture* texture = ge->getTexture();
    SDL_QueryTexture(texture, nullptr, nullptr, &w, &h);
    
    SDL_Rect dest = {x, y, w, h};
    
    Window::Draw(texture, dest);
}

void levelOrderDraw (GameEntity* root)
{
    std::queue<GameEntity*> queue;
    
    if (root != nullptr)
    {
        queue.push(root);
        
        while(!queue.empty())
        {
            GameEntity* ge = queue.front();
            
            if (ge->isVisible())
            {
                drawSprite((Sprite*)ge);
            }
            
            for (int i = 0; i < ge->children.size(); i++)
            {
                queue.push(ge->children[i]);
            }
        }
    }
}