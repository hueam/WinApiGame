#pragma once
class Collider;
union COLLIDER_ID
{
	struct
	{
		UINT left_ID;
		//UINT right_ID;
	};
	ULONGLONG ID;
};
class CollisionMgr
{
	SINGLE(CollisionMgr);
public:
	void Update();
private:
	void CollisionGroupUpdate();
	void UICollisionUpdate();
	//void CollisionGroupUpdate(OBJECT_GROUP _eLeft, OBJECT_GROUP _eRight);
	//bool IsCollision(Collider* _pLeft, Collider* _pRight);
	bool IsCollision(Collider* _pLeft, bool isUI);
private:
	// 그룹간의 충돌체크할 배열
	map<ULONGLONG, bool> m_mapColInfo;
};

