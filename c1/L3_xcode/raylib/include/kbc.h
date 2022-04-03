//
//  kbc.h
//  L3
//
//  Created by kbc on 2022/3/24.
//  Copyright © 2022 kbc. All rights reserved.
//

#ifndef kbc_h
#define kbc_h

#include "raylib.h"
#include "raymath.h"
#include "raygui.h"


//-------
// path
//-------
#ifdef _WIN32
    #define kbcDirResource "C:\\kbc\\c\\"
#else
    #define kbcDirResource "/Users/Shared/kbc/c/"
#endif

#define kbcDir(file) kbcDirResource "" file


//-------
// value
//-------
#define kbcColorWhite WHITE
#define kbcColorBlue BLUE
#define kbcColorRed RED
#define kbcColorBlack BLACK


//-------
// type
//-------
typedef Texture kbcImage;
typedef Color kbcColor;


//-------
// window
//-------
void
kbcWindowNew(int width, int height);

void
kbcWindowClear(void);


//-------
// image
//-------
//
// 自己的载入函数，屏蔽了 kbcDir 路径宏
#define kbcImageLoad(path) LoadTexture(kbcDir(path))

void
kbcImageDraw(kbcImage image, int x, int y);


//-------
// frame
//-------
void
kbcWaitFrame(void);


//-------
// event
//-------
// 事件
bool
kbcKeyIsDown(int key);


//-------
// primitive
//-------
void
kbcDrawCircle(int centerX, int centerY, float radius, kbcColor color);



#endif /* kbc_h */
