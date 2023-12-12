#include "pch.h"
#include "East_Game_Scene.h"
#include "UIObject.h"
#include "InventoryUI.h"
#include "Core.h"
#include "SceneUI.h"
#include "CollisionMgr.h"
#include "TestItem.h"
#include "UnusedObj.h"
#include "CameraMgr.h"

void East_Game_Scene::Init()
{
	Object* pObj = new UnusedObj(L"small_board");
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 + 100, Core::GetInst()->GetResolution().y / 2 - 70 })));
	pObj->SetScale(Vec2(195.f, 320.f));
	AddObject(pObj, RENDER_ORDER::ONE);

	pObj = new UnusedObj(L"board");
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 - 250, Core::GetInst()->GetResolution().y / 2 - 70})));
	pObj->SetScale(Vec2(560.f, 320.f));
	AddObject(pObj, RENDER_ORDER::ONE);

	pObj = new UnusedObj(L"teachingdesk");
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 - 350, Core::GetInst()->GetResolution().y / 2 + 180})));
	pObj->SetScale(Vec2(250.f, 350.f));
	AddObject(pObj, RENDER_ORDER::ONE);
}
