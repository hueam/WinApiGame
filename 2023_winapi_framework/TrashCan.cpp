#include "pch.h"
#include "TrashCan.h"
#include "KeyMgr.h"
#include "CameraMgr.h"
#include "Texture.h"
#include "ResMgr.h"
#include "TrashCanPopup.h"
#include "SceneMgr.h"
#include "Scene.h"
#include "SceneUI.h"
#include "Core.h"

TrashCan::TrashCan()
	:isEnter(false)
{
	m_pTex = ResMgr::GetInst()->TexLoad(L"TrashCan", L"Texture\\trashcan.bmp");
	Vec2 screenScale = Core::GetInst()->GetGamgeScreen();
	m_pTrashCanPopup = new TrashCanPopup( screenScale * 0.5f ,Vec2(700, 700), L"TrashcanPopup", L"trashcan_zoom_nocover");
	SceneMgr::GetInst()->GetCurScene()->GetSceneUI()->AddDontDestroyUI(m_pTrashCanPopup, UI_RENDER_ORDER::POPUP);
	CreateCollider();
}

TrashCan::~TrashCan()
{
}

void TrashCan::FinalUpdate()
{
	Object::FinalUpdate();
	if (KeyMgr::GetInst()->GetCurHIghObject() == this)
	{
		if (KEY_DOWN(KEY_TYPE::LBUTTON))
		{
			if (CameraMgr::GetInst()->GetFocusingObj() == this)
			{
				m_pTrashCanPopup->Open();
			}
			else if (isEnter)
			{
				CameraMgr::GetInst()->SetPos(m_vPos + Vec2(0, -20));
				CameraMgr::GetInst()->SetScale(3);
				CameraMgr::GetInst()->SetFocusingObj(this);
			}
		}
	}
}

void TrashCan::Render(HDC _dc)
{
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();

	Vec2 vRenderPos = CameraMgr::GetInst()->AdjustPos(vPos);
	Vec2 vRenderScale = CameraMgr::GetInst()->AdjustScale(vScale);

	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	int x = (int)(vRenderPos.x - vRenderScale.x / 2);
	int y = (int)(vRenderPos.y - vRenderScale.y / 2);
	//x *= (int)(vCamScale.x /2);
	//y *= (int)(vCamScale.x /2);  
	//ELLIPSE_RENDER(vPos.x, vPos.y, vScale.x, vScale.y, _dc);
	TransparentBlt(_dc
		, x
		, y
		, vRenderScale.x, vRenderScale.y, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));
	/*TransparentBlt(_dc
		, vPos.x
		, vPos.y
		, Width, Height, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));*/

	Component_Render(_dc);
	//if (isEnter)
		//TextOut(_dc, x, y, name.c_str(), name.size());
}

void TrashCan::EnterCollision()
{
	isEnter = true;
}

void TrashCan::ExitCollision()
{
	isEnter = false;
}
