//  [1/11/2017 王成]
//  窗口过程WndProc.cpp

#include "stdafx.h"

//  描述: 窗口过程函数,对窗口消息进行处理
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_KEYDOWN:                        //按键消息
        if (wParam == VK_ESCAPE)
            PostQuitMessage(0);
        break;
    case WM_LBUTTONDOWN:                    //鼠标左键消息
        if (!g_bCanAttact)
        {
            int x = LOWORD(lParam);         //x坐标
            int y = LOWORD(lParam);         //y坐标

            if (x >= 0 && x <= CHESSBOARD_SIZE && y >= 0 && y <= CHESSBOARD_SIZE)
            {
                g_bCanAttact = true;
                Player_Play();
            }
        }
        break;
    case WM_DESTROY:                        //若是窗口销毁消息
        Game_ShutDown(hWnd);                //退出前清理资源
        PostQuitMessage(0);                 //向系统表明有个线程有终止请求
        break;
    default://若上述case条件都不符合,调用默认窗口
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;//正常退出
}
