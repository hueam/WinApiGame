#include "pch.h"
#include "SceneMgr.h"
#include "Start_Scene.h"
#include "West_Game_Scene.h"
#include "North_Game_Scene.h"
#include "East_Game_Scene.h"
#include "South_Game_Scene.h"
#include "End_Scene.h"
#include "Core.h"

void SceneMgr::Init()
{
	m_pCurScene = nullptr;
	// ¾À µî·Ï
	RegisterScene(L"Start_Scene", std::make_shared<Start_Scene>());
	RegisterScene(L"West_Game_Scene", std::make_shared<West_Game_Scene>());
	RegisterScene(L"North_Game_Scene", std::make_shared<North_Game_Scene>());
	RegisterScene(L"East_Game_Scene", std::make_shared<East_Game_Scene>());
	RegisterScene(L"South_Game_Scene", std::make_shared<South_Game_Scene>());
	RegisterScene(L"End_Scene", std::make_shared<End_Scene>());

	Vec2 size = Core::GetInst()->GetResolution();
	RECT rt{0,0,size.x,size.y};
	m_pFadeIn = new Blend(rt, 0, 255, 0.5f, new BLENDFUNCTION());
	m_pFadeOut = new Blend(rt, 255, 0, 0.5f, new BLENDFUNCTION());
	m_pFadeOut->StartBlend();
	//m_pFadeIn->StartBlend();

	// Ã¹ ¾À ÁöÁ¤
	LoadScene(L"Start_Scene");
}

void SceneMgr::Update()
{
	m_pCurScene->Update();
	m_pCurScene->FinalUpdate();
	m_pFadeIn->Update();
	m_pFadeOut->Update();
}

void SceneMgr::Render(HDC _dc)
{
	m_pCurScene->Render(_dc);
	m_pFadeIn->Render(_dc);
	m_pFadeOut->Render(_dc);
}

void SceneMgr::LoadScene(const wstring& _scenename)
{
	// ¾ÀÀÌ ÀÖÀ¸¸é
	currentScene = 0;
	if (m_pCurScene != nullptr)
	{
		m_pCurScene->Release();
		m_pCurScene = nullptr;
	}

	auto iter = m_mapScenes.find(_scenename);
	if (iter != m_mapScenes.end())
	{
		m_pCurScene = iter->second;
		FadeOut();
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

void SceneMgr::ReleaseScene(const wstring& _scenename)
{
	auto iter = m_mapScenes.find(_scenename);
	if (iter != m_mapScenes.end())
	{
		iter->second->Release();
	}
}

void SceneMgr::ChangeScene(bool isAdd)
{
	//m_pFadeIn->Reset();
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
		FadeOut();
	}
}

void SceneMgr::FadeIn(std::function<void()>& func)
{
	m_pFadeIn->SetEndEvnet(func);
	m_pFadeIn->StartBlend();
}

void SceneMgr::FadeIn()
{
	m_pFadeIn->CleanEvent();
	m_pFadeIn->StartBlend();
}

void SceneMgr::FadeOut(std::function<void()>& func)
{
	m_pFadeOut->SetEndEvnet(func);
	m_pFadeOut->StartBlend();
}

void SceneMgr::FadeOut()
{
	m_pFadeOut->CleanEvent();
	m_pFadeOut->StartBlend();
}

void SceneMgr::RegisterScene(const wstring& _scenename, std::shared_ptr<Scene> _scene)
{
	m_mapScenes.insert(m_mapScenes.end(), { _scenename, _scene });
}
