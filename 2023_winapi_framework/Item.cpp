#include "pch.h"
#include "Item.h"
#include "ResMgr.h"
#include "Collider.h"
#include "Texture.h"

Item::Item(ITEM_TYPE type)
{
	m_itmeType = type;
}

Item::~Item()
{
}