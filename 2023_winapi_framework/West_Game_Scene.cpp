#include "pch.h"
#include "West_Game_Scene.h"
#include "UIObject.h"
#include "InventoryUI.h"
#include "Core.h"
#include "SceneUI.h"
#include "CollisionMgr.h"
#include "Lockers.h"
#include "CameraMgr.h"

void West_Game_Scene::Init()
{
	SceneUI* ui = GetSceneUI();
	CameraMgr::GetInst()->Init();
	Object* pObj = new Lockers(this, 100, Vec2({ Core::GetInst()->GetResolution().x / 2 - 200, Core::GetInst()->GetResolution().y - 250 }));
	AddObject(pObj);



	InventoryUI* invenUI = new InventoryUI(L"asd");
	Vec2 pos = Vec2({ Core::GetInst()->GetResolution().x - 100, Core::GetInst()->GetResolution().y / 2 });
	Vec2 scale = Vec2({ (LONG)200.f, Core::GetInst()->GetResolution().y });
	invenUI->Init(pos,scale);
	SceneUI::AddDontDestroyUI(invenUI, UI_RENDER_ORDER::INVENTORY);
}
