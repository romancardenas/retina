# Test FSM NEC protocol

This project serves to test the implementation of your Finite State Machine that parses into a NEC code a given array of time-ticks that represents the times where an edge (falling or rising) occurs in an infrared receiver.

To test your code:
- Paste your `fsm_rx_nec.c` and `fsm_rx_nec.h` in the folders `common/src` and `common/include` respectively. 
- Compile and run/ debug

This code is expected to be compiled and run in a computer. It does not need anything related to HW, therefore the `port` folder must be empty.

This project contains 3 array representing 3 different situations: (i) a real NEC command, (ii) a repetition code of a NEC command, and (iii) noise. If your code works properly you should see 3 messages like these:

> `[NEC TESTER] Congratulations!!!, the command parsed is correct (0xFF906F).` 
>
> `[NEC TESTER] Congratulations!!! The repetition has been detected as a repetition.`
>
> `[NEC TESTER] OK, it is not a repetition. It should not be a command either. The code parsed is: 0x0.`

If one or more of the test fail, you should check and debug your implementation. Once your code works properly you can bring your codes back to your project.