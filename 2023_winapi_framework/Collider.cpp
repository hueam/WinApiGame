#include "pch.h"
#include "Collider.h"
#include "Object.h"
#include "SelectGDI.h"
UINT Collider::m_sNextID = 0;
Collider::Collider()
	: m_pOwner(nullptr)
	, m_vScale(Vec2(50.f,50.f))
	, m_ID(m_sNextID++)
	, m_check(0)
	, m_vFinalPos{}
{
	//Collider a, b;
	//a = b;
}

Collider::Collider(const Collider& _origin)
	: m_pOwner(nullptr)
	, m_vScale(_origin.m_vScale)
	, m_vOffsetPos(_origin.m_vOffsetPos)
	, m_ID(m_sNextID++)
	, m_check(0)
	, m_vFinalPos{}
{
}

Collider::~Collider()
{}

void Collider::Render(HDC _dc)
{
	//Core::GetInst()->GetPen(PEN_TYPE::GREEN);
	//Core::GetInst()->GetBrush(BRUSH_TYPE::HOLLOW);
	//SelectObject();
	PEN_TYPE ePen = PEN_TYPE::GREEN;
	if (m_check)
		ePen = PEN_TYPE::RED;
	SelectGDI pen(_dc, ePen);
	SelectGDI brush(_dc, BRUSH_TYPE::HOLLOW);
	Vec2 vObjScale = m_pOwner->GetScale();

	RECT_RENDER(m_vFinalPos.x, m_vFinalPos.y, vObjScale.x, vObjScale.y, _dc);
}

void Collider::EnterCollision()
{
 	++m_check;
	m_pOwner->EnterCollision();
}

void Collider::ExitCollision()
{
	--m_check;
	m_pOwner->ExitCollision();
}

void Collider::StayCollision()
{
	m_pOwner->StayCollision();
}

void Collider::FinalUpdate()
{
	// Object��ġ�� ���󰡾� �ϴ°ž�.
	Vec2 vObjPos = m_pOwner->GetPos();
	m_vFinalPos = vObjPos/* + m_vOffsetPos*/;
}

