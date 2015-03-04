/*!
* \file CommonUtil.h
*
* \author yantiantian
* \date °ËÔÂ 2014
*
* 
*/
#ifndef __MONSTER_CommonUtil_h__
#define __MONSTER_CommonUtil_h__
#include "cocos2d.h"



	class CommonUtil
	{
	
		
	public:
		static inline int getRandomNumber(int _arg_1,int _arg_2)
		{
			//srand(time(nullptr));
			/*time_t seed;
			time(&seed);
			srand(seed);*/
			//srand((unsigned )time(NULL));
			/*	time_t seed1;
			time(&seed1);
			clock_t seed2 = clock();
			srand(seed2 * 10000 + seed1 /2000);*/
			int ret =CCRANDOM_0_1()*((_arg_2-_arg_1));
			return (ret + _arg_1);
		}

		
	};

#endif // CommonUtil_h__
