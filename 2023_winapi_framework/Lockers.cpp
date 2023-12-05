#include "pch.h"
#include "Lockers.h"
#include "Scene.h"
#include "Locker.h"

Lockers::Lockers(Scene* curScene, float lockerSize, Vec2 pos)
{
	m_vPos = pos;
	Vec2 lockPos(m_vPos.x - lockerSize * 0.5f, m_vPos.y - lockerSize * 0.5f);
	for (int i = 4; i >= 0; i--)
	{
		float x = lockPos.x + lockerSize * i;
		for (int j = 2; j >= 0; j--)
		{
			bool b = i == 2 && j == 0;
			float y = lockPos.y + lockerSize * j;
			Locker* temp = new Locker();
			temp->SetScale(Vec2(lockerSize, lockerSize));
			temp->SetPos(Vec2(x, y));
			temp->SetIsPost(b);
			temp->SetIsLocked(b);
			objArr[i][j] = temp;
			curScene->AddObject(temp);
		}
	}
}

Lockers::~Lockers()
{
}
