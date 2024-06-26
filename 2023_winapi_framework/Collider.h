#pragma once
class Object;

class Collider
{
public:
	Collider();
	Collider(const Collider& _origin);
	~Collider();
	Collider& operator = (Collider& _origin) = delete;
public:
	void FinalUpdate(bool isUI);
	void Render(HDC _dc, bool isUI);
public:
	void EnterCollision();
	void ExitCollision();
	void StayCollision();
public:
	void SetScale(Vec2 _vScale) { m_vScale = _vScale; }
	void SetOffSetPos(Vec2 _vOffsetPos) 
	{ m_vOffsetPos = _vOffsetPos; }
	void SetEnable(bool value) { isEnable = value; }
	const Vec2& GetScale() const { return m_vScale; }
	const Vec2& GetOffSetPos() const { return m_vOffsetPos; }
	const Vec2& GetFinalPos() const 
	{ return m_vFinalPos; }
	const UINT& GetID() const { return m_ID; }
	const Object* GetObj() const { return m_pOwner; }
	const bool GetIsEnable() const { return isEnable; }
private:
	UINT m_check;
	Object* m_pOwner;
	Vec2 m_vOffsetPos; // 오프셋
	Vec2 m_vFinalPos; // 파이널 위치
	Vec2 m_vScale; // 크기
	bool isEnable;
	friend class Object;
	UINT m_ID; // 충돌체 ID값
	static UINT m_sNextID;
};

