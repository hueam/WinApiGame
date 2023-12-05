#pragma once
#include "Object.h"

class Scene;
class Lockers : public Object
{
public:
    Lockers(Scene* curScene,float lockerSize, Vec2 pos);
    ~Lockers();
private:
    Object* objArr[6][3];
};

