#pragma once
#include <functional>
#include "Blend.h"

class Scene;
class Blend;
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
	void ReleaseScene(const wstring& _scenename);
	void RegisterScene(const wstring& _scenename, std::shared_ptr<Scene> _scene);
	void ChangeScene(bool isAdd);
public:
	const bool GetFadeRunning()
	{
		bool running = m_pFadeIn->GetRunning() || m_pFadeOut->GetRunning();
		return running;
	}
	void FadeIn(std::function<void()>& func);
	void FadeIn();
	void FadeOut(std::function<void()>& func);
	void FadeOut();
public:
	const std::shared_ptr<Scene>& GetCurScene() const
	{
		return m_pCurScene;
	}
private:
	Blend* m_pFadeIn;
	Blend* m_pFadeOut;

	int currentScene = 0;
	// ����Ʈ ������
	std::shared_ptr<Scene> m_pCurScene; // ���� ��
	// ������ �����ϴ� ��.
	map<wstring, std::shared_ptr<Scene>> m_mapScenes;
	const wstring gameSceneArr[4] = { L"West_Game_Scene", L"North_Game_Scene", L"East_Game_Scene", L"South_Game_Scene" };
};