#include "SimpleEngine.h"

USING_NS_SE;

int main(int argc, char* args[])
{
    try
    {
        SEWindow::Init("SDL2");
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
        SEWindow::Quit();
        return -1;
    }
    
    SEEventListener* listener = SEEventListener::getInstance();
    SEGameEntity* currentScene = SEDirector::getInstance()->getCurrentScene();
    
    SDL_Event event;
    
    bool quit = false;
    while (!quit)
    {
        long start = SEWindow::GetCurrentTime();
        
        SEWindow::Clear();

        // 这里的事件循环必须有，而不能是直接取一次，因为一个渲染帧过程中会有很多事件
        // Here must be a while loop to get event instead of just getting once
        // 一次取一个很可能取不到鼠标或者键盘事件，结果就是点了以后半天才取到事件开始处理，时间时快时而慢
        // for the reason that there are usually some events, getting once may not get the needed event.
        // 在分发过程中的技巧是单独收集需要接收事件的对象指针然后把事件发给它们，而不是遍历所有游戏物体，向它们都发送
        // There is also a skill in dispatching events, instead of level order travering all gameentity
        // we sort the game entity which need to receive events in a vector and just dispatch events to
        // them.
        while (SDL_PollEvent(&event))
        {
            listener->dispatchEvent(event);
        }

        SEDirector::LevelOrderTraversal (currentScene);

        SEWindow::Present();

        SEPoolManager::getInstance()->getCurPool()->autoDelete();

        long sleepTime = start + 1000 / SEWindow::FPS - SEWindow::GetCurrentTime();
        
        SEWindow::Sleep((int)sleepTime);
    }
    
    return 0;
}