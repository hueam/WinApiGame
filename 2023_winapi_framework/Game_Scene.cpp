#include "pch.h"
#include "Game_Scene.h"
#include "CollisionMgr.h"
#include "KeyMgr.h"
#include "SceneMgr.h"
#include "CameraMgr.h"

void Game_Scene::Init()
{
}

void Game_Scene::Update()
{
	Scene::Update();
	if (KEY_DOWN(KEY_TYPE::D))
		SceneMgr::GetInst()->ChangeScene(true);
	if (KEY_DOWN(KEY_TYPE::A))
		SceneMgr::GetInst()->ChangeScene(false);
	if (KEY_DOWN(KEY_TYPE::SPACE))
		CameraMgr::GetInst()->SetScale(3);
}

void Game_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Game_Scene::Release()
{
	Scene::Release();
}
