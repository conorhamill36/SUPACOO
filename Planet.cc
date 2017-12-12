#include "Planet.h"
#include <cmath>
#include <iostream>

using namespace std;


//getter functions
string Planet::name() {return m_name;}
double Planet::mass() {return m_mass;}
double Planet::distance() {return m_distance;}
double Planet::x_position() {return m_x_position;}
double Planet::y_position() {return m_y_position;}
double Planet::x_velocity() {return m_x_velocity;}
double Planet::y_velocity() {return m_y_velocity;}


//setter functions
void Planet::setName(string name){
  m_name=name;
}
void Planet::setMass(double mass){
  m_mass=mass;
}
void Planet::setDistance(double distance){
  m_distance=distance;
}
void Planet::setXPosition(double x_position){
  m_x_position=x_position;
}
void Planet::setYPosition(double y_position){
  m_y_position=y_position;
}
void Planet::setXVelocity(double x_velocity){
  m_x_velocity=x_velocity;
}
void Planet::setYVelocity(double y_velocity){
  m_y_velocity=y_velocity;
}
void Planet::setTimeStep(double time_step){
  m_time_step=time_step;
}


//defining evolve function
double Planet::Evolve(double time_step, double acc_x, double acc_y){
    m_x_position = m_x_position + m_x_velocity*time_step + 0.5*acc_x*time_step*time_step;
    m_x_velocity = m_x_velocity + acc_x*time_step;
    m_y_position = m_y_position + m_y_velocity*time_step + 0.5*acc_y*time_step*time_step;
    m_y_velocity = m_y_velocity + acc_y*time_step;

}
