/*******
 ** File:    Zerg.cpp
 ** Project: Project 4 - UMBC Starcraft
 ** Author:  Jon Woods
 ** Date:    11/17/2022
 ** Section: 20/22
 ** Email:   jwoods6@umbc.edu
 **
 ** This file contains all non-virtual functions in the child class Zerg. These functions construct
 ** Zerg objects with respect to parent Entity objects and get the value of regular attacks for
 ** all Zergs.  
*******/
#include "Entity.h"
#include "Zerg.h"
using namespace std;


// Zerg()
// Default constructor for a new Zerg object as an Entity.
Zerg::Zerg(): Entity() {
}

// Zerg() overload
// Given a string and an integer, constructs a new Zerg object as an Entity with that data as its
// name and health respectively.
Zerg::Zerg(string name, int hp): Entity(name, hp) {
}

// Attack()
// For all Zerg objects, outputs and returns a regular attack with a damage of 1.
int Zerg::Attack() {
  cout << GetName() << " deals 1 point of damage!" << endl;
  return 1;
}
