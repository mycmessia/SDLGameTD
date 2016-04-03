//
//  Macros.h
//  SDLGameTD
//
//  Created by 梅宇宸 on 4/2/16.
//  Copyright © 2016 梅宇宸. All rights reserved.
//

#ifndef Macros_h
#define Macros_h

#ifdef __cplusplus
#define NS_SE_BEGIN                     namespace SimpleEngine {
#define NS_SE_END                       }
#define USING_NS_SE                     using namespace SimpleEngine
#define NS_SE                           ::SimpleEngine
#else
#define NS_SE_BEGIN
#define NS_SE_END
#define USING_NS_SE
#define NS_SE
#endif

#define SE_SAFE_DELETE(p) do { delete (p); (p) = nullptr; } while(0)

#endif /* Macros_h */
