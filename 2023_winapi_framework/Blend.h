#pragma once
#include <functional>

class Blend
{
	Blend();
public:
	Blend(RECT& rect, float start, float end, float time, BLENDFUNCTION* newBlend);
	~Blend();
public:
	void Update();
	void Render(HDC _dc);
	void SetEndEvnet(std::function<void()>& func);
	void StartBlend();
	void CleanEvent();
	void SetYoyo(bool yoyo) { isYoyo = yoyo; }
	void SetLoop(bool loop) { isLoop = loop; }
	void Reset();
	void SetBlend(RECT& newRect);
	void EndBlend();
	const bool& GetRunning() { return running; }
private:
	float startValue;
	float endValue;
	float time;
	float curTime;
	bool running;
	bool isYoyo;
	bool isLoop;
	RECT blendSize;
	std::function<void()> endEvent;
private:
	
	BLENDFUNCTION* blend;

};

