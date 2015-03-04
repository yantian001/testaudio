/*!
 * \file SoundManager.h
 * \date 2014/08/24 16:14
 *
 * \author sky
 * Contact: user@company.com
 *
 * \brief 
 *
 * TODO: long description
 *
 * \note
*/
#ifndef __MONSTER_SoundManager_h__
#define __MONSTER_SoundManager_h__
#include "cocos2d.h"
#include "ResourceManager.h"
USING_NS_CC;


/*
 *	Macro of SoundManager::getInstance()
 */
#define SMI SoundManager::getInstance()
class SoundManager
{
public:
	static SoundManager* getInstance();
	void destroyInstance();
	void playSound(const std::string sound);
	void playMusic(const std::string music);
	void pauseMusic();
	void resumeMusic();
	void stopMusic();
	void enableMusic(bool enabled);
	void enableSound(bool enabled);
protected:
	SoundManager();
	bool init();
private:
	static SoundManager* m_sharedInstance;
public:
	bool m_SoundEnabled;
	bool m_MusicEnabled;
	/** Current playing music **/
	int m_CurrentMusicId;

	bool m_LoopMusic;

	float m_Volume;
};

#endif // SoundManager_h__