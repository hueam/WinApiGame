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

void South_Game_Scene::Init()
{
	SceneUI* ui = GetSceneUI();
	CameraMgr::GetInst()->Init();
	Object* pObj = new TestItem();
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj,RENDER_ORDER::ONE);

	pObj = new Door();
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 - 300, Core::GetInst()->GetResolution().y / 2 + 50})));
	pObj->SetScale(Vec2(450.f, 450.f));
	AddObject(pObj, RENDER_ORDER::ONE);

	pObj = new Bookshelf();
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 + 125, Core::GetInst()->GetResolution().y / 2 + 145 })));
	pObj->SetScale(Vec2(400.f, 260.f));
	AddObject(pObj, RENDER_ORDER::ONE);

}

