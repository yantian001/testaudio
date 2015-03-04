#ifndef __MONSTER_RESOURCEMANAGER_h__
#define __MONSTER_RESOURCEMANAGER_h__
#include "cocos2d.h"

USING_NS_CC;


/********************************************************************
created:	2015/02/06
created:	6:2:2015   17:54
filename: 	ResourceManager
author:		Hugo

purpose:	资源管理类 ,用于管理游戏中的图片资源等
*********************************************************************/

//macro
#define RMTOOL ResourceManager::getInstance()
#define GETRMRES(name) ResourceManager::getInstance()->getResouce(name)
#define GETSOUND(name) ResourceManager::getInstance()->getSound(name)
class ResourceManager 
{
public: 
	/*
	*	get a signleton instance pointer
	*/
	static ResourceManager* getInstance();
	/*
	*	init the img resource map with thc config file ,
	*  if the _config equals "" ,it will init with 
	*  resource/config/imgresource.json
	*/
	void initResource(const std::string _config= "");
	/** @brief init sound resource
	*init sound resource
	*/
	void initSounds(const std::string _soundPath = "");
	/** @brief parse resource to map
	* add to map
	*/
	void parseResource(const std::string _filePath,std::map<std::string,std::string>& _map);
	/*
	*	get the special _filename resouce path from the map
	*  if the resource dont exist in the map it will return 
	*  the IMG_DEFAULT
	*/
	const std::string getResouce(const std::string _filename);
	/** get sound filepath **/
	const std::string getSound(const std::string _soundName);

	const std::string getRandomSounds();
private:
	CC_DISALLOW_COPY_AND_ASSIGN(ResourceManager);

	ResourceManager();

public:
	std::map<std::string,std::string> m_ImgResMap;
	std::map<std::string,std::string> m_SoundMap;
public:
	static const  std::string IMG_DEFAULT ;
};

#endif