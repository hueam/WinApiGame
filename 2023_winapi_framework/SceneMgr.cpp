#include "pch.h"
#include "SceneMgr.h"
#include "Start_Scene.h"
#include "West_Game_Scene.h"
#include "North_Game_Scene.h"
#include "East_Game_Scene.h"
#include "South_Game_Scene.h"
void SceneMgr::Init()
{
	m_pCurScene = nullptr;
	// ¾À µî·Ï
	RegisterScene(L"Start_Scene", std::make_shared<Start_Scene>());
	RegisterScene(L"West_Game_Scene", std::make_shared<West_Game_Scene>());
	RegisterScene(L"North_Game_Scene", std::make_shared<North_Game_Scene>());
	RegisterScene(L"East_Game_Scene", std::make_shared<East_Game_Scene>());
	RegisterScene(L"South_Game_Scene", std::make_shared<South_Game_Scene>());

	// Ã¹ ¾À ÁöÁ¤
	LoadScene(L"Start_Scene");
}

void SceneMgr::Update()
{
	m_pCurScene->Update();
	m_pCurScene->FinalUpdate();
}

void SceneMgr::Render(HDC _dc)
{
	m_pCurScene->Render(_dc);
}

void SceneMgr::LoadScene(const wstring& _scenename)
{
	// ¾ÀÀÌ ÀÖÀ¸¸é
	if (m_pCurScene != nullptr)
	{
		m_pCurScene->Release();
		m_pCurScene = nullptr;
	}

	auto iter = m_mapScenes.find(_scenename);
	if (iter != m_mapScenes.end())
	{
		m_pCurScene = iter->second;
		m_pCurScene->Init();
	}
}
void SceneMgr::InitScene(const wstring& _scenename)
{
	auto iter = m_mapScenes.find(_scenename);
	if (iter != m_mapScenes.end())
	{
		iter->second->Init();
	}
}

void SceneMgr::ChangeScene(bool isAdd)
{
	if (m_pCurScene != nullptr)
	{
		m_pCurScene = nullptr;
	}
	if (isAdd)
	{
		currentScene = (currentScene + 1) % 4;
	}
	else
	{
		if (currentScene - 1 < 0)
		{
			currentScene = 4;
		}
		currentScene -= 1;
	}

	auto iter = m_mapScenes.find(gameSceneArr[currentScene]);
	if (iter != m_mapScenes.end())
	{
		m_pCurScene = iter->second;
	}
}

void SceneMgr::RegisterScene(const wstring& _scenename, std::shared_ptr<Scene> _scene)
{
	m_mapScenes.insert(m_mapScenes.end(), { _scenename, _scene });
}
