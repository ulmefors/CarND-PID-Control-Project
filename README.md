# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## PID Control Parameters

The main PID controller is used to steer the vehicle around the track based on the cross track error (CTE). The PID controller is defined by three parameters; Proportional, Derivative, and Integral. The controller output is the linear sum contribution of the three components.

### Proportional
The proportional controller gives an output that is proportional to the error e.g. negative steering value (left steering) if error is positive (position right of center). If position error is doubled, steering angle is doubled.

### Integral
The integral controller acts on the error sum over historical data. If the controller output causes the vehicle to stabilize at a non-zero error, the integral controller will accumulate an error which forces the steering towards the opposite direction. 

### Derivative
The derivative controller operates on the error rate of change. If the error is decreasing (i.e. car approaching the lane center from the right or leaving the center, heading towards the left edge) the derivative controller will contribute positive steering (to the right). The derivative controller is effective in reducing or eliminating overshoot oscillations around the zero-error position.
 
### Parameter Optimization

The optimal PID parameters are found by manual tuning starting with the proportional parameter. A small value (e.g. E-6) is selected and iterative trials are made while increasing `K_p` by steps of e.g. 0.5 or 1.0 orders of magnitude. The controller will eventually steer the vehicle back to the lane center but will probably overshoot the track center and begin to oscillate from left to right. The oscillation can be mitigated by increasing the derivative parameter `K_d` using the same methodology.

With increasing speed the vehicle travels further between every telemetry event. Consequently, the controller must react quicker which may require increased values for both proportional and derivative parameters `K_p` and `K_d`.

## Speed controller

The second PID controller is used to maintain speed at a predefined value. The parameters are found using the same methodology as for the steering controller. However, it is necessary to add a non-zero value to the integral parameter `K_i` in order to reach and maintain the goal speed without oscillations. 

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.

## Project Instructions and Rubric

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.