#include "pch.h"
#include "CollisionMgr.h"
#include "SceneMgr.h"
#include "Object.h"
#include "Scene.h"
#include "Collider.h"
#include "KeyMgr.h"
#include "SceneUI.h"
#include "UIObject.h"
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
	UICollisionUpdate();
}
void CollisionMgr::CollisionGroupUpdate(OBJECT_GROUP _eLeft)
{
	std::shared_ptr<Scene> pCurScene = SceneMgr::GetInst()->GetCurScene();
	const vector<Object*>& vecLeft = pCurScene->GetGroupObject(_eLeft);
	//const vector<Object*>& vecRight = pCurScene->GetGroupObject(_eRight);
	// �浹 �˻縦 �غ���.
	for (size_t i = 0; i < vecLeft.size(); ++i)
	{
		// �浹ü�� ���� ���
		if (vecLeft[i]->GetCollider() == nullptr)
			continue;
		Collider* pLeftCol = vecLeft[i]->GetCollider();
		COLLIDER_ID colID;
		colID.left_ID = pLeftCol->GetID();
		//colID.right_ID = pRightCol->GetID();

			// ã�ƶ�.
		auto iter = m_mapColInfo.find(colID.ID);
		// �����
		if (iter == m_mapColInfo.end())
		{
			// �־��
			m_mapColInfo.insert({ colID.ID, false });
			// ������ ��ƶ�.
			iter = m_mapColInfo.find(colID.ID);
		}
		// �浹�ϳ�?
		if (IsCollision(pLeftCol))
		{
			// �������� �浹 ��
			if (iter->second)
			{
				// ���� �ϳ� ���� �����̶��
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
			// ������ �浹x
			else
			{
				//if()
				pLeftCol->EnterCollision();
				iter->second = true;
			}
		}
		// ���ϳ�?
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

void CollisionMgr::UICollisionUpdate()
{
	std::shared_ptr<Scene> pCurScene = SceneMgr::GetInst()->GetCurScene();
	const vector<UIObject*>& vecLeft = pCurScene->GetSceneUI()->GetVecUI();
	//const vector<Object*>& vecRight = pCurScene->GetGroupObject(_eRight);
	// �浹 �˻縦 �غ���.
	for (size_t i = 0; i < vecLeft.size(); ++i)
	{
		// �浹ü�� ���� ���
		if (vecLeft[i]->GetCollider() == nullptr)
			continue;
		Collider* pLeftCol = vecLeft[i]->GetCollider();
		COLLIDER_ID colID;
		colID.left_ID = pLeftCol->GetID();
		//colID.right_ID = pRightCol->GetID();

			// ã�ƶ�.
		auto iter = m_mapColInfo.find(colID.ID);
		// �����
		if (iter == m_mapColInfo.end())
		{
			// �־��
			m_mapColInfo.insert({ colID.ID, false });
			// ������ ��ƶ�.
			iter = m_mapColInfo.find(colID.ID);
		}
		// �浹�ϳ�?
		if (IsCollision(pLeftCol))
		{
			// �������� �浹 ��
			if (iter->second)
			{
				// ���� �ϳ� ���� �����̶��
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
			// ������ �浹x
			else
			{
				//if()
				pLeftCol->EnterCollision();
				iter->second = true;
			}
		}
		// ���ϳ�?
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

void CollisionMgr::CheckReset()
{
	memset(m_arrCheck, 0, sizeof(UINT) * (UINT)(OBJECT_GROUP::END));
}

