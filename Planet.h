#ifndef PLANET_H
#define PLANET_H
#include <string>
#include <iostream>

using namespace std;

class Planet {

public:
  //getter functions
  string name();
  double mass();
  double distance();
  double x_position();
  double y_position();
  double x_velocity();
  double y_velocity();
  double x_acceleration();
  double y_acceleration();
  double time_step();


  //setter functions
  void setName(string name);
  void setMass(double mass);
  void setDistance(double distance);
  void setXPosition(double x_position);
  void setYPosition(double y_position);
  void setXVelocity(double x_velocity);
  void setYVelocity(double y_velocity);
  void setTimeStep(double time_step);

  //evolve function
  double Evolve (double time_step, double x_acceleration, double y_acceleration);


protected:

  string m_name;
  double m_mass;
  double m_distance;
  double m_x_position;
  double m_y_position;
  double m_x_velocity;
  double m_y_velocity;
  double m_x_acceleration;
  double m_y_acceleration;
  double m_time_step;

};

#endif
