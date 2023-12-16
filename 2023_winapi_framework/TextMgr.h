#pragma once
#include<queue>

class Blend;
class TextMgr
{
	SINGLE(TextMgr)
public:
	void Init();
	void Update();
	void Render(HDC _dc);
	void SetText(wstring txt);
	void SetRect(RECT& newRect);

	void SetLookHint(bool value) { lookHint = value; }
	bool& GetLookHint() { return lookHint; }
	bool& GetEnable() { return isEnable; }
private:
	RECT rect;
	bool isEnable;
	bool lookHint;
	std::queue<wstring> txt;
	Blend* background;
};

