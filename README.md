# PID Control
[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)


[//]: # (Image References)
[image1]: ./images/image1.png

## Basic instructions to run the code
1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
   * On windows, you may need to run: `cmake .. -G "Unix Makefiles" && make`
4. Run it: `./pid `

## [Rubric](https://review.udacity.com/#!/rubrics/824/view) Points
### Here I will consider the rubric points individually and describe how I addressed each point in my implementation.
---

### Compiling

#### 1. Code must compile without errors with cmake and make. Given that we've made CMakeLists.txt as general as possible, it's recommended that you do not change it unless you can guarantee that your changes will still compile on any platform.
My code is compiling ok, as you can see here (with two warnings that it was at the main):
`Scanning dependencies of target pid`
`[ 33%] Building CXX object CMakeFiles/pid.dir/src/PID.cpp.o`
`[ 66%] Building CXX object CMakeFiles/pid.dir/src/main.cpp.o`
`/media/marlosdamasceno/Dados/Udacity/Self Drive Car/Codes/PID Control/src/main.cpp: In lambda function:`
`/media/marlosdamasceno/Dados/Udacity/Self Drive Car/Codes/PID Control/src/main.cpp:61:28: warning: unused variable` `‘speed’ [-Wunused-variable]`
`double speed = std::stod(j[1]["speed"].get<std::string>());`
`^`
`/media/marlosdamasceno/Dados/Udacity/Self Drive Car/Codes/PID Control/src/main.cpp:62:28: warning: unused variable` `‘angle’ [-Wunused-variable]`
`double angle = std::stod(j[1]["steering_angle"].get<std::st`
`^`
`[100%] Linking CXX executable pid`
`[100%] Built target pid`


### Implementation

#### 1. It's encouraged to be creative, particularly around hyperparameter tuning/optimization. However, the base algorithm should follow what's presented in the lessons.
It follow the lessons, specially this [link](https://youtu.be/YamBuzDjrs8). I tried to use a mean for the steer angle, however did not work as expected.

### Reflection

#### 1. Student describes the effect of the P, I, D component of the PID algorithm in their implementation. Is it what you expected? Visual aids are encouraged, i.e. record of a small video of the car in the simulator and describe what each component is set to.
- The **P** is the proportional to the error, that tries to keep the car in the center of the road. However, if set too high the, the car get out of the road. [Here](https://youtu.be/UYgCRVD6yjQ) you can see P set as -10.

- The **I** is integral part, that sum the errors. But, if this component is much bigger than zero it will shoot the car out of the road. Therefore, I left it as 0, at the end the day is a **PD** instead of PID. [Here](https://youtu.be/ArEBaDgy0v8) you can see I set as -10.

- The **D** is the derivative of the error, that decrease the overshoot of the car. [Here](https://youtu.be/aM5LFEU51Yw) you can see I set as -15. You can see that the car keeps more at the center, however the steering is much more abrupt compared to a low level of D.

#### 2. Student discusses how they chose the final hyperparameters (P, I, D coefficients). This could be have been done through manual tuning, twiddle, SGD, or something else, or a combination!
I choose the combination of hyper-parameters manually, by try and check! At the end I got [-0.2, 0, -1.5]. P = -0.2, I = 0 and D = -1.5. I left the **I** set to zero and it is a **PD** instead a **PID**. The D was set to -1.5 to be less abrupt the steering of the car.

### Simulation

#### 1. No tire may leave the drivable portion of the track surface. The car may not pop up onto ledges or roll over any surfaces that would otherwise be considered unsafe (if humans were in the vehicle).
You can see the result of the simulation at this [link](https://youtu.be/Yb-jjXB7cPQ). Top speed was 34 mph.
