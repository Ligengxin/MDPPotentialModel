// PotentialModel.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "struct_fun.h"
#include "InputData.h"
#include "TrafficModel.h"

SLane LaneInfo; 
SObstacleInfo Obs;
SObstacle OBS;

int _tmain(int argc, _TCHAR* argv[])
{
	LaneSetting(LaneInfo);
	memset(&OBS,0,sizeof(SObstacle));
	fPoint obs1;
	obs1.x=-40;  
	obs1.y=3.75*2.5;
	ObsSetting(Obs,obs1,11);
	Obs.ObstacleID=Vehicle;
	OBS.Obs[0]=Obs;

	fPoint obs2;
	obs2.x=10;  
	obs2.y=3.75*2.5;
	ObsSetting(Obs,obs2,11);
	Obs.ObstacleID=Vehicle;
	OBS.Obs[1]=Obs;

	fPoint obs3;
	obs3.x=50;  
	obs3.y=3.75*2.5;
	ObsSetting(Obs,obs3,11);
	Obs.ObstacleID=Vehicle;
	OBS.Obs[2]=Obs;

	fPoint obs4;
	obs4.x=25;  
	obs4.y=3.75*1.5;
	ObsSetting(Obs,obs4,7);
	Obs.ObstacleID=Vehicle;
	OBS.Obs[3]=Obs;

	OBS.IsOK=TRUE;
	OBS.ObstacleNum=4;

	FrenetLaneMark LaneMark;
	memset(&LaneMark,0,sizeof(LaneMark));
	TrafficModel model;
	model.TrafficSetting(LaneInfo,OBS,LaneMark);
	model.veh.d=1.5*3.75;
	model.veh.s=10;
	model.veh.theta=0;
	model.veh.v=7;

	model.StaticObs[0].s=90;
	model.StaticObs[0].d=5.625;
	model.StaticObs[0].r=2.5;
	model.staticObsNum=2;

	model.StaticObs[1].s=110;
	model.StaticObs[1].d=9.375;
	model.StaticObs[1].r=2.5;

	TreeNode node;
	node.s=95;
	node.d=1.5*3.75;

	//float lane_cost=0;
	//float dynamic_cost=0;
	float static_cost=0;
	static_cost=model.StaticLaneRightCost(node,LaneMark);
	//dynamic_cost=model.DynamicLaneRightCost(node,LaneMark);
	//lane_cost=model.LaneMarkCost(node,LaneMark);  
	int num=LaneInfo.LineR2.ValidNum;
	//model.ReadVelocityFile("D:\\MDPPotentialModel\\PotentialModel\\indata\\VelocityFile1.txt");
	//for (int i=0;i<num;i++)
	//{
	//	cout<<LaneInfo.LineR2.LinePt[i].x<<"  "<<LaneInfo.LineR2.LinePt[i].y<<endl;
	//	
    //  Sleep(10);
	//	
	//}

	cout<<static_cost<<endl;
	system("pause");

	return 0;
}

