#pragma once
#include "Headers.h"

class MathManager
{
public:
	// �Ÿ����ϴ� �Լ�
	// ������ = 9 = 3*3, 25 = 5*5, 4 = 2*2... 
	static float GetDistance(Vector3 _A_Point, Vector3 _B_Point)
	{
		float Width = _A_Point.x - _B_Point.x;
		float Height = _A_Point.y - _B_Point.y;

		return sqrt((Width * Width) + (Height * Height));
	}

	// ** ���� ���ϴ� �Լ�    
	static Vector3 GetDirection(Vector3 _Current, Vector3 _Target)
	{
		float Width = _Target.x - _Current.x;  	 // �ݴ�� �ϸ� ������
		float Height = _Target.y - _Current.y;	 // �ݴ�� �ϸ� ������

		float Distance = sqrt((Width * Width) + (Height * Height));

		return Vector3(Width / Distance, Height / Distance);
	}
};