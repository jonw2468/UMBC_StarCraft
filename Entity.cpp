/*******
 ** File:    Entity.cpp
 ** Project: Project 4 - UMBC Starcraft
 ** Author:  Jon Woods
 ** Date:    11/17/2022
 ** Section: 20/22
 ** Email:   jwoods6@umbc.edu
 **
 ** This file contains all non-virtual functions in the parent class Entity. These functions
 ** construct and destruct the name and health values of an Entity object as well as call those
 ** values to be used by other classes.
*******/
#include "Entity.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

// Entity()
// Default constructor for a new Entity object.
Entity::Entity() {
}

// Entity() overload
// Given a string and an integer, constructs a new Entity object with that data as its name and
// health respectively.
Entity::Entity(string name, int health) {
  m_name = name;
  m_health = health;
}

// ~Entity()
// Default destructor for an Entity object.
Entity::~Entity() {
}

// GetName()
// Returns the name of an Entity object.
string Entity::GetName() {
  return m_name;
}

// GetHealth()
// Returns the health value of an Entity object.
int Entity::GetHealth() {
  return m_health;
}

// SetName()
// Given a string, replaces the name of an Entity object with that string.
void Entity::SetName(string name) {
  m_name = name;
}

// SetHealth()
// Given an integer, resets the health value for an Entity object to that integer.
void Entity::SetHealth(int health) {
  m_health = health;
}

// << overload
// Displays the name and current health of an Enttity object that is called by an output stream.
ostream& operator<<(ostream& out, Entity& thisEntity) {
  out << thisEntity.GetName() << "'s health: " << thisEntity.GetHealth() << endl;
  return out;
}
