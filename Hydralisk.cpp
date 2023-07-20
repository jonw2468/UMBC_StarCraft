/*******
 ** File:    Hydralisk.cpp
 ** Project: Project 4 - UMBC Starcraft
 ** Author:  Jon Woods
 ** Date:    11/17/2022
 ** Section: 20/22
 ** Email:   jwoods6@umbc.edu
 **
 ** This file contains all non-virtual functions in the grandchild class Hydralisk. These functions construct Hydralisk objects with respect to parent Zerg objects and get the value of special attacks for all Hydralisk-classified Zergs.
*******/
#include "Zerg.h"
#include "Entity.h"
#include "Hydralisk.h"
using namespace std;

// Hydralisk()
// Default constructor for a Hydralisk object as a Zerg.
Hydralisk::Hydralisk(): Zerg() {
}

// Hydralisk() overload
// Given a string and an integer, constructs a new Hydralisk object as a Zerg with that data as its
// Entity name and health.
Hydralisk::Hydralisk(string name, int hp): Zerg(name, hp) {
}

// SpecialAttack()
// Outputs and returns a special attack with damage of 2.
int Hydralisk::SpecialAttack() {
  cout << GetName() << " sprays you with deadly acid!" << endl;
  return 2;
}
