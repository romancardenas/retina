/**
 * @file retina.c
 * @brief Main file.
 * @author Sistemas Digitales II
 * @date 2023-01-01
 */

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include "fsm_rx_nec.h"
#include "fsm.h"

/* Defines ------------------------------------------------------------------*/
const uint32_t nec_command = 0x00FF906F;
uint16_t edge_ticks_nec_command[] = {56109, 57014, 57460, 57520, 57573, 57634, 57686, 57749, 57800, 57860, 57913, 57976, 58026, 58087, 58139, 58201, 58253, 58314, 58367, 58427, 58591, 58651, 58815, 58875, 59039, 59099, 59263, 59323, 59486, 59547, 59710, 59773, 59934, 59997, 60158, 60220, 60383, 60443, 60496, 60556, 60609, 60670, 60833, 60894, 60946, 61008, 61060, 61120, 61174, 61234, 61287, 61347, 61400, 61461, 61624, 61685, 61848, 61909, 61962, 62022, 62186, 62246, 62410, 62473, 62634, 62694, 62858, 62918};
uint16_t edges_nec_command = 68;

uint16_t edge_ticks_nec_repetition[] = {11838, 12742, 12964, 13024};
uint16_t edges_nec_repetition = 4;

uint16_t edge_ticks_nec_noise[] = {5678, 5878};
uint16_t edges_nec_noise = 2;


/**
 * @brief  This functions serves to test the FSM for processing a NEC code.
 * 
 * There are 3 global arrays that represent 3 different situations: an actual command, a repetition, and noise. These array contain the time ticks of the edges detected in the infrared receiver.
 * 
 * **Copy your `fsm_rx_nec.c` code into the `src` folder and `fsm_rx_nec.h` code into the `include` folder.** 
 * 
 * This code is expected to be run in a PC.
 * 
 * @retval int
 */
int main(void)
{
    /* Create adn init the NEC FSM */
    fsm_t *p_fsm_rx_nec = fsm_rx_NEC_new();
    fsm_rx_NEC_init(p_fsm_rx_nec);

    /* Variables to store the parsed codes */
    uint32_t command_parsed = 0x00;
    uint32_t repetition_parsed = 0x00;
    uint32_t noise_parsed = 0x00;

    /* Test the command */
    bool nec_command_result = fsm_rx_NEC_parse_code(p_fsm_rx_nec, edge_ticks_nec_command, edges_nec_command, &command_parsed);
    if (nec_command_result)
    {
        printf("[NEC TESTER] I'm sorry, the command should not be detected as a repetition.\n");
    }
    else
    {
        if (command_parsed == nec_command)
        {
            printf("[NEC TESTER] Congratulations!!!, the command parsed is correct (0x%X).\n", command_parsed);
        }
        else
        {
            printf("[NEC TESTER] I'm sorry, the FSM is not doing well. The command you parsed is: 0x%X, and it should be 0x%X.\n", command_parsed, nec_command);
        }
    }

    /* Test the repetition */
    bool nec_repetition_result = fsm_rx_NEC_parse_code(p_fsm_rx_nec, edge_ticks_nec_repetition, edges_nec_repetition, &repetition_parsed);
    if (nec_repetition_result)
    {
        printf("[NEC TESTER] Congratulations!!! The repetition has been detected as a repetition.\n");
    }
    else
    {
        printf("[NEC TESTER] I'm sorry, the repetition has not been detected correctly.\n");
    }

    /* Test the noise */
    bool nec_noise_result = fsm_rx_NEC_parse_code(p_fsm_rx_nec, edge_ticks_nec_noise, edges_nec_noise, &noise_parsed);
    if (nec_noise_result)
    {
        printf("[NEC TESTER] I'm sorry, the noise should not be detected as a repetition.\n");
    }
    else
    {
        printf("[NEC TESTER] OK, it is not a repetition. It should not be a command either. The code parsed is: 0x%X.\n", noise_parsed);
    }

    fsm_destroy(p_fsm_rx_nec);
}
