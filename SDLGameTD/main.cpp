#include "Window.hpp"
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
    
    //Load up an image and some text
    SDL_Texture *img, *msg;
    try
    {
        //Load the image
        std::string imgFile = "./images/image.png";
        img = Window::LoadImage(imgFile);
        //Load the font and message
        std::string fontFile = "./fonts/sample.ttf";
        std::string text = "TTF Fonts too!";
        SDL_Color color = { 255, 255, 255 };
        msg = Window::RenderText(text, fontFile, color, 25);
    }
    catch (const std::runtime_error &e)
    {
        //Catch error and crash
        std::cout << e.what() << std::endl;
        Window::Quit();
        return -1;
    }
    //Set a position to draw it with
    SDL_Rect pos = {Window::Box().w / 2 - 150 / 2, Window::Box().h / 2 - 150 / 2, 150, 150 };
    //The angle to draw at, so we can play with it
    int angle = 0;
    
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
        
        Window::Draw(img, pos, NULL, angle);
        Window::Draw(msg, pos, NULL, angle, 0, 0, SDL_FLIP_NONE);
        
        Window::Present();
    }
    
    return 0;
}