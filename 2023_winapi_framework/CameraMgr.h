#pragma once

class Object;
class CameraMgr
{
	SINGLE(CameraMgr);
public:
	void Init();
	void SetScale(const int scale) { m_vCamScale = Vec2(scale, scale); }
	void SetPos(const Vec2 pos);
	void SetFocusingObj(Object* obj);
	void AddPos(const int x, const int y);
	const void AddWindoeCnt() { windowCnt++; };
	const Vec2& GetPos() const { return m_vCamPos; }
	const Vec2& GetScale() const { return m_vCamScale; }
	const Object* GetFocusingObj() { return m_pFocusingObj; }
private:
	Vec2 m_vCamPos;
	Vec2 m_vCamScale;
	bool isZoom;
	int windowCnt;
	Object* m_pFocusingObj;
};

