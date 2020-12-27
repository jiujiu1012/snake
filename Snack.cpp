#include "pch.h"

#include "framework.h"

#include "MFCsnack.h"

#include "MFCsnackDlg.h"

#include "Snack.h"



#ifdef _DEBUG

#define new DEBUG_NEW

#endif



CSnake::CSnake()

{

	// ��ʼ���ߵĳ���Ϊ1�� �����˶��� ͷ��λ��Ϊ(10, 10)

	len = 1;

	direc = 4; // ��������1,2,3,4

	body[0].x = 10;

	body[0].y = 10;

}



CSnake::~CSnake()

{

}



void CSnake::UpMove()

{

	for (int i = len - 1; i > 0; --i) {

		body[i].x = body[i - 1].x;

		body[i].y = body[i - 1].y;

	}

	body[0].x--;

	direc = 1;

}



void CSnake::DownMove()

{

	for (int i = len - 1; i > 0; --i) {

		body[i].x = body[i - 1].x;

		body[i].y = body[i - 1].y;

	}

	body[0].x++;

	direc = 2;

}



void CSnake::LeftMove()

{

	for (int i = len - 1; i > 0; --i) {

		body[i].x = body[i - 1].x;

		body[i].y = body[i - 1].y;

	}

	body[0].y--;

	direc = 3;

}



void CSnake::RightMove()

{

	for (int i = len - 1; i > 0; --i) {

		body[i].x = body[i - 1].x;

		body[i].y = body[i - 1].y;

	}

	body[0].y++;

	direc = 4;

}



void CSnake::init()

{

	body[0].x = 10;

	body[0].y = 10;

	len = 1;

	direc = 4;

}