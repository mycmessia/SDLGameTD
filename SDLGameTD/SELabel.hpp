//
//  SELabel.hpp
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/21/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef SELabel_hpp
#define SELabel_hpp

#include "SEGameEntity.hpp"

NS_SE_BEGIN

class SELabel : public SEGameEntity
{
private:
    SDL_Texture* _texture;
    
    std::string _message;
    std::string _fontFile;
    SDL_Color _fontColor;
    int _fontSize;
protected:
    int _width;
    int _height;
    
public:
    int getWidth ();
    int getHeight ();
    
    SDL_Texture* getTexture ();
    
    const SDL_Rect getRect ();
    
    std::string getString ();
    void setString (std::string str);
    
    virtual void draw ();
    
    static SELabel* create (const std::string &message, const std::string &fontFile,
                            SDL_Color color, int fontSize, SEPos pos);
    
    virtual bool init (const std::string &message, const std::string &fontFile,
                       SDL_Color color, int fontSize, SEPos pos);
};

NS_SE_END

#endif /* SELabel_hpp */
