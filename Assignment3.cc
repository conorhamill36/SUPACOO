#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>
#include "Planet.h"

using namespace std;

double absolute_value(double x, double y) {
  return pow((pow(x,2) + pow(y,2)),0.5);;
}

int main(int argc,char* argv[2]){

  double simulation_length = atof(argv[1]);
  double time_step = atof(argv[2]);
  int i, j, k;
  string name_input, name_printing;
  double mass_input, distance_input, sum_mass_distance, x_position_input, y_position_input;
  double x_velocity_input, y_velocity_input;
  double G = 6.67408e-11; //gravitational constant in SI units
  double acc_x, acc_y;
  double a_i, a_j;
  double change_x, change_y, r, mag_a;
  vector<Planet> Planets;

  //Opening file
  ifstream myInput;
  ofstream myOutput;

  myInput.open("input.txt");
  if (myInput.fail() ) {
    cout << "Sorry, couldn't open file" << endl;
    exit(1);
  }

  myOutput.open("Assignment3_output.txt");


  //Loop to read in lines of file
  i=0;
  while ( !myInput.eof() ){
    myInput >> name_input >>  mass_input >> x_position_input >> y_position_input >> x_velocity_input >> y_velocity_input; //input from file
    if (myInput.eof()==true) {
      break;
    }
    //cout << name_input << " " << mass_input << " " << x_position_input << " " << y_position_input << " " << x_velocity_input << " " << y_velocity_input << endl; //testing file input properly

    //defining object from class Planet
    Planet New_Planet;
    //setting data members of class
    New_Planet.setName(name_input);
    New_Planet.setMass(mass_input);
    New_Planet.setXPosition(x_position_input);
    New_Planet.setYPosition(y_position_input);
    New_Planet.setXVelocity(x_velocity_input);
    New_Planet.setYVelocity(y_velocity_input);
    New_Planet.setTimeStep(time_step);

    //Adding object to planet vector
    Planets.push_back(New_Planet);

    i++;
  }

  myInput.close();
  cout <<  endl <<  endl <<  endl;
  //loop uses getters to check objects have correct variables
  i=0;
  while(i<Planets.size()) {
    cout << Planets[i].name() << " " << Planets[i].mass() << " " << Planets[i].x_position() << " " << Planets[i].y_position() << " " << Planets[i].x_velocity() << " " << Planets[i].y_velocity() << " " << endl;
    i++;
  }

  double temp_acc[2][Planets.size()]; //defines array to hold acc components for planets
  for (k=0; k<1000; k++) { //loop with number of time steps taken


    for (i=0; i< Planets.size(); i++) { //loop calculating acc for each planet
      acc_x=0;
      acc_y=0;
      for (j=0; j < Planets.size(); j++) { //loop calculating x and y acc contribution from each planet on one planet
        if (i!=j) { //if statement stops planet interacting with itself
          change_x=Planets[j].x_position() - Planets[i].x_position();
          change_y=Planets[j].y_position() - Planets[i].y_position();
          r=absolute_value(change_x,change_y);

          mag_a = G*Planets[j].mass()/( r*r ); //magnitude of acceleration

          a_i= mag_a*(change_x/r);
          // cout << a_i << " ";
          acc_x+=a_i;

          a_j= mag_a*(change_y/r);
          // cout << a_j << endl << endl;
          acc_y+=a_j;
        }
        cout << acc_x << " " << acc_y << endl;
      }
      //Save new accelerations in an array
      temp_acc[0][i]=acc_x;
      temp_acc[1][i]=acc_y;
      cout << endl;
      if (Planets[i].name() == "Earth") {
        myOutput << Planets[i].x_position() << " " << Planets[i].y_position() << endl;
      }
    }

    cout << endl;

    for (i=0; i< Planets.size(); i++) { //loop evolving each planet based on temporary array of acc
      acc_x=temp_acc[0][i];
      acc_y=temp_acc[1][i];
      // cout <<  acc_x << " " << acc_y << endl;
      // cout << Planets[i].x_position() << " " << Planets[i].y_position() << endl;
      Planets[i].Evolve(time_step, acc_x, acc_y);
      // cout << Planets[i].x_position() << " " << Planets[i].y_position() << endl;
      // cout << endl << endl;
      }
  }


  i=0;
  cout << acc_x << " " << acc_y << endl;
  myOutput.close();






  return 0;
}
