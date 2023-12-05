#pragma once
#include "Object.h"
class Texture;
class UIObject
	: public Object
{
public:
	UIObject();
	UIObject(const wstring& key, const wstring& textureName);
	~UIObject();
public:
	void Update() override;
	void Render(HDC _dc) override;
	void Component_Render(HDC _dc) override;
	void FinalUpdate() override;
protected:
	Texture* m_pTex;
};

