#pragma once

class Object;
class CameraMgr
{
	SINGLE(CameraMgr);
public:
	void Init();
	void SetScale(const int scale);
	void SetPos(const Vec2 pos);
	void SetFocusingObj(Object* obj);
	void AddPos(const int x, const int y);
	Vec2& AdjustPos(Vec2& pos);
	Vec2& AdjustScale(Vec2& scale);

	const void AddWindoeCnt() { windowCnt++; };
	//const Vec2& GetPos() const { return m_vCamPos; }
	//const Vec2& GetScale() const { return m_vCamScale; }
	const Object* GetFocusingObj() { return m_pFocusingObj; }
	const bool GetisZoom() const { return isZoom;}
private:
	Vec2 m_vCamPos;
	Vec2 m_vCamScale;
	bool isZoom;
	int windowCnt;
	Object* m_pFocusingObj;
};

