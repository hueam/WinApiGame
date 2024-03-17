#include "pch.h"
#include "End_Scene.h"
#include "SceneMgr.h"
#include "TextMgr.h"
#include "Core.h"
#include "ResMgr.h"
#include <functional>

void End_Scene::Init()
{
	ResMgr::GetInst()->Stop(SOUND_CHANNEL::BGM);
	Vec2 winSize = Core::GetInst()->GetResolution();
	RECT rect{ 0,0,winSize.x,winSize.y };
	TextMgr::GetInst()->SetRect(rect);
	TextMgr::GetInst()->SetText(L"그렇게 학교를 빠져나와 집으로 돌아갔다.");
	isEnd = true;
}

void End_Scene::Update()
{
	Scene::Update();
	if (isEnd&& !TextMgr::GetInst()->GetEnable())
	{
		isEnd = false;
		std::function<void()> func = std::bind(&End_Scene::GotoStartSecne,this);
		SceneMgr::GetInst()->FadeIn(func);
	}
}

void End_Scene::GotoStartSecne()
{
	SceneMgr::GetInst()->LoadScene(L"Start_Scene");
}
