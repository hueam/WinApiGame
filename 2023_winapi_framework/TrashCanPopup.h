#pragma once
#include "PopUpTexture.h"

class TrashCanPopup
	: public PopUpTexture
{
public:
	TrashCanPopup(Vec2 pos,Vec2 scale, wstring key, wstring textureName);
	~TrashCanPopup();
};

