/*
 * ESCOOTER_MonitorTask.h
 *
 *  Created on: 7 Jul 2023
 *      Author: TerenceLeung
 */

#ifndef ESCOOTER_ESCOOTER_MONITORTASK_H_
#define ESCOOTER_ESCOOTER_MONITORTASK_H_

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
typedef struct
{
    int16_t current_speed;   /*Check the E-Scooter Driving Speed */
    int16_t phase_current;   /*Check the Phase Current (Peak or Root Mean Square) */
    int16_t phase_voltage;   /*Check the Phase Voltage */
    int32_t motor_status;    /*Check the motor status */

}ESCOOTER_Physical_State;

void ESCOOTER_PhysicalParameterInit(ESCOOTER_Physical_State *stateHandle);

ESCOOTER_Physical_State ESCOOTER_PhysicalParameterMonitoring(ESCOOTER_Physical_State *stateHandle);


#ifdef __cplusplus
}
#endif
#endif /* ESCOOTER_ESCOOTER_MONITORTASK_H_ */
