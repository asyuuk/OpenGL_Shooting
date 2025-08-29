#include "Collider.h"

bool Collider::PolygonColliderCheck(const float width, const float height)
{
	// Simple AABB collision detection
	if (width < 0 || height < 0) return false; // Invalid dimensions
	// Assuming the object is centered at (0,0)
	if(-width<width && -height<height)
	{
		return true; // Collision detected
	}
	return false; // No collision
}

bool Collider::CircleColliderCheck(const float width, const float height,float PlayerWidth,float PlayerHeight)
{
	float radius = width / 2.0f; // Assuming width is the diameter
	float playercenterX = PlayerWidth / 2.0f;
	float playercenterY = PlayerHeight / 2.0f;

	if(playercenterX*playercenterX + playercenterY*playercenterY < radius*radius)
	{
		return true; // Collision detected
	}
	return false; // No collision
}