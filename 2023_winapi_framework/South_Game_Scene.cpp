#include "pch.h"
#include "South_Game_Scene.h"
#include "UIObject.h"
#include "InventoryUI.h"
#include "Core.h"
#include "SceneUI.h"
#include "CollisionMgr.h"
#include "TestItem.h"
#include "CameraMgr.h"
#include "Door.h"
#include "Bookshelf.h"
#include "BackGround.h"
#include "FlowerPot.h"

void South_Game_Scene::Init()
{
	Object* background = new BackGround(L"Background", L"back2");
	Vec2 gameSize = Core::GetInst()->GetGamgeScreen();
	background->SetPos({ gameSize.x * 0.5f,gameSize.y * 0.5f });
	background->SetScale({ gameSize.x, gameSize.y });
	AddObject(background, RENDER_ORDER::ONE);

	SceneUI* ui = GetSceneUI();
	CameraMgr::GetInst()->Init();

	Object* pObj = new Door();
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 - 300, Core::GetInst()->GetResolution().y / 2 + 100})));
	pObj->SetScale(Vec2(450.f, 450.f));
	AddObject(pObj, RENDER_ORDER::ONE);

	pObj = new Bookshelf();
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 + 125, Core::GetInst()->GetResolution().y / 2 + 200 })));
	pObj->SetScale(Vec2(400.f, 260.f));
	AddObject(pObj, RENDER_ORDER::ONE);

	pObj = new FlowerPot();
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 + 270, Core::GetInst()->GetResolution().y / 2 +36 })));
	pObj->SetScale(Vec2(50.f, 70.f));
	AddObject(pObj, RENDER_ORDER::TWO);


}

