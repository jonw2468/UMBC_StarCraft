/*******
 ** File:    Marine.cpp
 ** Project: Project 4 - UMBC Starcraft
 ** Author:  Jon Woods
 ** Date:    11/17/2022
 ** Section: 20/22
 ** Email:   jwoods6@umbc.edu
 **
 ** This file contains all non-virtual functions in the grandchild class Marine. These functions
 ** construct Marine objects with respect to parent Terran objects and get the value of special
 ** attacks for all Marine-classified Terrans.
*******/
#include "Entity.h"
#include "Terran.h"
#include "Marine.h"
#include <cstdlib>
#include <ctime>
using namespace std;

// Marine()
// Default constructor for a new Marine object as a Terran.
Marine::Marine(): Terran() {
}

// Marine() overload
// Given a string and an integer, constructs a new Marine object as a Terran with that data as its
// Entity name and health.
Marine::Marine(string name, int hp): Terran(name, hp) {
}

// ~Marine()
// Default destructor for a Marine object.
Marine::~Marine() {
  SetName("");
  SetHealth(0);
}

// SpecialAttack()
// Outputs and returns a special attack with random damage.
int Marine::SpecialAttack() {
  srand(time(NULL));
  int att = (rand()%8) + 1; // Random int between 1 and 8
  cout << GetName() << " spins up doing GATLING DAMAGE!" << endl;
  return att;
}
