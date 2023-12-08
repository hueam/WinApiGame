#include "pch.h"
#include "North_Game_Scene.h"
#include "UIObject.h"
#include "InventoryUI.h"
#include "Core.h"
#include "SceneUI.h"
#include "CollisionMgr.h"
#include "Window.h"
#include "CameraMgr.h"

void North_Game_Scene::Init()
{
	SceneUI* ui = GetSceneUI();
	CameraMgr::GetInst()->Init();
	Object* pObj = new Window();
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(350.f, 300.f));
	AddObject(pObj);
}
