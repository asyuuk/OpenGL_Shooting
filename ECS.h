#pragma once
#include<list>
#include<memory>
class Component
{
public:
	virtual ~Component() = default;
	virtual void update() = 0;
	virtual void Draw() = 0;
	virtual void init() = 0;
	std::shared_ptr<Object> Object;
};

class Object
{
public:
	virtual ~Object()
	{
		for(auto& component : components)
		{
			delete component;
		}
		components.clear();
	};
	std::list<Component*> components;
	void Update()
	{

		for (auto& component : components)
		{
			component->update();
		}
	}

	void Draw()
	{
		for (auto& component : components)
		{
			component->Draw();
		}
	}

	void init()
	{
		for (auto& component : components)
		{
			component->init();
		}
	}

	template<typename T>
	T* GetComponent()
	{
		for (auto component : components)
		{
			T* buff = dynamic_cast<T*>(component);
			if (buff != nullptr)
			{
				return buff;
			}
		}
		return nullptr
	}
	template<typename T>
	T* AddComponent()
	{
		T* component = new T();
		components.push_back(component);
		component->init();
		return component;
	}

	template<typename T>
	void RemoveComponent()
	{
		for (auto it = components.begin(); it != components.end(); ++it)
		{
			T* buff = dynamic_cast<T*>(*it);
			if (buff != nullptr)
			{
				delete *it;
				components.erase(it);
				return;
			}
		}
		components.clear();
	}
};

