#include "PID.h"

PID::PID() = default;

PID::~PID() = default;

//Initialize the error
void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    p_error = 0;
    i_error = 0;
    d_error = 0;
}

//Update the error
void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

//Calculate the PID (actually is a PD) and return the steer angle
double PID::TotalError() {
    return Kp*p_error + Ki*i_error + Kd*d_error;
}

