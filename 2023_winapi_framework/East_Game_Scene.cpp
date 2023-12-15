#include "pch.h"
#include "East_Game_Scene.h"
#include "UIObject.h"
#include "InventoryUI.h"
#include "Core.h"
#include "SceneUI.h"
#include "CollisionMgr.h"
#include "UnusedObj.h"
#include "CameraMgr.h"
#include "TouchTextObject.h"

void East_Game_Scene::Init()
{
	Object* background = new UnusedObj(L"back2");
	Vec2 gameSize = Core::GetInst()->GetGamgeScreen();
	Vec2 winSize = Core::GetInst()->GetResolution();
	background->SetPos({ gameSize.x * 0.5f,gameSize.y * 0.5f });
	background->SetScale({ gameSize.x, gameSize.y });
	AddObject(background, RENDER_ORDER::BACKGROUND);

	Vec2 smallBoradPos = { winSize.x / 2 + 100, winSize.y / 2 - 70 };
	Object* pObj = new UnusedObj(L"small_board");
	pObj->SetPos((Vec2(smallBoradPos)));
	pObj->SetScale(Vec2(195.f, 320.f));
	AddObject(pObj, RENDER_ORDER::ONE);

	vector<wstring>hinText({ L"칠판... 사물함... 창문... 식물...", L"이 순서인가.." });
	pObj = new TouchTextObject(hinText, true);
	pObj->SetPos((Vec2(smallBoradPos) + Vec2(40, 20)));
	pObj->SetScale(Vec2(75.f, 100.f));
	AddObject(pObj, RENDER_ORDER::TWO);


	Vec2 boradPos({ winSize.x / 2 - 250, winSize.y / 2 - 70 });
	Vec2 boradScale(560.f, 320.f);
	pObj = new UnusedObj(L"board");
	pObj->SetPos(boradPos);
	pObj->SetScale(boradScale);
	AddObject(pObj, RENDER_ORDER::ONE);

	vector<wstring>boardText({ L"파랑이 하나...", L"빨강이 여섯...",L"초록은 알 수 없음..?", L"뭘 의미하는 거지..?" });
	TouchTextObject* textObj = new TouchTextObject(boardText, false);
	textObj->SetHint(true);
	textObj->SetPos((boradPos + boradScale * 0.5f)- Vec2(60, 60));
	textObj->SetScale(Vec2(50, 50));
	AddObject(textObj, RENDER_ORDER::TWO);

	pObj = new UnusedObj(L"teachingdesk");
	pObj->SetPos((Vec2({ winSize.x / 2 - 350, winSize.y / 2 + 180 })));
	pObj->SetScale(Vec2(250.f, 350.f));
	AddObject(pObj, RENDER_ORDER::ONE);
}
