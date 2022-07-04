#include "Player.h"
#include "InputManager.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::Start()
{

}

void Player::Update()
{
	DWORD dwkey = InputManager::GetInstance()->GetKEY();
	Info->Position.x = 0;

	if (dwkey & KEY_UP)
		cout << "up" << endl;

	if (dwkey & KEY_DOWN)
		cout << "down" << endl;

	if (dwkey & KEY_LEFT)
		cout << "left" << endl;

	if (dwkey & KEY_RIGHT)
		cout << "right" << endl;

	if (dwkey & KEY_SPACE)
		cout << "space" << endl;

}

void Player::Render()
{

}

void Player::Release()
{

}