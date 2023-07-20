/*******
 ** File:    Ghost.cpp
 ** Project: Project 4 - UMBC Starcraft
 ** Author:  Jon Woods
 ** Date:    11/17/2022
 ** Section: 20/22
 ** Email:   jwoods6@umbc.edu
 **
 ** This file contains all non-virtual functions in the grandchild class Marine. These functions
 ** construct Ghost objects with respect to parent Terran objects and get the value of special
 ** attacks for all Ghost-classified Terrans.
*******/
#include "Entity.h"
#include "Terran.h"
#include "Ghost.h"
#include <cstdlib>
using namespace std;

// Ghost()
// Default constructor for a Ghost object as a Terran.
Ghost::Ghost(): Terran() {
}

// Ghost() overload
// Given a string and an integer, constructs a new Ghost object as a Terran with that data as its
// Entity name and health.
Ghost::Ghost(string name, int hp): Terran(name, hp) {
}

// ~Ghost()
// Default destructor for a Ghost object.
Ghost::~Ghost() {
  SetName("");
  SetHealth(0);
}

// SpecialAttack()
// Outputs and returns a special attack with random damage.
int Ghost::SpecialAttack() {
  srand(time(NULL));
  int att = (rand()%11) + 2; // Random int between 2 and 12
  cout << GetName() << " performs a sneak attack!" << endl;
  return att;
}
