#pragma once

class CameraMgr
{
	SINGLE(CameraMgr);
public:
	void Init();
	void SetScale(const int scale) { m_vCamScale = Vec2(scale, scale); }
	void SetPos(const Vec2 pos);
	void AddPos(const int x, const int y);
	const Vec2& GetPos() const { return m_vCamPos; }
	const Vec2& GetScale() const { return m_vCamScale; }
private:
	Vec2 m_vCamPos;
	Vec2 m_vCamScale;
};

