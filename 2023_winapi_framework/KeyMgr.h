#pragma once
#include "define.h"

struct tKeyInfo
{
	KEY_STATE eState; // 키 상태
	bool	  IsPrevCheck; // 이전에 눌렸냐
};

class Item;
class Object;
class KeyMgr // InputMgr
{
	SINGLE(KeyMgr);
private:
	vector<tKeyInfo> m_vecKey;
	int m_arrVKKey[(int)KEY_TYPE::LAST] =
	{ VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN, 'Q' , 'W','E','R',
	'T','Y','U','I','O','P',
	'A','S','D','F','G','H','J','K','L',
	'Z','X','C','V','B','N','M',
	VK_CONTROL, VK_LMENU, VK_LSHIFT, VK_SPACE,
		VK_RETURN, VK_TAB, VK_ESCAPE, VK_LBUTTON, VK_RBUTTON };

	POINT m_ptMouse;
	bool isEnterCollision = false;
	Object* m_pHighOrdering;
	Item* m_pPickItem;
public:
	void Init();
	void Update();
public:
	const KEY_STATE& GetKey(KEY_TYPE _eKey) const
	{
		return m_vecKey[(int)_eKey].eState;
	}
	const POINT& GetMousePos() const 
	{
		return m_ptMouse;
	}
	const void SetIsCollision(const bool value)
	{
		isEnterCollision = value;
	}
	const void SetHightObject(Object* value)
	{
		m_pHighOrdering = value;
	}
	const Object* GetCurHIghObject()
	{
		return m_pHighOrdering;
	}
	const void SetPickUpItem(Item* value)
	{
		m_pPickItem = value;
	}
	Item* GetPickUpItem()
	{
		return m_pPickItem;
	}
};

