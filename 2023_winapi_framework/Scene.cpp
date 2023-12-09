#include "pch.h"
#include "Scene.h"
#include "Object.h"
#include "UIObject.h"
#include "SceneUI.h"
Scene::Scene()
	:ui(nullptr)
{
	ui = new SceneUI();
}

Scene::~Scene()
{
	Release();
	delete ui;

}

void Scene::Update()
{
	for (int i = 0; i < (int)RENDER_ORDER::END; i++)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); ++j)
		{
			if (!m_vecObj[i][j]->GetIsDead())
				m_vecObj[i][j]->Update();
		}
	}
	ui->Update();
}

void Scene::FinalUpdate()
{
	for (int i = 0; i < (int)RENDER_ORDER::END; i++)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); ++j)
		{
			m_vecObj[i][j]->FinalUpdate();
		}
	}
	ui->FinalUpdate();
}

void Scene::Render(HDC _dc)
{
	for (int i = 0; i < (int)RENDER_ORDER::END; i++)
	{
		for (size_t j = 0; j < m_vecObj[i].size();)
		{
			if (!m_vecObj[i][j]->GetIsDead())
			{
				m_vecObj[i][j]->Render(_dc);
				++j;
			}
			else
				m_vecObj[i].erase(m_vecObj[i].begin() + j);
		}
	}
	ui->Render(_dc);

}

void Scene::Release()
{
	for (int i = 0; i < (int)RENDER_ORDER::END; i++)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); ++j)
		{
			delete m_vecObj[i][j];
		}
		m_vecObj[i].clear();
	}
	ui->Release();
}
