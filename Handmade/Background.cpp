#include "Background.h"
#include "Screen.h"
#include "Vector.h"

//======================================================================================================
Background::Background()
{
	m_isPlaying = false;
}
//======================================================================================================
Background::~Background()
{
	m_music.Unload(m_audioID);
	m_image.Unload(m_imageID);
}
//======================================================================================================
bool Background::Render()
{
	m_image.Render();
	return true;
}
//======================================================================================================
void Background::Load(const std::string& imageFilename, const std::string& audioFilename)
{
	Vector<int> resolution = Screen::Instance()->GetResolution();

	m_image.Load(imageFilename, imageFilename);
	m_image.SetImage(imageFilename);
	m_image.SetSpriteDimension(resolution.x, resolution.y);
	m_image.SetImageDimension(1, 1, resolution.x, resolution.y);

	m_music.Load(audioFilename, audioFilename);
	m_music.SetMusic(audioFilename);
	m_music.SetVolume(0.5f);

	m_imageID = imageFilename;
	m_audioID = audioFilename;
}
//======================================================================================================
void Background::PlayMusic()
{
	if (!m_isPlaying)
	{
		m_music.Play(Music::LoopType::PLAY_ENDLESS);
		m_isPlaying = true;
	}
}
//======================================================================================================
void Background::StopMusic()
{
	m_music.Stop();
	m_isPlaying = false;
}