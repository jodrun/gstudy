#include "Player.h"
#include "Bullet.h"
#include "InputManager.h"
#include "CursorManager.h"
#include "ObjectManager.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Start()
{
	Info.Position = Vector3(24.0f, 7.0f);
	Info.Rotation = Vector3(0.0f, 0.0f);
	Info.Scale = Vector3(2.0f, 1.0f);

	Target = nullptr;
}

int Player::Update()
{
	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (Info.Position.y >= 8.0f)
	{
		if (dwKey & KEY_UP)
			Info.Position.y--;
	}

	if (Info.Position.y <= 30.0f)
	{
		if (dwKey & KEY_DOWN)
			Info.Position.y++;
	}

	if (Info.Position.x >= 26.0f)
	{
		if (dwKey & KEY_LEFT)
			Info.Position.x -= 2;
	}

	if (Info.Position.x <= 120.0f)
	{
		if (dwKey & KEY_RIGHT)
			Info.Position.x += 2;
	}

	if (dwKey & KEY_SPACE)
		
	if (dwKey & KEY_ESCAPE)

	return 0;
}

void Player::Render()
{
	CursorManager::GetInstance()->WriteBuffer(Info.Position, (char*)"¡Þ");
}

void Player::Release()
{

}