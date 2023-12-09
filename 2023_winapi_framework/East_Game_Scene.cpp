#include "pch.h"
#include "East_Game_Scene.h"
#include "UIObject.h"
#include "InventoryUI.h"
#include "Core.h"
#include "SceneUI.h"
#include "CollisionMgr.h"
#include "TestItem.h"
#include "Board.h"
#include "CameraMgr.h"

void East_Game_Scene::Init()
{
	SceneUI* ui = GetSceneUI();
	CameraMgr::GetInst()->Init();
	Object* pObj = new TestItem();
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj,RENDER_ORDER::ONE);
	pObj = new TestItem();
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2+100, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, RENDER_ORDER::ONE);
	pObj = new TestItem();
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2, Core::GetInst()->GetResolution().y / 2+100 })));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, RENDER_ORDER::ONE);

	pObj = new Board();
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 - 300, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(700.f, 400.f));
	AddObject(pObj);

}
