#pragma once
#include "Headers.h"

// 충돌처리 함수
class CollisionManager
{
public:
	static bool RectCollision(Transform _Current, Transform _Target)
	{
		Vector3 CurrentEndPoint = _Current.Position + _Current.Scale;   // 엔드포인트 포지션 + 스케일 ★★
		Vector3 TargetEndPoint = _Target.Position + _Target.Scale;		// 엔드포인트 포지션 + 스케일 ★★

		if (_Current.Position.x < TargetEndPoint.x &&
			_Target.Position.x < CurrentEndPoint.x &&
			(int)_Current.Position.y == (int)_Target.Position.y)
			return true;

		return false;
	}
};