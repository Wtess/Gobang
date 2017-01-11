//  [1/11/2017 ����]
//  GobangMain.cpp����Ӧ�ó������ڵ�
#include "stdafx.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
    //���򴰿����
    WNDCLASSEX wndClass = { 0 };                                //ʹ��WNDCLASSEX���崰����
    wndClass.cbSize = sizeof(WNDCLASSEX);                       //���ýṹ����ֽ����С
    wndClass.style = CS_HREDRAW | CS_VREDRAW;                   //���ô�����ʽ
    wndClass.lpfnWndProc = WndProc;                             //����ָ�򴰿ڹ��̺�����ָ��
    wndClass.cbClsExtra = 0;                                    //�����฽���ڴ�
    wndClass.cbWndExtra = 0;                                    //���ڸ����ڴ�
    wndClass.hInstance = hInstance;                             //ָ���������ڹ��̵ĳ����ʵ�����
    //���ؼ���ͼ��
    wndClass.hIcon = (HICON)::LoadImage(NULL, L"icon.png", IMAGE_ICON, 0, 0, LR_DEFAULTSIZE | LR_LOADFROMFILE);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);             //ָ��������Ĺ��
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);   //ΪhbrBackgroundָ����ɫ��ˢ���
    wndClass.lpszMenuName = NULL;                               //��һ���Կ���ֹ���ַ���,ָ���˵���Դ
    wndClass.lpszClassName = WINDOWS_CLASS_NAME;               //���ַ���ָ����������

    //ע�ᴰ����
    if (!RegisterClassEx(&wndClass))
        return -1;

    //��������
    HWND hWnd = CreateWindowW(WINDOWS_CLASS_NAME, WINDOWS_TITLE, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WINDOWS_WIDTH, WINDOWS_HEIGHT, NULL, NULL, hInstance, NULL);

    //���ڵ��ƶ�����ʾ
    MoveWindow(hWnd, 250, 80, WINDOWS_WIDTH, WINDOWS_HEIGHT, true);             //�ƶ����ڵ�(250,80)
    ShowWindow(hWnd, nShowCmd);                                                 //������ʾ
    UpdateWindow(hWnd);
    //����ˢ��
    //��Ϸ��Դ��ʼ��,����ʼ��ʧ��,����һ����Ϣ��

    if (!Game_Init(hWnd)) {
        MessageBox(hWnd, L"��Դ��ʼ��ʧ��", L"��Ϣ����", 0);                     //ʹ��MessageBox����,������Ϣ����
        return FALSE;
    }

    //������Ϣѭ��
    MSG msg = { 0 };                                            //���岢��ʼ��msg
    while (msg.message != WM_QUIT) {                              //��Ϣѭ��,�������WM_QUIT��Ϣ�ͼ���ѭ��
        if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);                                 //���������Ϣת��Ϊ�ַ���Ϣ
            DispatchMessage(&msg);                                  //�ַ�һ����Ϣ�����ڳ���
        }
        else {
            g_tNow = GetTickCount();                                //��ȡ��ǰϵͳʱ��
            if (g_tNow - g_tPre >= 60)                                //���˴�ѭ���������ϴλ�ͼʱ�����0.06���ڽ��л�ͼ����
            {
                Game_Main(hWnd);
            }
        }
    }

    //������ע��
    UnregisterClass(WINDOWS_CLASS_NAME, wndClass.hInstance);        //����׼������,ע��������

    return 0;
}