#include "pch.h"
#include "Lockers.h"
#include "Scene.h"
#include "Locker.h"
#include "WaterBottle.h"
#include "Post.h"

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
			curScene->AddObject(temp, RENDER_ORDER::ONE);
			if (b)
			{
				Post* post = new Post(temp);
				post->SetPos(Vec2(x, y));
				post->SetScale(Vec2(50, 65));
				curScene->AddObject(post, RENDER_ORDER::TWO);
			}
			if (j == 0 && i == 1)
			{
				WaterBottle* bottle = new WaterBottle();
				bottle->SetOwner(temp);
				bottle->SetPos(Vec2(x, y + lockerSize * 0.2f));
				bottle->SetScale(Vec2(20.f, lockerSize * 0.5f));
				curScene->AddObject(bottle, RENDER_ORDER::TWO);
			}
		}
	}
}

Lockers::~Lockers()
{
}
