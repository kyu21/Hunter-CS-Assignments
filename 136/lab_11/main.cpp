#include <iostream>
#include <string>

#include "def.h"

int main() {
    Coord3D pointP = {10, 20, 30};
    cout << length(&pointP) << endl << endl; // would print 37.4166

    Coord3D pointQ = {-20, 21, -22};

    cout << "Address of P: " << &pointP << endl;
    cout << "Address of Q: " << &pointQ << endl;

    Coord3D * ans = fartherFromOrigin(&pointP, &pointQ);
   
    cout << "ans = " << ans << endl << endl; // So which point is farther?

    Coord3D pos = {0, 0, 100.0};
    Coord3D vel = {1, -5, 0.2};

    move(&pos, &vel, 2.0); // struct pos gets changed
    cout << pos.x << " " << pos.y << " " << pos.z << endl;
    // prints: 2 -10 100.4

    double x, y, z;
    cout << "\nEnter position: 10 20 30\n";
    Coord3D *ppos = createCoord3D(10,20,30);
    
    cout << "Enter velocity: 5.5 -1.4 7.77\n";
    Coord3D *pvel = createCoord3D(5.5,-1.4,7.77);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " 
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);

    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);

	return 0;
}