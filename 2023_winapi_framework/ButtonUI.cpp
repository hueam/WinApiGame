#include "pch.h"
#include "ButtonUI.h"
#include "KeyMgr.h"
#include "SceneMgr.h"

ButtonUI::ButtonUI()
	:m_bisEnter(false)
	, m_bisMouseDown(false)
{
	CreateCollider();
}

ButtonUI::ButtonUI(wstring textureName) 
	: UIObject(L"Bullet", textureName)
	, m_bisEnter(false)
	,m_bisMouseDown(false)
{
	CreateCollider();
}

ButtonUI::~ButtonUI()
{

}

void ButtonUI::Update()
{
	if (KEY_DOWN(KEY_TYPE::LBUTTON) && m_bisEnter == true)
	{
		m_bisMouseDown = true;
	}
	if (KEY_UP(KEY_TYPE::LBUTTON)&& m_bisMouseDown == true)
	{
		SceneMgr::GetInst()->LoadScene(L"Game_Scene");
	}
}

void ButtonUI::EnterCollision()
{
	m_bisEnter = true;
}

void ButtonUI::ExitCollision()
{
	m_bisEnter = false;
	m_bisMouseDown = false;
}