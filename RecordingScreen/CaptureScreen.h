#ifndef _CCAPTURE_SCREEN_HH
#define _CCAPTURE_SCREEN_HH

#include<time.h>
#include <d3d9.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <windows.h>

#include <tchar.h>
#include <winbase.h>
#include <winreg.h>
#include <Strsafe.h>


//
// ---ץ����----
//
class CCaptureScreen
{
public:
	CCaptureScreen(void);
	~CCaptureScreen(void);

public:
	/*-----------�����ⲿ���ú���-----------*/
	int Init(int&, int&);//��ʼ��
	BYTE* CaptureImage(); //ץȡ��Ļ

private:
	/*-----------�����ڲ����ú���-----------*/
	void* CaptureScreenFrame(int, int, int, int);//ץ��
	HCURSOR FetchCursorHandle(); //��ȡ�����

private:
	/*-----------����˽�б���-----------*/
	int m_width;
	int m_height;
	UINT   wLineLen;
	DWORD  dwSize;
	DWORD  wColSize;

	//�豸���
	HDC hScreenDC;
	HDC hMemDC;
	//ͼ��RGB�ڴ滺��
	PRGBTRIPLE m_hdib;
	//λͼͷ��Ϣ�ṹ��
	BITMAPINFO pbi;

	HBITMAP hbm;
	//�����
	HCURSOR m_hSavedCursor;


};

#endif //--_CCAPTURE_SCREEN_HH