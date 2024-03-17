#include "pch.h"
#include "West_Game_Scene.h"
#include "UIObject.h"
#include "InventoryUI.h"
#include "Core.h"
#include "SceneUI.h"
#include "CollisionMgr.h"
#include "Lockers.h"
#include "CameraMgr.h"
#include "TrashCan.h"
#include "TextMgr.h"
#include "UnusedObj.h"

void West_Game_Scene::Init()
{
	//SceneMgr::GetInst()->InitScene(L"East_Game_Scene");
	//SceneMgr::GetInst()->InitScene(L"North_Game_Scene");
	//SceneMgr::GetInst()->InitScene(L"South_Game_Scene");

	Vec2 winSize = Core::GetInst()->GetGamgeScreen();
	RECT rt{ 0,winSize.y - 200, winSize.x, winSize.y };
	TextMgr::GetInst()->SetRect(rt);


	Object* background = new UnusedObj(L"back2");
	Vec2 gameSize = Core::GetInst()->GetGamgeScreen();
	background->SetPos({ gameSize.x * 0.5f,gameSize.y * 0.5f });
	background->SetScale({ gameSize.x, gameSize.y });
	AddObject(background, RENDER_ORDER::ONE);

	CameraMgr::GetInst()->Init();
	Lockers lockers(this, 100, Vec2({ Core::GetInst()->GetResolution().x / 2 - 200, Core::GetInst()->GetResolution().y - 250 }));
	Object* tc = new TrashCan();
	tc->SetPos(Vec2({ Core::GetInst()->GetResolution().x / 2 - 500, Core::GetInst()->GetResolution().y - 150 }));
	tc->SetScale(Vec2({ 150,200 }));
	AddObject(tc, RENDER_ORDER::ONE);

	TextMgr::GetInst()->SetText(L"여기가 어디지?");
	TextMgr::GetInst()->SetText(L"학교..?");
	TextMgr::GetInst()->SetText(L"아무도 깨워주지 않았네...");
	TextMgr::GetInst()->SetText(L"일단 돌아가자...");


	InventoryUI* invenUI = new InventoryUI(L"asd");
	Vec2 pos = Vec2({ Core::GetInst()->GetResolution().x - 100, Core::GetInst()->GetResolution().y / 2 });
	Vec2 scale = Vec2({ (LONG)200.f, Core::GetInst()->GetResolution().y });
	invenUI->Init(pos, scale);
	SceneUI::AddDontDestroyUI(invenUI, UI_RENDER_ORDER::INVENTORY);
}
