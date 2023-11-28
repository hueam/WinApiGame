#pragma once
#include "Object.h";
class Texture;
class Item 
{
public:
	Item(ITEM_TYPE type);
	~Item();
protected:
	ITEM_TYPE m_itmeType;
};

