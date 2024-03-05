/*******************************************************************************
	Module Name:		OsCfg.c
	Generation Date:	2024-March-Tuesday	16:22:41
	Tool Version: 		V.0
	Description: 		Os configuration src file


	All Rights Reserved - Sarea Alhariri
*******************************************************************************/

/******************************************************************************/
/*******************AUTO GENERATED FILE PLEASE DO NOT TOUCH********************/
/******************************************************************************/

#include "OsCfg.h"

#define		INVALID_ID		0xFFU
#define		NULL		(void *)0

/*******************************************************************************
	Num of app tasks
*******************************************************************************/
const uint8_t OsCfg_MAX_NUM_OF_TASKS = 	2U;

/*******************************************************************************
	Num of system alarms
*******************************************************************************/
const uint8_t OsCfg_MAX_NUM_OF_ALARMS = 1U;
/*******************************************************************************
	Num of system resources
*******************************************************************************/
const uint8_t OsCfg_MAX_NUM_OF_RESOURCES = 0U;
/*******************************************************************************
	App task externs
*******************************************************************************/
const uint16_t OsCfg_ALL_STACK_SIZE = 100;
/*******************************************************************************
	Hook routines configurations
*******************************************************************************/
const uint8_t OsCfg_USE_ERROR_HOOK = 0U;
const uint8_t OsCfg_USE_PRETASK_HOOK = 0U;
const uint8_t OsCfg_USE_POSTTASK_HOOK = 0U;
const uint8_t OsCfg_USE_STARTUP_HOOK = 0U;
const uint8_t OsCfg_USE_STACK_OVER_FLOW_HOOK = 0U;


const uint8_t OsCfg_USE_PARAMETER_ACCESS = 0U;
const uint8_t OsCfg_USE_GET_SERVICE_ID = 0U;
const uint32_t OsCfg_SYSTEM_TICK_IN_MS = 10U;
const uint32_t OSTICKDURATION = 10000U;
/*******************************************************************************
	Task contol block table
*******************************************************************************/
tcb_t OsCfg_TCBs[2/*num of app tasks*/+1/*for Idle mechanism */] = 
{
	{/*SP*/0u, /*basic SP*/0u , /*task pointer*/OsTask_Application, 
	/*task state*/SUSPENDED, /*DeadBeefLoc*/NULL, /*priority*/10, /*task model*/BASIC,
	/*set events*/0u, /*wait events*/0u, /*res occupation*/0u, 
	/*preemptability*/1u, /*schedule requested */0u},

	{/*SP*/0u, /*basic SP*/0u , /*task pointer*/OsTask_ApplicationInit, 
	/*task state*/READY, /*DeadBeefLoc*/NULL, /*priority*/20, /*task model*/BASIC,
	/*set events*/0u, /*wait events*/0u, /*res occupation*/0u, 
	/*preemptability*/1u, /*schedule requested */0u},

	{0u, 0u, OsTask_IdleMechanism,     READY, NULL, 255u, BASIC, 0u, 0u,
	 0u, 1u, 0u }
};

/*******************************************************************************
	Stack Size For Each Thread
*******************************************************************************/
const uint32_t OsCfg_StackSize[2] = 
{
	50,		/*Application*/
	50		/*ApplicationInit*/
};

/*******************************************************************************
	Stack Buffer Allocation For All Threads
*******************************************************************************/
uint32_t OsCfg_Stack[100+16/* 16 for Idle mechanism */] = {0u};

/*******************************************************************************
	Alarms base records to be referenced in alarm configs
*******************************************************************************/
AlarmBaseType MainCounter = { 0xFFFFFFFF, 1, 1};

/*******************************************************************************
	Alarm control blocks table
*******************************************************************************/
acb_t OsCfg_Alarms[1/*OsCfg_MAX_NUM_OF_ALARMS*/] =
{
	{/*fire time*/300, /*cyclic time*/50, /*call back*/NULL,
	/*action*/ALARM_ACTION_TASK,
	/*base type*/&MainCounter, /*task id*/Application, /*event id*/INVALID_ID,
	/*enable status*/true}		/*Alarm ID: WakeBlinker*/
};
/*******************************************************************************
	Resource task authorization
*******************************************************************************/
const uint8_t OsCfg_ResourceTaskAuthorized[1][1]; /*Not used*/
/*******************************************************************************
	Ceiling priority for system resources
*******************************************************************************/
const uint8_t OsCfg_ResourceCeilPri[1]; /*Not used*/
/*******************************************************************************
	Error Code task buffer
*******************************************************************************/
StatusType SVCCnxt_ErrCodes[2/*OsCfg_MAX_NUM_OF_TASKS*/] = {E_OK};
/*******************************************************************************
	SVC resource context
*******************************************************************************/
ResourceType SVCCnxt_ResMgrCnxt[1];/*Not used*/
/*******************************************************************************
	Resource control block table
*******************************************************************************/
RCB_t RCB[1]; /*Not used*/
