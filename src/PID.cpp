#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	p_error = 0;
	i_error = 0;
	d_error = 0;
}

void PID::UpdateError(double cte) {
	this->i_error += cte;
	this->d_error = cte - this->p_error;
	this->p_error = cte;
}

double PID::TotalError() {
  // DEBUG
	// std::cout << p_error << " " << Kp*p_error << " " << Ki*i_error << " " << Kd*d_error << std::endl;
	return Kp*p_error + Ki*i_error + Kd*d_error;
}

