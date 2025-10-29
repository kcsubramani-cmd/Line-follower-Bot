# Line-follower-Bot

Hardware Required
1. Arduino UNO
2.L293D Motor Driver IC
3.5x IR (Infrared) Sensors (Analog)
4.2x DC Motors (with wheels)
5.9V Battery (for motors)
6. Breadboard and Jumper Wires

Control Algorithms used 
1. Simple if-else: 
  Checks which sensor the line is (binary) and adjusts its speed and direction accordingly, with a set of predefined movements it can          take. Calibration must be performed to determine which values of the IR sensors correspond to the black or white lines. 
  Drawbacks in code: Does not check for cases where 2 or more sensors give a value of 1, was not able to figure out a way to test the code.
  Generally, if-else statements will be extremely jerky and not smooth.
2. PID-controller:
  Implimented PID, which uses analog logic for input from sensors for a better result.

Key learnings over the break
1. Basic functions in Arduino Code
2. Controlling of motors, reverse, forward, and speed control
3. Intuition on the working of PID controller, and why it's better than a simple switch. (working on implementing it in code for the line follower bot)
4. Algorithms for maze solver
 Dijkstra's algorithm, A*
5. Implimentation of PID, learned more code in c++

Difficultues
Relied much on AI to write my thoughts into code directly. 

  
