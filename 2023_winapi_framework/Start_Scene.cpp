#include "pch.h"
#include "Start_Scene.h"
#include "Object.h"
#include "Item.h"
#include "TestItem.h"
#include "Core.h"
#include "KeyMgr.h"
#include "CollisionMgr.h"
#include "ResMgr.h"
#include "UIObject.h"
#include "ButtonUI.h"
#include "SceneUI.h"
#include "Collider.h"
#include "CameraMgr.h"
void Start_Scene::Init()
{
	CameraMgr::GetInst()->Init();
	Object* pObj = new TestItem();
	pObj->SetPos((Vec2({Core::GetInst()->GetResolution().x /2, Core::GetInst()->GetResolution().y / 2})));
	pObj->SetScale(Vec2(100.f,100.f));
	AddObject(pObj, OBJECT_GROUP::ITEM);
	pObj = new TestItem();
	pObj->SetPos((Vec2({ Core::GetInst()->GetResolution().x / 2 + 100, Core::GetInst()->GetResolution().y / 2 })));
	pObj->SetScale(Vec2(100.f, 100.f));
	AddObject(pObj, OBJECT_GROUP::ITEM);

	SceneUI* ui = GetSceneUI();
	UIObject* pUIObj = new ButtonUI(L"Bullet");
	pUIObj->SetPos((Vec2({Core::GetInst()->GetResolution().x /2, Core::GetInst()->GetResolution().y / 2 + 300})));
	pUIObj->SetScale(Vec2(300.f,100.f));
	ui->AddUI(pUIObj);
	//// ���� ���� �������� ��ġ�� �غ��ô�.

	//Vec2 vResolution = Core::GetInst()->GetResolution();
	//Monster* pMonster = nullptr;
	//int iMonster = 10;		// ���� �� 
	//float fMoveDist = 30.f; // ������ �Ÿ�
	//float fMonsterScale = 50.f; // ���� ũ��
	//// �ػ�x - ( ������ �Ÿ� + ������Ʈ ũ�� /2) * 2 / ���ͼ� -1 
	//float fTerm = (vResolution.x - (fMoveDist + fMonsterScale / 2.f) * 2) 
	//				/ (float)(iMonster -1);
	//for (int i = 0; i < iMonster; ++i)
	//{
	//	pMonster = new Monster;
	//	pMonster->SetPos(Vec2(
	//		(fMoveDist + fMonsterScale / 2.f) + i* fTerm
	//		,300.f));
	//	pMonster->SetScale(Vec2(fMonsterScale, fMonsterScale));
	//	pMonster->SetCenterPos(pMonster->GetPos());
	//	pMonster->SetMoveDis(fMoveDist);
	//	AddObject(pMonster, OBJECT_GROUP::MONSTER);
	//}
	// ���� ����
	ResMgr::GetInst()->LoadSound(L"BGM", L"Sound\\Retro_bgm.wav", true);
 	ResMgr::GetInst()->LoadSound(L"Shoot", L"Sound\\laserShoot.wav", false);
	ResMgr::GetInst()->Play(L"BGM");

}

void Start_Scene::Update()
{
	Scene::Update();
	//if(KEY_DOWN(KEY_TYPE::ENTER))
	//	// �� ����
}

void Start_Scene::Render(HDC _dc)
{
	Scene::Render(_dc);
}

void Start_Scene::Release()
{
	Scene::Release();
	CollisionMgr::GetInst()->CheckReset();
}
