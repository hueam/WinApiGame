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
	Object* pObj = new UnusedObj(L"board");
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 - 250, Core::GetInst()->GetResolution().y / 2 - 40})));
	pObj->SetScale(Vec2(560.f, 320.f));
	AddObject(pObj, RENDER_ORDER::ONE);
	
	pObj = new UnusedObj(L"small_board");
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 + 102, Core::GetInst()->GetResolution().y / 2 - 50})));
	pObj->SetScale(Vec2(205.f, 320.f));
	AddObject(pObj, RENDER_ORDER::ONE);

	pObj = new UnusedObj(L"teachingdesk");
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(250.f, 350.f));
	AddObject(pObj, RENDER_ORDER::ONE);
}
