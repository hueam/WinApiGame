#include "pch.h"
#include "SceneUI.h"
#include "UIObject.h"

SceneUI::SceneUI()
{
}

SceneUI::~SceneUI()
{

}
vector<UIObject*> SceneUI::m_vecDontDestroyUI[(int)UI_RENDER_ORDER::END];
void SceneUI::Update()
{
	for (size_t i = 0; i < (int)UI_RENDER_ORDER::END; i++)
	{
		for (size_t j = 0; j < m_vecUI[i].size(); ++j)
		{
			if (m_vecUI[i][j]->GetIsDead()) return;
			m_vecUI[i][j]->Update();
		}
		for (size_t j = 0; j < SceneUI::m_vecDontDestroyUI[i].size(); ++j)
		{
			if (SceneUI::m_vecDontDestroyUI[i][j]->GetIsDead()) return;
			SceneUI::m_vecDontDestroyUI[i][j]->Update();
		}
	}
}
void SceneUI::FinalUpdate()
{
	for (size_t i = 0; i < (int)UI_RENDER_ORDER::END; i++)
	{
		for (size_t j = 0; j < m_vecUI[i].size(); ++j)
		{
			m_vecUI[i][j]->FinalUpdate();
		}
		for (size_t j = 0; j < SceneUI::m_vecDontDestroyUI[i].size(); ++j)
		{
			SceneUI::m_vecDontDestroyUI[i][j]->FinalUpdate();
		}
	}
}

void SceneUI::Render(HDC _dc)
{
	for (size_t i = 0; i < (int)UI_RENDER_ORDER::END; i++)
	{
		for (size_t j = 0; j < m_vecUI[i].size(); ++j)
		{
			if (m_vecUI[i][j]->GetIsDead()) m_vecUI[i].erase(m_vecUI[i].begin() + j);
			else m_vecUI[i][j]->Render(_dc);
		}
		for (size_t j = 0; j < SceneUI::m_vecDontDestroyUI[i].size(); ++j)
		{
			if (SceneUI::m_vecDontDestroyUI[i][j]->GetIsDead()) SceneUI::m_vecDontDestroyUI[i].erase(SceneUI::m_vecDontDestroyUI[i].begin() + j);
			else SceneUI::m_vecDontDestroyUI[i][j]->Render(_dc);
		}
	}
}

void SceneUI::Release()
{
	for (size_t i = 0; i < (int)UI_RENDER_ORDER::END; i++)
	{
		for (size_t j = 0; j < m_vecUI[i].size(); ++j)
		{
			delete m_vecUI[i][j];
			m_vecUI[i].erase(m_vecUI[i].begin() + j);
		}
		m_vecUI[i].clear(); 
	}
}
