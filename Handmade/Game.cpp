#include "Game.h"
#include "Input.h"
#include "Music.h"
#include "Screen.h"
#include "Text.h"

#include "Utility.h"

//======================================================================================================
Game::Game(GameState* initialGameState)
{
	m_deltaTime = 0;
	m_gameState.reset(initialGameState);
}
//======================================================================================================
bool Game::Initialize(const std::string& name, int screenWidth, int screenHeight, bool fullscreen)
{
	if (!Screen::Instance()->Initialize(name.c_str(), screenWidth, screenHeight, fullscreen))
	{
		return false;
	}

	Screen::Instance()->SetClearColor(100, 149, 237);

	if (!(Music::Initialize()))
	{
		//not serious - game does not need to end
		//add your own outcome/messages here...
	}

	if (!Text::Initialize())
	{
		//not serious - game does not need to end
		//add your own outcome/messages here...
	}

	return true;
}
//======================================================================================================
bool Game::Run()
{
	m_gameState->OnEnter();

	while (m_gameState)
	{
		int startTime = SDL_GetTicks();

		Screen::Instance()->Clear();
		Input::Instance()->Update();

		GameState* nextState = m_gameState->Update(m_deltaTime);

		m_gameState->Render();

		Screen::Instance()->Present();

		if (nextState != m_gameState.get())
		{
			m_gameState->OnExit();
			m_gameState.reset(nextState);

			if (m_gameState)
			{
				m_gameState->OnEnter();
			}
		}

		m_deltaTime = SDL_GetTicks() - startTime;
	}

	return true;
}
//======================================================================================================
void Game::Shutdown()
{
	Text::Shutdown();
	Music::Shutdown();
	Screen::Instance()->Shutdown();
}