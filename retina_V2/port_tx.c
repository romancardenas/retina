/**
 * @file port_tx.c
 * @brief Portable functions to interact with the infrared transmitter FSM library.
 * @author alumno1
 * @author alumno2
 * @date fecha
 */

/* Includes ------------------------------------------------------------------*/
#include "port_tx.h"

/* Defines --------------------------------------------------------------------*/
#define ALT_FUNC1_TIM2 /*!< TIM2 Alternate Function mapping */

/* IMPORTANT
The timer symbol is the same for all the TX, so it is not in the structure of TX. It has been decided to be the TIM1. It is like a systick but faster.
*/

/* Typedefs --------------------------------------------------------------------*/

/* Global variables ------------------------------------------------------------*/

/* Infrared transmitter private functions */
static void _timer_symbol_setup()
{
  /* TO-Do alumnos */


  /* Finally, set the priority and enable interruptions globally. */
  NVIC_SetPriority(TIM1_UP_TIM10_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 1, 0)); /* Priority 1, sub-priority 0 */
  NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn);                                                          /* Enable interrupt */
}

static void _timer_pwm_setup(uint32_t tx_id)
{
}

/* Public functions */
void port_tx_init(uint8_t tx_id, bool status)
{
}

/* In order to make the academic effort of configuring the PWM, the values: timer, channel and masks are hardcoded and this function is not generic for any timer/channel. It is not the best way, but it is as it. */
void port_tx_pwm_timer_set(uint8_t tx_id, bool status)
{
}

void port_tx_symbol_tmr_start()
{
}

void port_tx_symbol_tmr_stop()
{
}

uint32_t port_tx_tmr_get_tick()
{
}

//------------------------------------------------------
// INTERRUPT SERVICE ROUTINES
//------------------------------------------------------

void TIM1_UP_TIM10_IRQHandler(void)
{
}