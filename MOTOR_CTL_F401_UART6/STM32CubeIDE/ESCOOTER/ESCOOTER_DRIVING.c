/*
 * ESCOOTER_DRIVING.c
 *
 *  Created on: 18 Jul 2023
 *      Author: TerenceLeung
 */

#include "ESCOOTER_DRIVING.h"
#include "POWER_CONTROL.h"
#include "POWER_CONTROL_LL.h"
#include "Cruise_Control.h"
#include "cmsis_os.h"
#include "mc_api.h"
#include "main.h"

ESCOOTER_Driving_State Driving_State;     /*Determines the current E-Scooter's operation status*/
ESCOOTER_BrakeANDThrottleInput modeControl; /*Motor Physical Limitations*/
ESCOOTER_Physical_State motorStatus; /*Current Motor Physical Status*/

void ESCOOTER_saveStatus (uint8_t state)
{
	  Driving_State = state;
}

ESCOOTER_Driving_State ESCOOTER_getStatus()
{
	return Driving_State;
}

void ESCOOTER_Set_Limit(ESCOOTER_BrakeANDThrottleInput *limitHandle)
{
     modeControl = *limitHandle;
}

void ESCOOTER_Set_PhysicalParam(ESCOOTER_Physical_State *motorParam)
{
	 motorStatus = *motorParam;
}

void Speed_Cruise_Control()
{

}

int16_t throttle_Current = 0;
void ESCOOTER_Driving_Start()
{
	//retransmissionTimerStart();
	//MC_ProgramTorqueRampMotor1(modeControl.TARGET_IQ,modeControl.RAMP_DURATION);
	//MC_StartMotor1();
    throttle_Current = modeControl.TARGET_IQ;
}

uint8_t stop = 0;
void ESCOOTER_Driving_Stop()
{
	//HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5,GPIO_PIN_RESET);
	/*Stop Motor!*/
	//MC_StopMotor1();
}

/*This thread might be useful (?) This thread will be deleted (?)*/
void ESCOOTER_DrivingTaskControl(void const * argument)
{
     for(;;)
     {

           switch(Driving_State)
           {
               case DRIVING_IDLE:
            	   ESCOOTER_Driving_Stop();
            	   break;

               case DRIVING_START:
            	   ESCOOTER_Driving_Start();
            	   break;

               case DRIVING_STOP:
            	   ESCOOTER_Driving_Stop();
            	   break;

               default:
            	   break;

           }
     }
}
