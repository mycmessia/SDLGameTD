//
//  SEWindow.cpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 3/23/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#include "SEWindow.hpp"

USING_NS_SE;

//Initialize the unique_ptr's deleters here
std::unique_ptr<SDL_Window, void (*)(SDL_Window*)> SEWindow::mWindow
= std::unique_ptr<SDL_Window, void (*)(SDL_Window*)>(nullptr, SDL_DestroyWindow);

std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer*)> SEWindow::mRenderer
= std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer*)>(nullptr, SDL_DestroyRenderer);

//Other static members
SDL_Rect SEWindow::mBox;

void SEWindow::Sleep (int milliseconds)
{
    std::chrono::milliseconds dura(milliseconds);
    std::this_thread::sleep_for(dura);
}

//In SEWindow.cpp
void SEWindow::Init(std::string title)
{
    //initialize all SDL subsystems
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
        throw std::runtime_error("SDL Init Failed");
    if (TTF_Init() == -1)
        throw std::runtime_error("TTF Init Failed");
    
    //Setup our SEWindow size
    mBox.x = 0;
    mBox.y = 0;
    mBox.w = 960;
    mBox.h = 640;
    //Create our SEWindow
    mWindow.reset(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
                                   SDL_WINDOWPOS_CENTERED, mBox.w, mBox.h, SDL_WINDOW_SHOWN));
    //Make sure it created ok
    if (mWindow == nullptr)
        throw std::runtime_error("Failed to create SEWindow");
    
    //Create the renderer
    mRenderer.reset(SDL_CreateRenderer(mWindow.get(), -1,
                                       SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
    //Make sure it created ok
    if (mRenderer == nullptr)
        throw std::runtime_error("Failed to create renderer");
}

void SEWindow::Quit()
{
    TTF_Quit();
    SDL_Quit();
}

void SEWindow::Draw(SDL_Texture *tex, SDL_Rect &dstRect, SDL_Rect *clip, float angle,
                  int xPivot, int yPivot, SDL_RendererFlip flip)
{
    //Convert pivot pos from relative to object's center to screen space
    xPivot += dstRect.w / 2;
    yPivot += dstRect.h / 2;
    //SDL expects an SDL_Point as the pivot location
    SDL_Point pivot = { xPivot, yPivot };
    //Draw the texture
    SDL_RenderCopyEx(mRenderer.get(), tex, clip, &dstRect, angle, &pivot, flip);
}

SDL_Texture* SEWindow::LoadImage (const std::string &file)
{
    SDL_Texture* tex = nullptr;
    tex = IMG_LoadTexture(mRenderer.get(), file.c_str());
    if (tex == nullptr)
        throw std::runtime_error("Failed to load image: " + file + IMG_GetError());
    return tex;
}

SDL_Texture* SEWindow::RenderText(const std::string &message, const std::string &fontFile,
                                SDL_Color color, int fontSize)
{
    //Open the font
    TTF_Font *font = nullptr;
    font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == nullptr)
        throw std::runtime_error("Failed to load font: " + fontFile + TTF_GetError());
    
    //Render the message to an SDL_Surface, as that's what TTF_RenderText_X returns
    SDL_Surface *surf = TTF_RenderText_Blended(font, message.c_str(), color);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(mRenderer.get(), surf);
    //Clean up unneeded stuff
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    
    return texture;
}

void SEWindow::Clear()
{
    SDL_RenderClear(mRenderer.get());
}

void SEWindow::Present()
{
    SDL_RenderPresent(mRenderer.get());
}

SDL_Rect SEWindow::Box()
{
    //Update mBox to match the current SEWindow size
    SDL_GetWindowSize(mWindow.get(), &mBox.w, &mBox.h);
    return mBox;
}