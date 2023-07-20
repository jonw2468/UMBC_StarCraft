/*******
 ** File:    Zergling.cpp
 ** Project: Project 4 - UMBC Starcraft
 ** Author:  Jon Woods
 ** Date:    11/17/2022
 ** Section: 20/22
 ** Email:   jwoods6@umbc.edu
 **
 ** This file contains all non-virtual functions in the grandchild class Zergling. These functions
 ** construct Zergling objects with respect to parent Zerg objects and get the value of special
 ** attacks for all Zergling-classified Zergs.
*******/
#include "Zerg.h"
#include "Entity.h"
#include "Zergling.h"
#include <cstdlib>
using namespace std;

// Zergling()
// Default constructor for a Zergling object as a Zerg.
Zergling::Zergling(): Zerg() {
}

// Zergling() overload
// Given a string and an integer, constructs a new Zergling object as a Zerg with that data as its
// Entity name and health.
Zergling::Zergling(string name, int hp): Zerg(name, hp) {
}

// SpecialAttack()
// Outputs and returns a special attack with damage of 1.
int Zergling::SpecialAttack() {
  cout << GetName() << " scratches at you ferociously!" << endl;
  return 1;
}
