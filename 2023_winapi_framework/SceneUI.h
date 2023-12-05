#pragma once
class UIObject;
class SceneUI
{
public:
	SceneUI();
	~SceneUI();
public:
	void Update();
	void FinalUpdate();
	void Render(HDC _dc);
	void Release();

	void AddUI(UIObject* _pUI, UI_RENDER_ORDER type)
	{
		m_vecUI[(int)type].push_back(_pUI);
	}
	static void AddDontDestroyUI(UIObject* _pUI, UI_RENDER_ORDER type)
	{
		m_vecDontDestroyUI[(int)type].push_back(_pUI);
	}
	const vector<UIObject*> GetVecUI(UI_RENDER_ORDER type) { return m_vecUI[(int)type]; }
public:
	static vector<UIObject*> m_vecDontDestroyUI[(int)UI_RENDER_ORDER::END];
private:
	vector<UIObject*> m_vecUI[(int)UI_RENDER_ORDER::END];
};

