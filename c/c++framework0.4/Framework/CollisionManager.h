#pragma once
#include "Headers.h"

// �浹ó�� �Լ�
class CollisionManager
{
public:
	static bool RectCollision(Transform _Current, Transform _Target)
	{
		Vector3 CurrentEndPoint = _Current.Position + _Current.Scale;   // ��������Ʈ ������ + ������ �ڡ�
		Vector3 TargetEndPoint = _Target.Position + _Target.Scale;		// ��������Ʈ ������ + ������ �ڡ�

		if (_Current.Position.x < TargetEndPoint.x &&
			_Target.Position.x < CurrentEndPoint.x &&
			(int)_Current.Position.y == (int)_Target.Position.y)
			return true;

		return false;
	}
};