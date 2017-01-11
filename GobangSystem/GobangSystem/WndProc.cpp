//  [1/11/2017 ����]
//  ���ڹ���WndProc.cpp

#include "stdafx.h"

//  ����: ���ڹ��̺���,�Դ�����Ϣ���д���
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_KEYDOWN:                        //������Ϣ
        if (wParam == VK_ESCAPE)
            PostQuitMessage(0);
        break;
    case WM_LBUTTONDOWN:                    //��������Ϣ
        if (!g_bCanAttact)
        {
            int x = LOWORD(lParam);         //x����
            int y = LOWORD(lParam);         //y����

            if (x >= 0 && x <= CHESSBOARD_SIZE && y >= 0 && y <= CHESSBOARD_SIZE)
            {
                g_bCanAttact = true;
                Player_Play();
            }
        }
        break;
    case WM_DESTROY:                        //���Ǵ���������Ϣ
        Game_ShutDown(hWnd);                //�˳�ǰ������Դ
        PostQuitMessage(0);                 //��ϵͳ�����и��߳�����ֹ����
        break;
    default://������case������������,����Ĭ�ϴ���
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    return 0;//�����˳�
}
