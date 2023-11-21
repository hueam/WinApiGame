#include "pch.h"
#include "CollisionMgr.h"
#include "SceneMgr.h"
#include "Object.h"
#include "Scene.h"
#include "Collider.h"
#include "KeyMgr.h"
void CollisionMgr::Update()
{
	for (UINT Row = 0; Row < (UINT)OBJECT_GROUP::END; ++Row)
	{
		//if (m_arrCheck[Row] & (1 << Col))
		{
			//CollisionGroupUpdate((OBJECT_GROUP)Row, (OBJECT_GROUP)Col);
			CollisionGroupUpdate((OBJECT_GROUP)Row);
		}
	}
}
void CollisionMgr::CollisionGroupUpdate(OBJECT_GROUP _eLeft)
{
	std::shared_ptr<Scene> pCurScene = SceneMgr::GetInst()->GetCurScene();
	const vector<Object*>& vecLeft = pCurScene->GetGroupObject(_eLeft);
	//const vector<Object*>& vecRight = pCurScene->GetGroupObject(_eRight);
	// 충돌 검사를 해보자.
	for (size_t i = 0; i < vecLeft.size(); ++i)
	{
		// 충돌체가 없는 경우
		if (vecLeft[i]->GetCollider() == nullptr)
			continue;
		Collider* pLeftCol = vecLeft[i]->GetCollider();
		COLLIDER_ID colID;
		colID.left_ID = pLeftCol->GetID();
		//colID.right_ID = pRightCol->GetID();

			// 찾아라.
		auto iter = m_mapColInfo.find(colID.ID);
		// 없어용
		if (iter == m_mapColInfo.end())
		{
			// 넣어라
			m_mapColInfo.insert({ colID.ID, false });
			// 넣은거 잡아라.
			iter = m_mapColInfo.find(colID.ID);
		}
		// 충돌하네?
		if (IsCollision(pLeftCol))
		{
			// 이전에도 충돌 중
			if (iter->second)
			{
				// 둘중 하나 삭제 예정이라면
				if (vecLeft[i]->GetIsDead())
				{
					pLeftCol->ExitCollision();
					iter->second = false;
				}
				else
				{
					pLeftCol->StayCollision();
				}
			}
			// 이전에 충돌x
			else
			{
				//if()
				pLeftCol->EnterCollision();
				iter->second = true;
			}
		}
		// 안하네?
		else
		{
			if (iter->second)
			{
				pLeftCol->ExitCollision();
				iter->second = false;
			}
		}
	}
}


bool CollisionMgr::IsCollision(Collider* _pLeft)
{
	// 충돌검사 알고리즘
	// AABB 
	POINT posPoint = KeyMgr::GetInst()->GetMousePos();

	Vec2 vLeftPos = _pLeft->GetFinalPos();
	Vec2 vLeftScale = _pLeft->GetScale();
	if ((vLeftPos.x + vLeftScale.x * 0.5f) > posPoint.x && (vLeftPos.x - vLeftScale.x * 0.5f) < posPoint.x)
	{
		if ((vLeftPos.y + vLeftScale.y * 0.5f) > posPoint.y && (vLeftPos.y - vLeftScale.y * 0.5f) < posPoint.y)
			return true;
	}

	return false;
}

void CollisionMgr::CheckGroup(OBJECT_GROUP _eLeft, OBJECT_GROUP _eRight)
{
	// 작은쪽을 행으로 씁시다.
	UINT Row = (UINT)_eLeft;
	UINT Col = (UINT)_eRight;
	Row = min(Row, Col);

	//// 비트 연산
	// 체크가 되어있다면
	if (m_arrCheck[Row] & (1 << Col))
	{
		m_arrCheck[Row] &= ~(1 << Col);
	}
	// 체크가 안되어있다면r
	else
	{
		m_arrCheck[Row] |= (1 << Col);
	}
}

void CollisionMgr::CheckReset()
{
	memset(m_arrCheck, 0, sizeof(UINT) * (UINT)(OBJECT_GROUP::END));
}

