/**
 * @file fsm_button.c
 * @brief Button FSM main file.
 * @author Sistemas Digitales II
 * @date 2023-01-01
 */

/* Includes ------------------------------------------------------------------*/
#include "fsm_button.h"
#include "port_button.h"

/* Typedefs --------------------------------------------------------------------*/

/* Defines and enums ----------------------------------------------------------*/
/* Enums */

/* State machine input or transition functions */


/* State machine output or action functions */


/* Other auxiliary functions */


fsm_t *fsm_button_new(uint32_t debounce_time, uint32_t button_id)
{
    fsm_t *p_fsm = malloc(sizeof(fsm_button_t)); /* Hago malloc para que reserve memoria de todo resto de cosas de la FSM, aunque lo interpreto como fsm_t (el primer elto de la estructura) */
    fsm_button_init(p_fsm, debounce_time, button_id);
    return p_fsm;
}

void fsm_button_init(fsm_t *p_this, uint32_t debounce_time, uint32_t button_id)
{
    fsm_button_t *p_fsm = (fsm_button_t *)(p_this);
    fsm_init(p_this, fsm_trans_button);

    /* TO-DO alumnos: */
}
