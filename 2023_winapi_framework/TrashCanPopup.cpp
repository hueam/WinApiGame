#include "pch.h"
#include "TrashCanPopup.h"
#include "Key.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "SceneUi.h"

TrashCanPopup::TrashCanPopup(Vec2 pos, Vec2 scale, wstring key, wstring textureName):PopUpTexture(scale,key,textureName)
{
	SetPos(pos);

	Key* newKey = new Key(L"Key", L"trashcan_key",this);
	newKey->SetPos(pos);
	newKey->SetScale(scale);
	SceneMgr::GetInst()->GetCurScene()->GetSceneUI()->AddDontDestroyUI(newKey, UI_RENDER_ORDER::BUTTON);

}

TrashCanPopup::~TrashCanPopup()
{
}
