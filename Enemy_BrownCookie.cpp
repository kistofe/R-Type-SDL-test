#include "Application.h"
#include "Enemy_BrownCookie.h"
#include "ModuleCollision.h"


Enemy_BrownCookie::Enemy_BrownCookie(int x, int y) : Enemy(x,y)
{
	fly.PushBack({ 5,72,21,22 });

	animation = &fly;

	path.PushBack({-1.0f,-0.75f }, 120);
	path.PushBack({-1.0f,0.75f }, 100);
	path.PushBack({-1.0f,1.25f }, 100);

	collider = App->collision->AddCollider({ 0, 0, 21, 22 }, COLLIDER_TYPE::COLLIDER_ENEMY, (Module*)App->enemies);

	original_pos.x = x;
	original_pos.y = y;
}

void Enemy_BrownCookie::Move()
{
	position = original_pos + path.GetCurrentPosition();
}
