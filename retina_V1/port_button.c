/**
 * @file port_button.c
 * @brief File containing functions related to the HW of the button FSM.
 *
 * This files defines an internal struct which coontains the HW information of the 
 *
 * @author alumno1
 * @author alumno2
 * @date fecha
 */

/* Includes ------------------------------------------------------------------*/
#include "port_button.h"

/* Typedefs --------------------------------------------------------------------*/
typedef struct
{
    GPIO_TypeDef *p_port;
    uint8_t pin;
    bool flag_pressed;
} port_button_hw_t;

/* Global variables ------------------------------------------------------------*/

void port_button_init(uint32_t button_id)
{
    GPIO_TypeDef *p_port = buttons_arr[button_id].p_port;
    uint8_t pin = buttons_arr[button_id].pin;

    /* TO-DO alumnos */
}


//------------------------------------------------------
// INTERRUPT SERVICE ROUTINES
//------------------------------------------------------
/**
 * @brief This function handles Px10-Px15 global interrupts.
 */
void EXTI15_10_IRQHandler(void)
{
    /* ISR user button in PC13 */
    if (EXTI->PR & BIT_POS_TO_MASK(buttons_arr[BUTTON_0_IDX].pin))
    {
      /* TO-DO alumnos */

    }
}
