#include "pch.h"
#include "Start_Scene.h"
#include "Object.h"
#include "Item.h"
#include "Core.h"
#include "KeyMgr.h"
#include "CollisionMgr.h"
#include "ResMgr.h"
#include "UIObject.h"
#include "ButtonUI.h"
#include "SceneUI.h"
#include "Collider.h"
#include "CameraMgr.h"
#include "TextMgr.h"
#include "SceneMgr.h"
#include "UnusedObj.h"

void Start_Scene::Init()
{
	CameraMgr::GetInst()->Init();

	SceneUI* ui = GetSceneUI();
	UIObject* pUIObj = new ButtonUI(L"start_btn");
	pUIObj->SetPos((Vec2({Core::GetInst()->GetResolution().x /2 + 300, Core::GetInst()->GetResolution().y / 2 + 200})));
	pUIObj->SetScale(Vec2(750.f,250.f)); // 3:1
	ui->AddUI(pUIObj, UI_RENDER_ORDER::BUTTON);

	Object* background = new UnusedObj(L"game_title");
	Vec2 gameSize = Core::GetInst()->GetResolution();
	Vec2 winSize = Core::GetInst()->GetResolution();
	background->SetPos({ gameSize.x * 0.5f,gameSize.y * 0.5f });
	background->SetScale({ gameSize.x, gameSize.y });
	AddObject(background, RENDER_ORDER::BACKGROUND);

	//Vec2 vResolution = Core::GetInst()->GetResolution();
	//Monster* pMonster = nullptr;
	//int iMonster = 10;		// 몬스터 수 
	//float fMoveDist = 30.f; // 움직일 거리
	//float fMonsterScale = 50.f; // 몬스터 크기
	//// 해상도x - ( 움직일 거리 + 오브젝트 크기 /2) * 2 / 몬스터수 -1 
	//float fTerm = (vResolution.x - (fMoveDist + fMonsterScale / 2.f) * 2) 
	//				/ (float)(iMonster -1);
	//for (int i = 0; i < iMonster; ++i)
	//{
	//	pMonster = new Monster;
	//	pMonster->SetPos(Vec2(
	//		(fMoveDist + fMonsterScale / 2.f) + i* fTerm
	//		,300.f));
	//	pMonster->SetScale(Vec2(fMonsterScale, fMonsterScale));
	//	pMonster->SetCenterPos(pMonster->GetPos());
	//	pMonster->SetMoveDis(fMoveDist);
	//	AddObject(pMonster, OBJECT_GROUP::MONSTER);
	//}
	// 사운드 세팅
	ResMgr::GetInst()->LoadSound(L"BGM", L"Sound\\background.wav", true);
	ResMgr::GetInst()->LoadSound(L"Click", L"Sound\\click.wav", false);
 	ResMgr::GetInst()->LoadSound(L"NumPad", L"Sound\\beep.wav", false);
 	ResMgr::GetInst()->LoadSound(L"door_close", L"Sound\\door_close.wav", false);
 	ResMgr::GetInst()->LoadSound(L"door_open", L"Sound\\door_open.wav", false);
 	ResMgr::GetInst()->LoadSound(L"locker_open", L"Sound\\locker_close.wav", false);
 	ResMgr::GetInst()->LoadSound(L"locker_close", L"Sound\\locker_open.wav", false);
 	ResMgr::GetInst()->LoadSound(L"water", L"Sound\\water.wav", false);
 	ResMgr::GetInst()->LoadSound(L"window", L"Sound\\window.wav", false);

	ResMgr::GetInst()->Play(L"BGM");

}

void Start_Scene::Update()
{
	Scene::Update();
	//if (KEY_DOWN(KEY_TYPE::ENTER))
	//	SceneMgr::GetInst()->LoadScene(L"West_Game_Scene");
	//	// 씬 변경
}

void Start_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Start_Scene::Release()
{
	Scene::Release();
}
