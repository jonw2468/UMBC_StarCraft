/*******
 ** File:    Battlecruiser.cpp
 ** Project: Project 4 - UMBC Starcraft
 ** Author:  Jon Woods
 ** Date:    11/17/2022
 ** Section: 20/22
 ** Email:   jwoods6@umbc.edu
 **
 ** This file contains all non-virtual functions in the grandchild class Battlecruiser. These
 ** functions construct Battlecruiser objects with respect to parent Terran objects and get the
 ** value of special attacks for all Battlecruiser-classified Terrans.
*******/
#include "Entity.h"
#include "Terran.h"
#include "Battlecruiser.h"
#include <cstdlib>
#include <ctime>
using namespace std;

// Battlecruiser()
// Default constructor for a Battlecruiser object as a Terran.
Battlecruiser::Battlecruiser(): Terran() {
}

// Battlecruiser() overload
// Given a string and an integer, constructs a new Battlecruiser object as a Terran with that data
// as its Entity name and health.
Battlecruiser::Battlecruiser(string name, int hp): Terran(name, hp) {
}

// ~Battlecruiser()
// Default destructor for a Battlecruiser object.
Battlecruiser::~Battlecruiser() {
  SetName("");
  SetHealth(0);
}

// SpecialAttack()
// Outputs and returns a special attack with random damage.
int Battlecruiser::SpecialAttack() {
  srand(time(NULL));
  int att = (rand()%10) + 3; // Random int between 3 and 12
  cout << GetName() << " uses the Yomato Cannon!" << endl;
  return att;
}
