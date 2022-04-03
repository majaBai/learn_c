//
//  main.c
//  L3
//
//  Created by kbc on 2022/3/20.
//  Copyright © 2022 kbc. All rights reserved.
//

#include "raylib.h"
#include "kbc.h"

#define kbcColorBlue BLUE
#define kbcColorWhite WHITE
#define kbcColorYellow YELLOW


//  玩家小球坐标
int ballX = 100;
int ballY = 600;
int circleSize = 10;

// 记录敌人的小球坐标
int ex[4] = {100, 130, 160, 190};
int ey[2] = {200, 230};

int end = 0;

int main(void) {
    // 初始化窗口 参数是 宽 高 标题
    InitWindow(800, 600, "move ball");
    // 参数 1 表示下面的无限循环每秒执行 1 次
    SetTargetFPS(1);

    
    // 按 ESC 后
    // WindowShouldClose 会返回 true
    // 这样就退出无限循环了
    while (1) {
        
        // 如果 esc 是被按下的状态。 break 会退出循环，程序自然结束
        if (IsKeyDown(KEY_ESCAPE)) {
            break;
        }
        // 检查按键，如果是 A D 就改变 ballX
        if (IsKeyDown(KEY_A)) {
            ballX -= 20;
        }
        if (IsKeyDown(KEY_D)) {
            ballX += 20;
        }
        if (ballX >= 800) ballX -= 50;
        if (ballX <= 0) ballX += 50;
        
        if (IsKeyDown(KEY_W)) {
            ballY -= 10;
        }
        if (IsKeyDown(KEY_S)) {
            ballY += 10;
        }
        if (ballY >= 600) ballY -= 50;
        if (ballY <= 0) ballY += 50;
        // 敌人小球移动
        for (int i = 0; i < 4; i++) {
            ex[i] = end == 0 ?  ex[i] + 10 : ex[i] - 10;
        }
        if (ex[3] == 800) end = 1;
        if (ex[0] == 0) end = 0;
       

        // 画图
        // 一定要在 BeginDrawing EndDrawing 之间画图才行
        BeginDrawing();
        // 清空画面 参数是预定义的白色
        ClearBackground(kbcColorWhite);
        
       
        // 画敌人小球
        for (int k = 0; k < 4; k++) {
            DrawCircle(ex[k], ey[0], circleSize, kbcColorYellow);
            DrawCircle(ex[k], ey[1], circleSize, kbcColorYellow);
        }
        
        // 参数是  圆心x 圆心y 半径 颜色
        DrawCircle(ballX, ballY, circleSize, kbcColorBlue);
        

//        EndDrawing();
        
        // kbcWaitFrame 会让程序等待一段时间后再继续运行
        // 确保每秒只运行 60 次循环
        kbcWaitFrame();
    }

    // 关闭窗口 退出程序
//    CloseWindow();

    return 0;
}

