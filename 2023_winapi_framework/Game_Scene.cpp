#include "pch.h"
#include "Game_Scene.h"
#include "UIObject.h"
#include "InventoryUI.h"
#include "Core.h"
#include "SceneUI.h"
#include "CollisionMgr.h"

void Game_Scene::Init()
{
	SceneUI* ui = GetSceneUI();
	UIObject* pUIObj = new InventoryUI(L"asd");
	pUIObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x - 100, Core::GetInst()->GetResolution().y / 2})));
	pUIObj->SetScale(Vec2({ (LONG)200.f, Core::GetInst()->GetResolution().y }));
	ui->AddUI(pUIObj);
}
void Game_Scene::Update()
{
	Scene::Update();
	//if(KEY_DOWN(KEY_TYPE::ENTER))
	//	// ¾À º¯°æ
}

void Game_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Game_Scene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
