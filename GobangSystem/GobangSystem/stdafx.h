//  [1/11/2017 ����]
//  stdafx.hͷ�ļ����ڼ���ͷ�ļ�
//                    �궨��
//                    ���ļ���������
//                    ����ȫ�ֱ���
//                    ȫ�ֺ�������
#pragma once

//ͷ�ļ�����
#include <windows.h>
#include <tchar.h>
#include <time.h>

#pragma comment(lib,"Msimg32.lib")                  //����TransparentBlt����������ļ�

//�궨��
#define WINDOWS_WIDTH      800                         //���ڿ��
#define WINDOWS_HEIGHT     600                         //���ڸ߶�
#define WINDOWS_TITLE      L"�γ����-������"          //��-���ڱ���
#define CHESSBOARD_SIZE    15                          //���̴�С
#define WINDOWS_CLASS_NAME L"GobangGameSystem"         //��������

//ȫ�ֽṹ��

//ȫ�ֱ�������
HDC g_hdc = NULL, g_mdc = NULL, g_bufdc = NULL;     //ȫ���豸���������ȫ���ڴ�DC���
DWORD g_tPre = 0, g_tNow = 0;                       //���������������ڼ�¼��ͼʱ��
RECT g_rect;                                        //����һ��RECT�ṹ��,���ڴ����ڲ���������
int g_iFrameNum, g_iTxtNum;                         //֡������������
wchar_t text[8][10];                                //������������ַ�������
BOOL g_bCanAttact, g_bGameOver;                     //��Ϸ����״̬,����Ƿ��������,��Ϸ�Ƿ����

//ȫ�ֺ�������
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);        //���ڹ��̺���
BOOL Game_Init(HWND hWnd);                                                              //��Ϸ��Դ��ʼ��
VOID Game_Main(HWND hWnd);                                                              //��Ϸ��ͼ
BOOL Game_ShutDown(HWND hWnd);                                                          //�ڴ˺����н�����Դ����
VOID Game_Over(int x, int y, bool win);                                                 //��Ϸʤ�����
VOID Player_Play();                                                                     //����Ƿ���������ж�
