/*******
 ** File:    Mutalisk.cpp
 ** Project: Project 4 - UMBC Starcraft
 ** Author:  Jon Woods
 ** Date:    11/17/2022
 ** Section: 20/22
 ** Email:   jwoods6@umbc.edu
 **
 ** This file contains all non-virtual functions in the grandchild class Mutalisk. These functions construct Mutalisk objects with respect to parent Zerg objects and get the value of special attacks for all Mutalisk-classified Zergs.
*******/
#include "Zerg.h"
#include "Entity.h"
#include "Mutalisk.h"
using namespace std;

// Mutalisk()
// Default constructor for a Mutalisk object as a Zerg.
Mutalisk::Mutalisk(): Zerg() {
}

// Mutalisk() overload
// Given a string and an integer, constructs a new Mutalisk object as a Zerg with that data as its Entity name and health.
Mutalisk::Mutalisk(string name, int hp): Zerg(name, hp) {
}

// SpecialAttack()
// Outputs and returns a special attack with damage of 4.
int Mutalisk::SpecialAttack() {
  cout << GetName() << " blasts you with their attack!" << endl;
  return 4;
}
