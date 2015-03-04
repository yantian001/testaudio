#include "SoundManager.h"
#include "AudioEngine.h"

using namespace cocos2d::experimental;
/*
 *	Staic variables
 */
SoundManager* SoundManager::m_sharedInstance = nullptr;

/*
 *	SoundManager
 */
SoundManager::SoundManager():
	m_SoundEnabled(true),
	m_MusicEnabled(true),
	m_CurrentMusicId(AudioEngine::INVAILD_AUDIO_ID),
	m_LoopMusic(true),
	m_Volume(1.0f)
{

}

SoundManager* SoundManager::getInstance()
{
	if (!m_sharedInstance)
	{
		m_sharedInstance = new (std::nothrow)SoundManager();
		if (m_sharedInstance && m_sharedInstance->init())
		{
			
		}
		else
		{
			CC_SAFE_DELETE(m_sharedInstance);
		}
	}
	//
	return m_sharedInstance;
}

void SoundManager::destroyInstance()
{
	CC_SAFE_DELETE(m_sharedInstance);
}

bool SoundManager::init()
{
	/*m_SoundEnabled = UserDefault::getInstance()->getBoolForKey(STT_SOUNDENABLED);
	m_MusicEnabled = UserDefault::getInstance()->getBoolForKey(STT_MUSICENABLED);*/
	//SimpleAudioEngine::getInstance()->
	return true;
}

void SoundManager::playSound(const std::string sound)
{
	if (sound == "" || !m_SoundEnabled)
	{
		return;
	}
	//std::string soundpath = GETSOUND(sound);
	std::string soundpath =(sound);

	if (soundpath != "")
	{
		AudioEngine::play2d(soundpath,false);
	}
}

void SoundManager::playMusic(const std::string music)
{
	if (music == "")
	{
		return;
	}
	SoundManager::stopMusic();
	if (!m_MusicEnabled)
	{
		return;
	}
	//std::string musicpath = GETSOUND(music);
	std::string musicpath = (music);
	if ( musicpath != "")
	{
		m_CurrentMusicId = AudioEngine::play2d(musicpath,m_LoopMusic,m_Volume);
	}
}

void SoundManager::pauseMusic()
{
	if (m_CurrentMusicId != AudioEngine::INVAILD_AUDIO_ID)
	{
		AudioEngine::pause(m_CurrentMusicId);
	}
}

void SoundManager::resumeMusic()
{
	if (m_CurrentMusicId == AudioEngine::INVAILD_AUDIO_ID || !m_MusicEnabled)
	{
		return;
	}
	if(AudioEngine::getState(m_CurrentMusicId) == AudioEngine::AudioState::PAUSED)
	{
		AudioEngine::resume(m_CurrentMusicId);
	}
}

void SoundManager::stopMusic()
{
	AudioEngine::stop(m_CurrentMusicId);
	m_CurrentMusicId = AudioEngine::INVAILD_AUDIO_ID;
}

void SoundManager::enableMusic(bool enabled)
{
	m_MusicEnabled = enabled;
	/*UserDefault::getInstance()->setBoolForKey(STT_MUSICENABLED,m_MusicEnabled);
	UserDefault::getInstance()->flush();*/
}

void SoundManager::enableSound(bool enabled)
{
	m_SoundEnabled = enabled;
	//UserDefault::getInstance()->setBoolForKey(STT_SOUNDENABLED,m_SoundEnabled);
	//UserDefault::getInstance()->flush();
}