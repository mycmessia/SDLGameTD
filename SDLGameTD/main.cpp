#include "AutoReleasePool.hpp"
#include "Director.hpp"
#include "EventListener.hpp"

int main(int argc, char* args[])
{
    try
    {
        Window::Init("SDL2");
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
        Window::Quit();
        return -1;
    }
    
    EventListener* listener = EventListener::getInstance();
    GameEntity* currentScene = Director::getInstance()->getCurrentScene();
    
    SDL_Event event;
    
    bool quit = false;
    while (!quit)
    {
        long start = Window::GetCurrentTime();
        
        Window::Clear();
        
        // 这里的事件循环必须有，而不能是直接取一次，因为一个渲染帧过程中会有很多事件
        // 一次取一个很可能取不到鼠标或者键盘事件，结果就是点了以后半天才取到事件开始处理，时间时快时而慢
        // 在分发过程中的技巧是单独收集需要接收事件的对象指针然后把事件发给它们，而不是遍历所有游戏物体，向它们都发送
        while (SDL_PollEvent(&event))
        {
            listener->dispatchEvent(event);
        }
        
        Director::LevelOrderTraversal (currentScene);
        
        Window::Present();
        
        PoolManager::getInstance()->getCurPool()->autoDelete();
        
        long sleepTime = start + 1000 / Window::FPS - Window::GetCurrentTime();
        
        Window::Sleep((int)sleepTime);
    }
    
    return 0;
}