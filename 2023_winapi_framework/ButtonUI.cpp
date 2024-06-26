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
	: UIObject(L"StartBtn", textureName)
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
		SceneMgr::GetInst()->LoadScene(L"West_Game_Scene");
		SceneMgr::GetInst()->InitScene(L"East_Game_Scene");
		SceneMgr::GetInst()->InitScene(L"North_Game_Scene");
		SceneMgr::GetInst()->InitScene(L"South_Game_Scene");
	}
}

void ButtonUI::EnterCollision()
{
	m_bisEnter = true;
	curScale = GetScale(); // 현재 스케일
	SetScale({ curScale.x + 60,curScale.y + 20 });
}

void ButtonUI::ExitCollision()
{
	m_bisEnter = false;
	m_bisMouseDown = false;
	curScale = GetScale();
	SetScale({ curScale.x - 60,curScale.y - 20 });
}