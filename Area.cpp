/*******
 ** File:    Area.cpp
 ** Project: Project 4 - UMBC Starcraft
 ** Author:  Jon Woods
 ** Date:    11/17/2022
 ** Section: 20/22
 ** Email:   jwoods6@umbc.edu
 **
 ** This file contains all functions involving Area objects. These functions construct, get, and
 ** display the name, description, and coordinate-based surroundings of Area objects.
*******/
#include "Area.h"
#include <iostream>
#include <string>
using namespace std;

// Area()
// Given an index integer, 2 strings, and 4 integers, constructs a new Area object with the index as
// its ID, the strings as its name and description respectively, and the other integers as the index
// IDs of Areas in each cardinal direction.
Area::Area(int id, string name, string desc, int north, int east, int south, int west) {
  m_ID = id;
  m_name = name;
  m_desc = desc;
  m_direction[n] = north;
  m_direction[e] = east;
  m_direction[s] = south;
  m_direction[w] = west;
}

// GetName()
// Returns the name of an Area object.
string Area::GetName() {
  return m_name;
}

// GetID()
// Returns the index ID of an Area object.
int Area::GetID() {
  return m_ID;
}

// GetDesc()
// Returns the description of an Area object.
string Area::GetDesc() {
  return m_desc;
}

// CheckDirection()
// Given an enum cardinal direction, returns the ID in that direction from an Area object.
int Area::CheckDirection(char myDirection) {
  return m_direction[myDirection];
}

// PrintArea()
// Displays the name and description of an Area object.
// Calculates and displays the cardinal directions with an exit.
void Area::PrintArea() {
  cout << GetName() << endl;
  cout << GetDesc() << endl;
  cout << "Possible Exits: ";
  string exits = "";
  // Check each direction and append them to the exits string accordingly
  if (CheckDirection(n) != -1)
    exits += "N ";
  if (CheckDirection(e) != -1)
    exits += "E ";
  if (CheckDirection(s) != -1)
    exits += "S ";
  if (CheckDirection(w) != -1)
    exits += "W";
  
  if (exits == "") {
    cout << "None" << endl;
  } else {
    cout << exits << endl;
  }
}
