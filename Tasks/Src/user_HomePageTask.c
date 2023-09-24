/* Private includes -----------------------------------------------------------*/
//includes
#include "user_TasksInit.h"
#include "user_ScrRenewTask.h"
#include "main.h"
#include "rtc.h"
#include "lvgl.h"
#include "ui_HomePage.h"
#include "power.h"

/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/


/**
  * @brief  homepage time renew task
  * @param  argument: Not used
  * @retval None
  */
void TimeRenewTask(void *argument)
{
	uint8_t value_strbuf[10];
	while(1)
	{
		if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_HomePage)
		{
			/*
			lv_obj_set_style_text_opa(ui_TimeColonLabel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
			osDelay(500);
			lv_obj_set_style_text_opa(ui_TimeColonLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
			*/
			
			//time get and renew the screen
			RTC_DateTypeDef nowdate;
			RTC_TimeTypeDef nowtime;
			
			HAL_RTC_GetTime(&hrtc,&nowtime,RTC_FORMAT_BIN);//Ҫ��gettime,������²���ʱ��
			HAL_RTC_GetDate(&hrtc,&nowdate,RTC_FORMAT_BIN);
			
			if(ui_TimeMinuteValue != nowtime.Minutes)
			{
				ui_TimeMinuteValue = nowtime.Minutes;
				sprintf(value_strbuf,"%02d",ui_TimeMinuteValue);
				lv_label_set_text(ui_TimeMinuteLabel, value_strbuf);
			}
			
			if(ui_TimeHourValue != nowtime.Hours)
			{
				ui_TimeHourValue = nowtime.Hours;
				sprintf(value_strbuf,"%2d",ui_TimeHourValue);
				lv_label_set_text(ui_TimeHourLabel, value_strbuf);
			}
			
			if(ui_DateDayValue != nowdate.Date)
			{
				ui_DateDayValue = nowdate.Date;
				ui_DataWeekdayValue = nowdate.WeekDay;
				sprintf(value_strbuf,"%2d-%02d",ui_DateMonthValue,ui_DateDayValue);
				lv_label_set_text(ui_DateLabel, value_strbuf);
				lv_label_set_text(ui_DayLabel, ui_Days[ui_DataWeekdayValue-1]);
			}
			if(ui_DateMonthValue != nowdate.Month)
			{
				ui_DateMonthValue = nowdate.Month;
				ui_DateDayValue = nowdate.Date;
				ui_DataWeekdayValue = nowdate.WeekDay;
				sprintf(value_strbuf,"%2d-%02d",ui_DateMonthValue,ui_DateDayValue);
				lv_label_set_text(ui_DateLabel, value_strbuf);
				lv_label_set_text(ui_DayLabel, ui_Days[ui_DataWeekdayValue-1]);
			}
		}
		osDelay(500);
	}
}

/**
  * @brief  homepage check the battery power(5 mins a detection)
  * @param  argument: Not used
  * @retval None
  */
void BatDet_Task(void *argument)
{
	while(1)
	{
		uint8_t BatDetStr;
		if(osMessageQueueGet(BatDet_MessageQueue,&BatDetStr,NULL,0)==osOK)
		{
			uint8_t value_strbuf[5];
			
			ui_BatArcValue = PowerCalculate();
			if(ui_BatArcValue>0 && ui_BatArcValue<=100)
			{}
			else
			{ui_BatArcValue=0;}
			
			if(ScrRenewStack.Data[ScrRenewStack.Top_Point-1] == (long long int)&ui_HomePage)
			{
				lv_arc_set_value(ui_BatArc, ui_BatArcValue);
				sprintf(value_strbuf,"%2d%%",ui_BatArcValue);
				lv_label_set_text(ui_BatNumLabel, value_strbuf);
			}
		}
		osDelay(500);
	}
}

/**
  * @brief  homepage renew the bottom sensors' data
  * @param  argument: Not used
  * @retval None
  */
void HomePageSensorDataRenew_Task(void *argument)
{
	while(1)
	{
		//wait for the message from the sensor data renew
		if(1)
		{
			
		}
		osDelay(500);
	}
}
