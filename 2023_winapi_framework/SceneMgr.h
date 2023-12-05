#pragma once
class Scene;
class SceneMgr
{
	SINGLE(SceneMgr);
public:
	void Init();
	void Update();
	void Render(HDC _dc);
public:
	void LoadScene(const wstring& _scenename);
	void InitScene(const wstring& _scenename);
	void RegisterScene(const wstring& _scenename, std::shared_ptr<Scene> _scene);
	void ChangeScene(bool isAdd);
public:
	const std::shared_ptr<Scene>& GetCurScene() const
	{
		return m_pCurScene;
	}
private:
	int currentScene = 0;
	// ����Ʈ ������
	std::shared_ptr<Scene> m_pCurScene; // ���� ��
	// ������ �����ϴ� ��.
	map<wstring, std::shared_ptr<Scene>> m_mapScenes;
	const wstring gameSceneArr[4] = { L"West_Game_Scene", L"North_Game_Scene", L"East_Game_Scene", L"South_Game_Scene" };
};