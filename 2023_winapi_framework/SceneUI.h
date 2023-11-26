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

	void AddUI(UIObject* _pUI)
	{
		m_vecUI.push_back(_pUI);
	}
	const vector<UIObject*> GetVecUI() { return m_vecUI; }
private:
	vector<UIObject*> m_vecUI;
};

