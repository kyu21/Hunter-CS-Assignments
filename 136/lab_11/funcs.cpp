#include <iostream>
#include <string>
#include <cmath>

#include "def.h"

using namespace std;

double length(Coord3D *p) {
  double xy = sqrt(((*p).x * (*p).x) + ((*p).y * (*p).y));
  double xyz = sqrt(xy * xy + ((*p).z * (*p).z));
  return xyz;
}

Coord3D * fartherFromOrigin(Coord3D *p1, Coord3D *p2) {
  double distance_one = length(p1);
  double distance_two = length(p2);
  if (distance_one >= distance_two) {
    return p1;
  }
  else {
    return p2;
  }
}

void move(Coord3D *ppos, Coord3D *pvel, double dt) {
  (*ppos).x += (*pvel).x * dt;
  (*ppos).y += (*pvel).y * dt;
  (*ppos).z += (*pvel).z * dt;
}

Coord3D* createCoord3D(double x, double y, double z) {
  Coord3D *cord = new Coord3D;
  (*cord).x = x;
  (*cord).y = y;
  (*cord).z = z;
  return cord;
}

void deleteCoord3D(Coord3D *p) {
  delete p;
}

Particle* createParticle(double x, double y, double z, double vx, double vy, double vz) {
  Particle *part = new Particle;
  (*part).x = x;
  (*part).y = y;
  (*part).z = z;
  (*part).vx = vx;
  (*part).vy = vy;
  (*part).vz = vz;
  return part;
}

void setVelocity(Particle *p, double vx, double vy, double vz) {
  (*p).vx = vx;
  (*p).vy = vy;
  (*p).vz = vz;
}

Coord3D getPosition(Particle *p) {
  Coord3D cord = {(*p).x, (*p).y, (*p).z};
  return cord;
}

void move(Particle *p, double dt) {
  (*p).x += (*p).vx * dt;
  (*p).y += (*p).vy * dt;
  (*p).z += (*p).vz * dt;
}

void deleteParticle(Particle *p) {
  delete p;
}
