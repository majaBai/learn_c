/*
 第一个项目
    用 A D 可以左右移动的蓝色小球
 
 新语法
    break
 
 作业
    加上 W S 上下移动蓝色小球的功能
*/
#include "kbc.h"
#include "raylib.h"

#define kbcColorBlue BLUE;
#define kbcColorWhite WHITE;
#define kbcColorYellow YELLOW;

//  玩家小球坐标
int ballX = 100;
int ballY = 600;
int circleSize = 10;

// 记录敌人的小球坐标
int ex[4] = { 100, 130, 160, 190 };
int ey[2] = { 200, 230 };

int end = 0;



int main(void) {
    // 创建一个窗口
    // 参数是 宽 高
    kbcWindowNew(800, 600);

    
    // 变量 x, 用于表示圆形的 x
    int x = 100;

    // 无限循环, 这样程序就不会停止
    // 这个循环每 1/60 秒执行一次
    // 由下面的 kbcWaitFrame 函数保证
    while(1) {
        // 如果 esc 是被按下的状态。 break 会退出循环，程序自然结束
        if (kbcKeyIsDown(KEY_ESCAPE)) {
            break;
        }
        
        // 检查按键，如果是 A D 就改变 ballX
        if (IsKeyDown(KEY_A)) {
            ballX -= 10;
        }
        if (IsKeyDown(KEY_D)) {
            ballX += 10;
        }
        if (ballX >= 800) ballX -= 50;
        if (ballX <= 0) ballX += 50;

        //  检查按键，如果是 W S 就改变 ballY
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
            ex[i] = end == 0 ? ex[i] + 5 : ex[i] - 5;
        }
        if (ex[3] == 800) end = 1;
        if (ex[0] == 0) end = 0;

         // 画图
        // 一定要在 BeginDrawing EndDrawing 之间画图才行
        BeginDrawing();
        
        // 这个函数会用白色清空窗口
        // 这样上一次循环画的所有内容都会被擦除
        kbcWindowClear();
        
        
        // 画一个圆
        // 4 个参数分别是  圆心x 圆心y 圆半径 颜色
       // kbcDrawCircle(x, 500, 10, kbcColorBlue);

         // 画敌人小球
        for (int k = 0; k < 4; k++) {
            kbcDrawCircle(ex[k], ey[0], circleSize, YELLOW);
            kbcDrawCircle(ex[k], ey[1], circleSize, YELLOW);
        }

        //画玩家小球参数是  圆心x 圆心y 半径 颜色
        kbcDrawCircle(ballX, ballY, circleSize, BLUE);


        
        // kbcWaitFrame 会让程序等待一段时间后再继续运行
        // 确保每秒只运行 60 次循环
        kbcWaitFrame();
    }

    return 0;
}
