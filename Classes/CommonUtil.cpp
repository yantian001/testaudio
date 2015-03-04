#include "CommonUtil.h"
#include <iostream>
#include <fstream>
namespace monster
{


	Layer* CommonUtil::m_Container = nullptr;
	Layer* CommonUtil::m_TopContainer = nullptr;
	Layer* CommonUtil::m_RootContainer = nullptr;
	bool CommonUtil::m_IsActived = false;
	/*
	*	返回时间间隔,(毫秒)
	*/
	const float CommonUtil::GetTimerDiff(struct timeval& timeStart)
	{
		struct timeval now;
		float ret(0.0f);
		if(gettimeofday(&now,nullptr) != 0 )
		{
			//CCLOG("get timeval error in CommonUtil");
			return ret;
		}
		float deltaTime = (now.tv_sec - timeStart.tv_sec) * 1000 + (now.tv_usec - timeStart.tv_usec) / 1000;
		ret = MAX(0,deltaTime);
		return ret;
	}

	void CommonUtil::WriteLog2File(const char* format)
	{
		//CCLOG
		//StringUtils::toString(format,...)
//		std::string filename = (FileUtils::getInstance()->getWritablePath() + "cocos_log.txt");
//		std::ofstream fs(filename,std::ios::out | std::ios::_Noreplace);
//		time_t t = time( 0 );
//		char tmp[64];
//		strftime( tmp, sizeof(tmp), "%Y/%m/%d %X %A",localtime(&t) );
//		fs<< tmp <<":"<< format <<std::endl;
//		fs.close();
	}
}
