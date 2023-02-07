/**
 * @file fsm_tx.c
 * @brief Infrared transmitter FSM main file.
 * @author alumno1
 * @author alumno2
 * @date fecha
 */

/* Includes ------------------------------------------------------------------*/
#include "fsm_tx.h"

/* Typedefs --------------------------------------------------------------------*/


/* Defines and enums ----------------------------------------------------------*/
/* Enums */


/* NEC private functions */


/* State machine input or transition functions */


/* State machine output or action functions */


/* Other auxiliary functions */
void fsm_tx_set_code(fsm_t *p_this, uint32_t code)
{
    /* TO-DO alumnos */
}

void fsm_send_NEC_code(uint8_t tx_id, uint32_t code)
{
    /* TO-DO alumnos */

}

fsm_t *fsm_tx_new(uint8_t tx_id)
{
    fsm_t *p_fsm = malloc(sizeof(fsm_tx_t)); /* Do malloc to reserve memory of all other FSM elements, although it is interpreted as fsm_t (the first element of the structure) */
    fsm_tx_init(p_fsm, tx_id);
    return p_fsm;
}

void fsm_tx_init(fsm_t *p_this, uint8_t tx_id)
{
    fsm_tx_t *p_fsm = (fsm_tx_t *)(p_this);
    fsm_init(p_this, fsm_trans_tx);

    /* TO-DO alumnos */
    
}
