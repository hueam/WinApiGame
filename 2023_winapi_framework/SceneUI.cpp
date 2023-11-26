#include "pch.h"
#include "SceneUI.h"
#include "UIObject.h"

SceneUI::SceneUI()
{
}

SceneUI::~SceneUI()
{
	Release();
}

void SceneUI::Update()
{
	for (size_t i = 0; i < m_vecUI.size(); ++i)
	{
		m_vecUI[i]->Update();
	}
}
void SceneUI::FinalUpdate()
{
	for (size_t i = 0; i < m_vecUI.size(); ++i)
	{
		m_vecUI[i]->FinalUpdate();
	}
}

void SceneUI::Render(HDC _dc)
{
	for (size_t i = 0; i < m_vecUI.size(); ++i)
	{
		m_vecUI[i]->Render(_dc);
	}
}

void SceneUI::Release()
{
	for (size_t i = 0; i < m_vecUI.size(); ++i)
	{
		delete m_vecUI[i];
	}
	m_vecUI.clear();
}
