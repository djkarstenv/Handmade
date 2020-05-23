#include "GameObject.h"

//------------------------------------------------------------------------------------------------------
//constructor that assigns all defaults 
//------------------------------------------------------------------------------------------------------
GameObject::GameObject()
{

	m_isAlive = true;
	m_isActive = true;
	m_isVisible = true;
	m_position = { 0, 0 };
	
}
//------------------------------------------------------------------------------------------------------
//getter-setter function that returns memory flag reference
//------------------------------------------------------------------------------------------------------
bool& GameObject::IsAlive()
{

	return m_isAlive;

}
//------------------------------------------------------------------------------------------------------
//getter-setter function that returns active flag reference
//------------------------------------------------------------------------------------------------------
bool& GameObject::IsActive()
{

	return m_isActive;

}
//------------------------------------------------------------------------------------------------------
//getter-setter function that returns visibility flag reference
//------------------------------------------------------------------------------------------------------
bool& GameObject::IsVisible()
{

	return m_isVisible;

}
//------------------------------------------------------------------------------------------------------
//getter function that returns game object's tag variable
//------------------------------------------------------------------------------------------------------
const std::string& GameObject::GetTag() const
{

	return m_tag;

}
//------------------------------------------------------------------------------------------------------
//getter function that returns game object's position on screen
//------------------------------------------------------------------------------------------------------
SDL_Point GameObject::GetPosition()
{

	return m_position;

}
//------------------------------------------------------------------------------------------------------
//setter function that assigns game object's tag variable
//------------------------------------------------------------------------------------------------------
void GameObject::SetTag(const std::string& tag)
{

	m_tag = tag;

}
//------------------------------------------------------------------------------------------------------
//setter function that assigns game object's position on screen
//------------------------------------------------------------------------------------------------------
void GameObject::SetPosition(int x, int y)
{

	m_position.x = x;
	m_position.y = y;

}