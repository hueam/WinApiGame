#include "pch.h"
#include "North_Game_Scene.h"
#include "UIObject.h"
#include "InventoryUI.h"
#include "Core.h"
#include "SceneUI.h"
#include "CollisionMgr.h"
#include "TestItem.h"
#include "CameraMgr.h"

void North_Game_Scene::Init()
{
	SceneUI* ui = GetSceneUI();
	CameraMgr::GetInst()->Init();
	Object* pObj = new TestItem();
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj);
	pObj = new TestItem();
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2+100, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj);

}
