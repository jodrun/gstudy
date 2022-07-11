#pragma once
#include "Headers.h"

class Object
{
protected:
	Transform Info;
	Object* Target;
public:
	virtual void Start()PURE;
	virtual int Update()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
public:
	Transform GetTransform() const { return Info; }                 // 불렛,에너미,플레이어 트렌스폼 사용 하기 위함 (이거 있으면 밑에꺼 없어도 괜찮음) 

	Vector3 GetPosition() const { return Info.Position; }           // 불렛,에너미,플레이어 info.position 사용 하기위한 함수
	void SetPosition(Vector3 _Position) { Info.Position = _Position; }
	void SetPosition(float _x, float _y) { Info.Position = Vector3(_x, _y); }

	void SetDirection(Vector3 _Direction) { Info.Direction = _Direction; }
	void SetDirection(float _x, float _y) { Info.Direction = Vector3(_x, _y); }
	void SetTarget(Object* _Target) { Target = _Target; }
public:
	Object();
	virtual ~Object();
};

