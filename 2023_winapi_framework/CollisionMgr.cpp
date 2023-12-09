#include "pch.h"
#include "CollisionMgr.h"
#include "SceneMgr.h"
#include "Object.h"
#include "Scene.h"
#include "Collider.h"
#include "KeyMgr.h"
#include "SceneUI.h"
#include "UIObject.h"
#include "CameraMgr.h"
#include "Core.h"
void CollisionMgr::Update()
{
	CollisionGroupUpdate();
	UICollisionUpdate();
}
void CollisionMgr::CollisionGroupUpdate()
{
	std::shared_ptr<Scene> pCurScene = SceneMgr::GetInst()->GetCurScene();
	bool isEnterCollider = false;
	Object* highObj = nullptr;
	for (size_t i = 0; i < (int)RENDER_ORDER::END; i++)
	{

		const vector<Object*>& vecLeft = pCurScene->GetGroupObject((RENDER_ORDER)i);
		//const vector<Object*>& vecRight = pCurScene->GetGroupObject(_eRight);
		// �浹 �˻縦 �غ���.
		for (size_t j = 0; j < vecLeft.size(); ++j)
		{
			// �浹ü�� ���� ���
			if (vecLeft[j]->GetCollider() == nullptr)
				continue;
			Collider* pLeftCol = vecLeft[j]->GetCollider();
			if (!pLeftCol->GetIsEnable()) continue;
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
			bool collision = IsCollision(pLeftCol, false);
			isEnterCollider |= collision;
			if (collision)
			{
				highObj = vecLeft[j];
				// �������� �浹 ��
				if (iter->second)
				{
					// ���� �ϳ� ���� �����̶��
					if (vecLeft[j]->GetIsDead())
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
	KeyMgr::GetInst()->SetIsCollision(isEnterCollider);
	KeyMgr::GetInst()->SetHightObject(highObj);

}

void CollisionMgr::UICollisionUpdate()
{
	std::shared_ptr<Scene> pCurScene = SceneMgr::GetInst()->GetCurScene();
	Object* highObj = nullptr;
	bool isEnterCollider = false;
	for (size_t i = 0; i < (int)UI_RENDER_ORDER::END; i++)
	{

		const vector<UIObject*>& vecLeft = pCurScene->GetSceneUI()->GetVecUI((UI_RENDER_ORDER)i);
		//const vector<Object*>& vecRight = pCurScene->GetGroupObject(_eRight);

		// �浹 �˻縦 �غ���.
		for (size_t j = 0; j < vecLeft.size(); ++j)
		{
			// �浹ü�� ���� ���
			if (vecLeft[j]->GetCollider() == nullptr)
				continue;
			Collider* pLeftCol = vecLeft[j]->GetCollider();
			if (!pLeftCol->GetIsEnable()) continue;

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
			bool collision = IsCollision(pLeftCol, true);
			isEnterCollider |= collision;
			if (collision)
			{
				highObj = vecLeft[j];
				// �������� �浹 ��
				if (iter->second)
				{
					// ���� �ϳ� ���� �����̶��
					if (vecLeft[j]->GetIsDead())
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
		const vector<UIObject*>& vecDonDestroy = SceneUI::m_vecDontDestroyUI[i];
		//const vector<Object*>& vecRight = pCurScene->GetGroupObject(_eRight);
		// �浹 �˻縦 �غ���.
		for (size_t i = 0; i < vecDonDestroy.size(); ++i)
		{
			// �浹ü�� ���� ���
			if (vecDonDestroy[i]->GetCollider() == nullptr)
				continue;
			Collider* pLeftCol = vecDonDestroy[i]->GetCollider();
			if (!pLeftCol->GetIsEnable()) continue;
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
			bool collision = IsCollision(pLeftCol, true);
			isEnterCollider |= collision;
			if (collision)
			{
				highObj = vecDonDestroy[i];

				// �������� �浹 ��
				if (iter->second)
				{
					// ���� �ϳ� ���� �����̶��
					if (vecDonDestroy[i]->GetIsDead())
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
	if(isEnterCollider)
		KeyMgr::GetInst()->SetIsCollision(isEnterCollider);
	if(highObj != nullptr)
		KeyMgr::GetInst()->SetHightObject(highObj);
}



bool CollisionMgr::IsCollision(Collider* _pLeft, bool isUI)
{
	POINT posPoint = KeyMgr::GetInst()->GetMousePos();

	Vec2 vPos = _pLeft->GetFinalPos();
	Vec2 vScale = _pLeft->GetScale();

	Vec2 vCamScale = CameraMgr::GetInst()->GetScale();

	Vec2 vRenderScale = vScale * vCamScale;
	if (isUI)
	{
		if ((vPos.x + vScale.x * 0.5f) > posPoint.x && (vPos.x - vScale.x * 0.5f) < posPoint.x)
		{
			if ((vPos.y + vScale.y * 0.5f) > posPoint.y && (vPos.y - vScale.y * 0.5f) < posPoint.y)
				return true;
		}
	}
	else
	{
		if ((vPos.x + vRenderScale.x * 0.5f) > posPoint.x && (vPos.x - vRenderScale.x * 0.5f) < posPoint.x)
		{
			if ((vPos.y + vRenderScale.y * 0.5f) > posPoint.y && (vPos.y - vRenderScale.y * 0.5f) < posPoint.y)
				return true;
		}
	}


	return false;
}