#include <time.h>
#include "Input.h"
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"

//------------------------------------------------------------------------------------------------------
//constructor that assigns all default values
//------------------------------------------------------------------------------------------------------
MenuState::MenuState(Game* gameHandle) : GameState(gameHandle)
{

	m_menu = nullptr;
	m_image = nullptr;
	
}
//------------------------------------------------------------------------------------------------------
//function that creates a new background screen object and menu
//------------------------------------------------------------------------------------------------------
bool MenuState::OnEnter()
{

	m_menu = new MainMenu;
	m_menu->SetMenuText("PLAY GAME");
	m_menu->SetMenuText("QUIT GAME");

	m_image = new Background("Assets/Textures/Menu_1280x720.png", "Assets/Audio/Menu.ogg");
	
	//seed the random number generator
	srand(static_cast<unsigned int>(time(0)));

	return true;

}
//------------------------------------------------------------------------------------------------------
//function that waits for a key to be pressed before transitioning to a different state
//------------------------------------------------------------------------------------------------------
bool MenuState::Update(int deltaTime)
{

	//play the background music associated with the image
	//when the state transitions to the next state stop it
	m_image->PlayMusic();

	//update the main menu to determine which menu choice was made
	m_menu->Update(deltaTime);

	//if player chose to play game, go into main playing state 
	if (m_menu->GetMenuOption() == static_cast<int>(MenuOption::PLAY))
	{
		m_image->StopMusic();
		//m_isActive = m_isAlive = false;
		m_gameHandle->ChangeState(new PlayState(m_gameHandle));
	}

	//if player chose to exit the game then quit altogether
	if (m_menu->GetMenuOption() == static_cast<int>(MenuOption::QUIT))
	{
		m_image->StopMusic();
		//m_isActive = m_isAlive = false;
	}

	return true;

}
//------------------------------------------------------------------------------------------------------
//function that renders the background splash image and menu
//------------------------------------------------------------------------------------------------------
bool MenuState::Draw()
{

	m_image->Draw();
	m_menu->Draw();
	
	return true;

}
//------------------------------------------------------------------------------------------------------
//function that removes splash screen background object and menu from memory
//------------------------------------------------------------------------------------------------------
void MenuState::OnExit()
{

	delete m_image;
	delete m_menu;

}