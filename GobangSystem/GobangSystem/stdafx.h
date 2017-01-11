//  [1/11/2017 王成]
//  stdafx.h头文件用于加载头文件
//                    宏定义
//                    库文件包含部分
//                    声明全局变量
//                    全局函数声明
#pragma once

//头文件加载
#include <windows.h>
#include <tchar.h>
#include <time.h>

#pragma comment(lib,"Msimg32.lib")                  //调用TransparentBlt函数所需库文件

//宏定义
#define WINDOWS_WIDTH      800                         //窗口宽度
#define WINDOWS_HEIGHT     600                         //窗口高度
#define WINDOWS_TITLE      L"课程设计-五子棋"          //宏-窗口标题
#define CHESSBOARD_SIZE    15                          //棋盘大小
#define WINDOWS_CLASS_NAME L"GobangGameSystem"         //窗口类名

//全局结构体

//全局变量声明
HDC g_hdc = NULL, g_mdc = NULL, g_bufdc = NULL;     //全局设备环境句柄与全局内存DC句柄
DWORD g_tPre = 0, g_tNow = 0;                       //声明两个变量用于记录绘图时间
RECT g_rect;                                        //定义一个RECT结构体,用于储存内部窗口坐标
int g_iFrameNum, g_iTxtNum;                         //帧数和文字数量
wchar_t text[8][10];                                //储存输出文字字符串数组
BOOL g_bCanAttact, g_bGameOver;                     //游戏两个状态,玩家是否可以下棋,游戏是否结束

//全局函数声明
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);        //窗口过程函数
BOOL Game_Init(HWND hWnd);                                                              //游戏资源初始化
VOID Game_Main(HWND hWnd);                                                              //游戏绘图
BOOL Game_ShutDown(HWND hWnd);                                                          //在此函数中进行资源清理
VOID Game_Over(int x, int y, bool win);                                                 //游戏胜利检测
VOID Player_Play();                                                                     //玩家是否可以落子判断
