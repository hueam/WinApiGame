#include "pch.h"
#include "Post.h"
#include "ResMgr.h"
#include "Locker.h"
#include "Collider.h"
#include "KeyMgr.h"
#include "CameraMgr.h"
#include "Texture.h"
#include "Core.h"

Post::Post(Locker* owner)
	:isEnter(false)
{
	this->owner = owner;
	m_pTex = ResMgr::GetInst()->TexLoad(L"Post", L"Texture\\Post.bmp");

	CreateCollider();
}

Post::~Post()
{
}

void Post::Update()
{
	Collider* col = GetCollider();
	col->SetEnable(owner->GetIsOpen());
	if (KEY_DOWN(KEY_TYPE::LBUTTON) && isEnter)
	{
		CameraMgr::GetInst()->SetPos(m_vPos);
		CameraMgr::GetInst()->SetScale(3);
		CameraMgr::GetInst()->SetFocusingObj(this);
	}
}

void Post::Render(HDC _dc)
{
	if (!owner->GetIsOpen()) return;
	Vec2 vPos = GetPos();
	Vec2 vScale = GetScale();
	Vec2 vCamPos = CameraMgr::GetInst()->GetPos();
	Vec2 vCamScale = CameraMgr::GetInst()->GetScale();
	Vec2 vMinusCamScale = CameraMgr::GetInst()->GetScale();
	vMinusCamScale.x -= 1;
	vMinusCamScale.y -= 1;

	Vec2 vRenderPos = vPos - vCamPos;
	Vec2 vRenderScale = vScale * vCamScale;

	Vec2 vResolution = Core::GetInst()->GetResolution();
	vResolution.x = vResolution.x / 2;
	vResolution.y = vResolution.y / 2;
	vRenderPos = vRenderPos + (vRenderPos - vResolution) * vMinusCamScale;

	int Width = m_pTex->GetWidth();
	int Height = m_pTex->GetHeight();

	int x = (int)(vRenderPos.x - vRenderScale.x / 2);
	int y = (int)(vRenderPos.y - vRenderScale.y / 2);
	TransparentBlt(_dc
		, x
		, y
		, vRenderScale.x, vRenderScale.y, m_pTex->GetDC()
		, 0, 0, Width, Height, RGB(255, 0, 255));

	Component_Render(_dc);
}

void Post::EnterCollision()
{
	isEnter = true;
}

void Post::ExitCollision()
{
	isEnter = false;
}
