#pragma once
class Collider
{
public:
	Collider() = default;
	virtual ~Collider() = default;

	bool PolygonColliderCheck(const float width,const float height);


	bool CircleColliderCheck(const float width,const float height,float PlayerWidth,float PlayerHeight);

	struct CollisionData
	{
		float x; // X position of the object
		float y; // Y position of the object
		float width; // Width of the object
		float height; // Height of the object
	};
	struct CollisionObject
	{
		

	};

	enum
	{
		COLLISION_TYPE_CIRCLE, // Circle collision
		COLLISION_TYPE_POLYGON, // Polygon collision
		COLLISION_TYPE_POINT,// Point collision
		COLLISION_TYPE_MAX
	};
	enum
	{
		Player,
		Enemy,
		Boss,
		Bullet,
		Wall,
		Building,
		Object_Max
	};
};

class Transform
{
public:
	Transform() = default;
	
	float x;
	float y;
	float rotation; // Rotation in radians
	void setPosition(float newX, float newY) {
		x = newX;
		y = newY;
	}
	void setRotation(float newRotation) {
		rotation = newRotation;
	}
	void translate(float deltaX, float deltaY) {
		x += deltaX;
		y += deltaY;
	}
	void rotate(float deltaRotation) {
		rotation += deltaRotation;
	}
};

