/*******
 ** File:    Terran.cpp
 ** Project: Project 4 - UMBC Starcraft
 ** Author:  Jon Woods
 ** Date:    11/17/2022
 ** Section: 20/22
 ** Email:   jwoods6@umbc.edu
 **
 ** This file contains all non-virtual functions in the child class Terran. These functions
 ** construct Terran objects with respect to parent Entity objects, get the value of regular attacks
 ** for all Terrans, and get the value of special attacks for unclassified Terrans.
*******/

#include "Entity.h"
#include "Terran.h"
#include <cstdlib>
#include <ctime>
using namespace std;

// Terran()
// Default constructor for a new Terran object as an Entity.
Terran::Terran(): Entity() {
}

// Terran() overload
// Given a string and an integer, constructs a new Terran object as an Entity with that data as its
// name and health respectively.
Terran::Terran(string name, int hp): Entity(name, hp) {
}

// ~Terran()
// Default destructor for a Terran object.
Terran::~Terran() {
}

// Attack()
// For all Terran objects, outputs and returns a regular attack with random damage.
int Terran::Attack() {
  srand(time(NULL));
  int att = (rand()%6) + 1; // Random int between 1 and 6
  cout << GetName() << " deals ";
  if (att == 1) {
    cout << "1 point of damage!" << endl;
  } else {
    cout << att << " points of damage!" << endl;
  }
  return att;
}

// SpecialAttack()
// For unclassified Terran objects without special attacks, notifies the user and returns zero.
int Terran::SpecialAttack() {
  cout << "You don't have a special attack." << endl;
  return 0;
}
