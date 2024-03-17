#pragma once
#include "Scene.h"
class End_Scene :
	public Scene
{
	virtual void Init() override;
	virtual void Update() override;
	void GotoStartSecne();
private:
	bool isEnd;
};

