//  [1/11/2017 王成]
//  GobangMain.cpp定义应用程序的入口点
#include "stdafx.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    //程序窗口设计
    WNDCLASSEX wndClass = { 0 };                                //使用WNDCLASSEX定义窗口类
    wndClass.cbSize = sizeof(WNDCLASSEX);                       //设置结构体的字节类大小
    wndClass.style = CS_HREDRAW | CS_VREDRAW;                   //设置窗口样式
    wndClass.lpfnWndProc = WndProc;                             //设置指向窗口过程函数的指针
    wndClass.cbClsExtra = 0;                                    //窗口类附加内存
    wndClass.cbWndExtra = 0;                                    //窗口附加内存
    wndClass.hInstance = hInstance;                             //指定包含窗口过程的程序的实例句柄
    //本地加载图标
    wndClass.hIcon = (HICON)::LoadImage(NULL, L"icon.png", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);             //指定窗口类的光标
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);   //为hbrBackground指定白色画刷句柄
    wndClass.lpszMenuName = NULL;                               //用一个以空终止的字符串,指定菜单资源
    wndClass.lpszClassName = WINDOWS_CLASS_NAME;               //用字符串指定窗口类名

    //注册窗口类
    if (!RegisterClassEx(&wndClass))
        return -1;

    //创建窗口
    HWND hWnd = CreateWindowW(WINDOWS_CLASS_NAME, WINDOWS_TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WINDOWS_WIDTH, WINDOWS_HEIGHT, NULL, NULL, hInstance, NULL);

    //窗口的移动和显示
    MoveWindow(hWnd, 250, 80, WINDOWS_WIDTH, WINDOWS_HEIGHT, true);             //移动窗口到(250,80)
    ShowWindow(hWnd, nShowCmd);                                                 //窗口显示
    UpdateWindow(hWnd);
    //窗口刷新
    //游戏资源初始化,若初始化失败,弹出一个消息框

    if (!Game_Init(hWnd)) {
        MessageBox(hWnd, L"资源初始化失败", L"消息窗口", 0);                     //使用MessageBox函数,创建消息窗口
        return FALSE;
    }

    //窗口消息循环
    MSG msg = { 0 };                                            //定义并初始化msg
    while (msg.message != WM_QUIT) {                              //消息循环,如果不是WM_QUIT消息就继续循环
        if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);                                 //将虚拟键消息转换为字符消息
            DispatchMessage(&msg);                                  //分发一个消息给窗口程序
        }
        else {
            g_tNow = GetTickCount();                                //获取当前系统时间
            if (g_tNow - g_tPre >= 60)                                //当此次循环运行与上次绘图时间相差0.06秒在进行绘图操作
            {
                Game_Main(hWnd);
            }
        }
    }

    //窗口类注销
    UnregisterClass(WINDOWS_CLASS_NAME, wndClass.hInstance);        //程序准备结束,注销窗口类

    return 0;
}