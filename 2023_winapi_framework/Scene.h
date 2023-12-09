#pragma once
//#include "Object.h"
class Object;
class SceneUI;
class Scene
{
public:
	Scene();
	virtual ~Scene();
	// Init(), Update(), Render(), Release();
	virtual void Init() abstract;
	virtual void Update();
	virtual void FinalUpdate();
	virtual void Render(HDC _dc);
	virtual void Release();
public:
	const vector<Object*>& GetGroupObject(RENDER_ORDER type) const
	{
		return m_vecObj[(int)type];
	}
public:
	void AddObject(Object* _pObj, RENDER_ORDER type)
	{
		m_vecObj[(int)type].push_back(_pObj);
	}
	SceneUI* GetSceneUI()
	{
		return ui;
	}

private:
//	Object*  m_obj;
	vector<Object*> m_vecObj[(int)RENDER_ORDER::END];
	SceneUI* ui;
};

