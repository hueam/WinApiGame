#pragma once

enum class KEY_STATE
{
	// NONE: �ȴ���
	// DOWN: �� ����
	// UP: ��
	// PRESS: ��������
	NONE, DOWN, UP, PRESS
};

enum class KEY_TYPE
{
	LEFT, RIGHT, UP, DOWN,
	Q,W,E,R,T,Y,U,I,O,P,
	A,S,D,F,G,H,J,K,L,
	Z,X,C,V,B,N,M,
	CTRL, LALT, LSHIFT, SPACE,
	ENTER, TAB, ESC, LBUTTON, RBUTTON, LAST
	// LAST�ǹ�: ���̶�� ���̾�
};

enum class ITEM_TYPE
{
	TEST,
	KEY,
	WATER,
	POT,
	END
};
enum class RENDER_ORDER
{
	ONE,
	TWO,
	THREE,
	END
};
enum class UI_RENDER_ORDER
{
	BACKGROUND,
	INVENTORY,
	SLOT,
	ITEM,
	POPUP,
	BUTTON,
	END = 6
};

enum class GAME_SCENE_TYPE
{
	WEST,
	NORTH,
	EAST,
	SOUTH
};

enum class PEN_TYPE
{
	HOLLOW, RED, GREEN, 
	BLUE, YELLOW, END
};

enum class BRUSH_TYPE
{
	HOLLOW, RED, GREEN,
	BLUE, YELLOW, END
};

enum class EVENT_TYPE
{
	DELETE_OBJECT,
	CREATE_OBJECT,
	SCENE_CHANGE,
	END
};