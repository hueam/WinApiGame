#include "pch.h"
#include "North_Game_Scene.h"
#include "UIObject.h"
#include "InventoryUI.h"
#include "Core.h"
#include "SceneUI.h"
#include "CollisionMgr.h"
#include "Window.h"
#include "CameraMgr.h"
#include "UnusedObj.h"

void North_Game_Scene::Init()
{
	Object* background = new UnusedObj(L"back2");
	Vec2 gameSize = Core::GetInst()->GetGamgeScreen();
	background->SetPos({ gameSize.x * 0.5f,gameSize.y * 0.5f });
	background->SetScale({ gameSize.x, gameSize.y });
	AddObject(background, RENDER_ORDER::BACKGROUND);

	CameraMgr::GetInst()->Init();

	Object* pObj = new Window(false);
	pObj->SetPos((Vec2({ Core::GetInst()->GetGamgeScreen().x / 2 + 250, Core::GetInst()->GetGamgeScreen().y / 2 })));
	pObj->SetScale(Vec2(410.f, 300.f));
	AddObject(pObj,RENDER_ORDER::ONE);

	pObj = new Window(true);
	pObj->SetPos((Vec2({ Core::GetInst()->GetGamgeScreen().x / 2 - 250, Core::GetInst()->GetGamgeScreen().y / 2 })));
	pObj->SetScale(Vec2(410.f, 300.f));
	AddObject(pObj, RENDER_ORDER::ONE);

	pObj = new UnusedObj(L"clock");
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 - 95, Core::GetInst()->GetResolution().y / 2 - 200 })));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, RENDER_ORDER::ONE);
}
