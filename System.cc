class System{




for (k=0; k<300; k++) {
    //cout << "new time step" << endl;


    for (i=0; i< Planets.size(); i++) { //loop calculating acc for each planet
      //cout << "acc calculation" << endl;
      acc_x=0;
      acc_y=0;
      for (j=0; j < Planets.size(); j++) { //loop calculating x and y acc contribution from each planet on one planet
        if (i!=j) { //if statement stops planet interacting with itself
          change_x=Planets[j].x_position() - Planets[i].x_position();
          change_y=Planets[j].y_position() - Planets[i].y_position();
          r=absolute_value(change_x,change_y);

        //cout << change_x  <<  " " << change_y << " " << r << endl;
          mag_a = G*Planets[j].mass()/( (pow(r,2) ) );

          a_i= mag_a*(change_x/r);
          if ( (Planets[j].x_position() < Planets[i].x_position()) && a_i<0 ) { //if statements accounts for direction of acceleration
              a_i=-a_i;
          }
          //cout << a_i << endl;
          acc_x+=a_i;

          a_j= mag_a*(change_y/r);
          if ( (Planets[j].y_position() < Planets[i].y_position()) && a_j<0 ) { //if statements accounts for direction of acceleration
              a_j=-a_j;
          }
          //cout << a_j << endl;
  }

  double temp_acc[2][Planets.size()]; //defines array to hold acc components for planets

  for (i=0; i< Planets.size(); i++) { //loop evolving each planet based on temporary array of acc

    cout << Planets[i].x_position() << " " << Planets[i].y_position() << endl;
    cout << endl << endl;
  }

