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
	for (size_t j = 0; j < m_vecObj.size(); ++j)
	{
		if (!m_vecObj[j]->GetIsDead())
			m_vecObj[j]->Update();
	}
	ui->Update();
}

void Scene::FinalUpdate()
{
	for (size_t j = 0; j < m_vecObj.size(); ++j)
	{
		m_vecObj[j]->FinalUpdate();
	}
	ui->FinalUpdate();
}

void Scene::Render(HDC _dc)
{
	for (size_t j = 0; j < m_vecObj.size();)
	{
		if (!m_vecObj[j]->GetIsDead())
		{
			m_vecObj[j]->Render(_dc);
			++j;
		}
		else
			m_vecObj.erase(m_vecObj.begin() + j);
	}
	ui->Render(_dc);

}

void Scene::Release()
{
	for (size_t j = 0; j < m_vecObj.size(); ++j)
	{
		delete m_vecObj[j];
	}
	m_vecObj.clear();
	ui->Release();
}
