#include "pch.h"
#include "Game_Scene.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "CameraMgr.h"
#include "Blend.h"
#include <functional>
#include "TextMgr.h"

void Game_Scene::Init()
{
}

void Game_Scene::Update()
{
	Scene::Update();
	if (!CameraMgr::GetInst()->GetisZoom()&& !TextMgr::GetInst()->GetEnable()&& !SceneMgr::GetInst()->GetFadeRunning())
	{
		if (KEY_DOWN(KEY_TYPE::D))
		{
			std::function<void()> func;
			func = std::bind(&Game_Scene::ChangeAftetScene,this);
			SceneMgr::GetInst()->FadeIn(func);
		}
		if (KEY_DOWN(KEY_TYPE::A))
		{
			std::function<void()> func;
			func = std::bind(&Game_Scene::ChangeBeforeScene,this);
			SceneMgr::GetInst()->FadeIn(func);
		}
	}
}

void Game_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);

}

void Game_Scene::Release()
{
	Scene::Release();
}

void Game_Scene::ChangeBeforeScene()
{
	SceneMgr::GetInst()->ChangeScene(true);
}

void Game_Scene::ChangeAftetScene()
{
	SceneMgr::GetInst()->ChangeScene(false);
}