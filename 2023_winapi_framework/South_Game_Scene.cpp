#include "pch.h"
#include "South_Game_Scene.h"
#include "UIObject.h"
#include "InventoryUI.h"
#include "Core.h"
#include "SceneUI.h"
#include "CollisionMgr.h"
#include "CameraMgr.h"
#include "Door.h"
#include "FlowerPot.h"
#include "UnusedObj.h"
#include "DoorLock.h"
#include "TouchTextObject.h"

void South_Game_Scene::Init()
{
	Object* background = new UnusedObj(L"back2");
	Vec2 gameSize = Core::GetInst()->GetGamgeScreen();
	background->SetPos({ gameSize.x * 0.5f,gameSize.y * 0.5f });
	background->SetScale({ gameSize.x, gameSize.y });
	AddObject(background, RENDER_ORDER::BACKGROUND);

	SceneUI* ui = GetSceneUI();
	CameraMgr::GetInst()->Init();

	Door* door = new Door();

	Vec2 doorPos = Vec2({ Core::GetInst()->GetResolution().x / 2 - 300, Core::GetInst()->GetResolution().y / 2 + 100 });
	door->SetPos(doorPos);
	door->SetScale(Vec2(450.f, 450.f));
	AddObject(door, RENDER_ORDER::ONE);

	DoorLock* pDoorLock = new DoorLock(doorPos + Vec2({ 175.f,0.f }), Vec2(50.f, 80.f),this);
	door->SetDoorLock(pDoorLock);
	AddObject(pDoorLock, RENDER_ORDER::TWO);
	

	Object* pObj = new UnusedObj(L"bookshelf");
	Vec2 shelfPos({ Core::GetInst()->GetResolution().x / 2 + 125, Core::GetInst()->GetResolution().y / 2 + 200 });
	pObj->SetPos(shelfPos);
	pObj->SetScale(Vec2(400.f, 260.f));
	AddObject(pObj, RENDER_ORDER::ONE);

	vector<wstring> shelfText({L"»õ½Ï + ºû + ¹°", L"ÀÌ°Ç ¹» ÀÇ¹ÌÇÏ´Â °É±î"});
	TouchTextObject* textObj = new TouchTextObject(shelfText, false);
	textObj->SetHint(true);
	textObj->SetPos((shelfPos) + Vec2(0, 14));
	textObj->SetScale(Vec2(120, 80));
	AddObject(textObj, RENDER_ORDER::TWO);

	pObj = new FlowerPot();
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 + 270, Core::GetInst()->GetResolution().y / 2 +20 })));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, RENDER_ORDER::TWO);


}

