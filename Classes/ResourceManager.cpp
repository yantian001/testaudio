#include "ResourceManager.h"
#include "json/rapidjson.h"
#include "json/document.h"
#include "CommonUtil.h"
const std::string ResourceManager::IMG_DEFAULT = "";

ResourceManager::ResourceManager()
{

}

ResourceManager* ResourceManager::getInstance()
{
    static ResourceManager resMgr;
    return &resMgr;
}

void ResourceManager::initResource(const std::string _config/* = "" */)
{
    std::string strConfPath(_config);
    if (strConfPath == "")
    {
        strConfPath = "config/imgresource.json";
    }
	parseResource(strConfPath,m_ImgResMap);
}

void ResourceManager::initSounds(const std::string _soundPath)
{
	std::string strConfPath(_soundPath);
	if (strConfPath == "")
	{
		strConfPath = "config/sounds.json";
	}
	parseResource(strConfPath,m_SoundMap);
}

void ResourceManager::parseResource(const std::string _filePath,std::map<std::string,std::string>& _map)
{
	//get the json data from json file
	std::string jsonData = FileUtils::getInstance()->getStringFromFile(_filePath);

	//init rapid json document
	rapidjson::Document d;
	d.Parse<0>(jsonData.c_str());

	//parse error
	CCASSERT(!d.HasParseError(),d.GetParseError());

	//parse the json item to img map
	if ((!d["resources"].IsNull()) && d["resources"].IsArray())
	{
		for (int i = 0; i < d["resources"].Size(); i++)
		{
			const rapidjson::Value& itr = d["resources"][(unsigned)i];
			if (_map.find(itr["name"].GetString()) 
				== _map.end())
			{
				_map[itr["name"].GetString()] = itr["url"].GetString();
			}
		}
	}
}

const std::string ResourceManager::getResouce(const std::string _filename)
{
    if (m_ImgResMap.find(_filename) != m_ImgResMap.end())
    {
        return m_ImgResMap.at(_filename);
    }
    return IMG_DEFAULT;
}

const std::string ResourceManager::getSound(const std::string _soundName)
{
	if (m_SoundMap.find(_soundName) != m_SoundMap.end())
	{
		return m_SoundMap.at(_soundName);
	}
	return "";
}

const std::string ResourceManager::getRandomSounds()
{
	int i = CommonUtil::getRandomNumber(0,m_SoundMap.size());
	auto itr = m_SoundMap.begin();
	std::advance(itr,i);
	if (itr != m_SoundMap.end())
	{
		return itr->second;
	}
	return "";
}

