#include "kbc.h"


#define kbcDrawBegin BeginDrawing
#define kbcDrawEnd EndDrawing
#define kbcBackgroundDraw ClearBackground


void
kbcWindowNew(int width, int height) {
    InitWindow(width, height, "move ball 2.0");
    
    SetExitKey(0);
    
    // 参数 60 表示每秒执行 60 次
    SetTargetFPS(60);
}

void
kbcWindowClear(void) {
    kbcDrawBegin();
    kbcBackgroundDraw(kbcColorWhite);
}

void
kbcDrawCircle(int centerX, int centerY, float radius, kbcColor color) {
    DrawCircle(centerX, centerY, radius, color);
}

void
kbcImageDraw(kbcImage image, int x, int y) {
    // 省一个参数 tintColor
    DrawTexture(image, x, y, kbcColorWhite);
}

void
kbcWaitFrame(void) {
    EndDrawing();
}

bool
kbcKeyIsDown(int key) {
    return IsKeyDown(key);
}
