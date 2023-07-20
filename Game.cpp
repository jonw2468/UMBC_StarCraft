/*******
 ** File:    Game.cpp
 ** Project: Project 4 - UMBC Starcraft
 ** Author:  Jon Woods
 ** Date:    11/17/2022
 ** Section: 20/22
 ** Email:   jwoods6@umbc.edu
 **
 ** This file contains all functions involving Game objects. These functions construct Game objects,
 ** populate the map vector with Area objects, initialize player Terran objects and oppenent Zerg
 ** objects and control all user inputs and menus in order to run the UMBC Starcraft.
*******/
#include "Game.h"
#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

// Game()
// Default constructor with all default data.
Game::Game() {
  m_filename = FILE_NAME;
  m_curArea = START_AREA;
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
  m_wins = START_WINS;
}

// Game() overload
// Given the name of a file, constructs a new Game object with a the file name as the name in the
// parameter and all other default data.
Game::Game(string file) {
  m_filename = file;
  m_curArea = START_AREA;
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
  m_wins = START_WINS;
}

// ~Game()
// Default destructor for a Game object.
// Sets all data back to their default values, nullifies both Entity pointers, and replaces the
// map with an empty one.
Game::~Game() {
  vector<Area*> emptyMap;
  m_myTerran = nullptr;
  m_myMap.swap(emptyMap);
  m_curArea = START_AREA;
  m_curZerg = nullptr;
  m_numRests = NUM_RESTS;
  m_numSpecial = NUM_SPECIAL;
  m_filename = FILE_NAME;
  m_wins = START_WINS;
}

// TerranCreation()
// Assigns the m_myTerran pointer to a new Terran object classified by user input.
void Game::TerranCreation() {
  string myName;
  int type;
  cout << "Terran Name: ";
  getline(cin, myName);
  // User input with validation
  do {
    cout << "Select a class\n1. Marine\n2. Ghost\n3. Battlecruiser\n4. No Class" << endl;
    cin >> type;
  } while (type < 1 || type > 4);
  switch (type) {
  case 1:
    m_myTerran = new Marine(myName, MARINE_HEALTH);
    break;
  case 2:
    m_myTerran = new Ghost(myName, GHOST_HEALTH);
    break;
  case 3:
    m_myTerran = new Battlecruiser(myName, BATTLECRUISER_HEALTH);
    break;
  case 4:
    m_myTerran = new Terran(myName, TERRAN_HEALTH);
  }
}

// LoadMap()
// Opens and reads the file given by m_filename and populates the map vector with Area pointers
// accordingly.
void Game::LoadMap() {
  fstream reader;
  reader.open(m_filename.c_str());
  cout << "Loading map..." << endl;
  string id, name, desc, north, east, south, west;
  // Check every line in the input as separated by "|"
  while (getline(reader, id, DELIMITER) && getline(reader, name, DELIMITER)) {
    getline(reader, desc, DELIMITER);
    getline(reader, north, DELIMITER);
    getline(reader, east, DELIMITER);
    getline(reader, south, DELIMITER);
    getline(reader, west, DELIMITER);
    reader.ignore(256,'\n');
    Area* newArea = new Area(stoi(id), name, desc, stoi(north), stoi(east), stoi(south), stoi(west));
    m_myMap.push_back(newArea);
  }
}

// StartGame()
// Welcomes the user, populates the map, assigns the player Terran, and moves the user to the
// starting area.
void Game::StartGame() {
  cout << "Welcome to the UMBC Starcraft!" << endl;
  LoadMap();
  TerranCreation();
  m_curArea = START_AREA;
  m_myMap.at(m_curArea)->PrintArea();
  Action();
}

// Action()
// Prints the area, moves to another area, starts a battle Zerg battle, or rests the player Terran
// based on user input. Repeats until the user runs out of health or inputs to quit.
void Game::Action() {
  int choice = 0;
  m_curZerg = RandomZerg();
  int curHealth = m_myTerran->GetHealth();
  do {
    // User input with validation
    do {
      cout << "What would you like to do?\n1. Look\n2. Move\n3. Attack Zerg\n4. Rest\n5. Check Stats\n6. Quit" << endl;
      cin >> choice;
    } while (choice < 1 || choice > 6);
    switch (choice) {
    case 1:
      m_myMap.at(m_curArea)->PrintArea();
      break;
    case 2:
      Move();
      m_curZerg = RandomZerg();
      break;
    case 3:
      Attack();
      curHealth = m_myTerran->GetHealth();
      break;
    case 4:
      Rest();
      curHealth = m_myTerran->GetHealth();
      break;
    case 5:
      Stats();
      break;
    }
  } while (choice != 6 && curHealth > 0);
  // Repeat until user inputs 6 OR the player Terran runs out of health
  cout << "Thanks for playing!" << endl;
}

// RandomZerg()
// Outputs and returns a randomly generated Zerg pointer for the user's current area.
Entity* Game::RandomZerg() {
  srand(time(NULL));
  int zergType = rand() % 4; // Random number between 0 and 3
  switch (zergType) {
  case 1: // Generate a zergling
    cout << "A small terrifying zergling waits here." << endl;
    return new Zergling("Zergling", ZERGLING_HEALTH);
    break;
  case 2: // Generate a mutalisk
    cout << "A large flying mutalisk hovers here." << endl;
    return new Mutalisk("Mutalisk", MUTALISK_HEALTH);
    break;
  case 3: // Generate a hydralisk
    cout << "A medium sized hydralisk slithers here waiting to cover you with acid." << endl;
    return new Hydralisk("Hydralisk", HYDRALISK_HEALTH);
    break;
  default: // Case 0, but a default prevents logic errors: no Zerg is generated
    cout << "It is peaceful here." << endl;
    return nullptr;
    break;
  }
}

// Rest()
// Checks whether the user can rest in the current area. If so, increases the player Terran's health
// and resets the special attack counter.
void Game::Rest() {
  if (m_curZerg != nullptr) { // End function if the current area is not peaceful
    cout << "You can't rest while there's a zerg nearby." << endl;
    return;
  }
  if (m_numRests == 0) { // End function if the user is out of rests
    cout << "You don't have any rests remaining." << endl;
    return;
  }
  // Otherwise restore player stats and decrement the remaining rest count
  cout << "You rested and gained " << REST_HEAL << " health." << endl;
  m_myTerran->SetHealth(m_myTerran->GetHealth() + REST_HEAL);
  m_numRests--;
  m_numSpecial = NUM_SPECIAL;
}

// Move()
// Assigns m_curArea to the ID of an adjacent Area based on user input.
// Outputs data of the user's new Area.
void Game::Move() {
  char direction;
  int move = -1;
  // User input with validation
  while (move == -1) {
    cout << "Where would you like to go? (N E S W)" << endl;
    cin >> direction;
    // Convert input to a cardinal direction and check for an Area in that direction
    if (direction == 'N' || direction == 'n') {
      move = m_myMap.at(m_curArea)->CheckDirection(n);
      if (move == -1) {
        cout << "You can't go north from here!" << endl;
      }
    } else if (direction == 'E' || direction == 'e') {
      move = m_myMap.at(m_curArea)->CheckDirection(e);
      if (move == -1) {
	cout << "You can't go east from here!" << endl;
      }
    } else if (direction == 'S' || direction == 's') {
      move = m_myMap.at(m_curArea)->CheckDirection(s);
      if (move == -1) {
        cout << "You can't go south from here!" << endl;
      }
    } else if (direction == 'W' || direction == 'w') {
      move = m_myMap.at(m_curArea)->CheckDirection(w);
      if (move == -1) {
        cout << "You can't go west from here!" << endl;
      }
    }
    // If input does not correspond to a direction nothing happens
  }
  m_curArea = move;
  m_myMap.at(m_curArea)->PrintArea();
}

// Attack()
// Checks if a Zerg is present. If so, controls a battle with the current area's Zerg based on user
// input. Repeats until the player Terran and/or the Zerg have no health remaining and declares
// parameters for ProcessBattle().
void Game::Attack() {
  if (m_curZerg != nullptr) {
    int choice;
    // Storage variables for each Entity's health
    int myHealth = m_myTerran->GetHealth();
    int zergHealth = m_curZerg->GetHealth();
    // Repeat until one or more Entities have a health of 0
    while (myHealth > 0 && zergHealth > 0) {
      int myAttack = 0;
      // User input with validation
      do {
	cout << "1. Normal Attack\n2. Special Attack" << endl;
	cin >> choice;
	switch (choice) {
	case 1: // User does a regular attack
	  myAttack = m_myTerran->Attack();
	  break;
	case 2:
	  if (m_numSpecial == 0) {
	    // Notifies user of classified Terrans who are out of special attacks
	    cout << "You don't have any special attacks left." << endl;
	  } else {
	    myAttack = m_myTerran->SpecialAttack();
	  }
	  break;
	}
      } while ((choice != 1 && choice != 2) || myAttack == 0);
      if (choice == 2) { // Decrement user's special attack count if needed
	m_numSpecial--;
      }
      zergHealth -= myAttack;
      m_curZerg->SetHealth(zergHealth);
      // Randomly select type for the Zerg's counterattack
      srand(time(NULL));
      int zergAttack = rand() % 2; // 50% chance of each type of attack
      switch (zergAttack) {
      case 0:
	myHealth -= m_curZerg->Attack();
	break;
      case 1:
	myHealth -= m_curZerg->SpecialAttack();
	break;
      }
      m_myTerran->SetHealth(myHealth);
    }
    ProcessBattle(zergHealth > 0, myHealth > 0);
    m_curZerg = nullptr;
  } else {
    cout << "There's no zerg to attack." << endl;
  }
}

// Stats()
// Displays the name, health, rest count, special attack count, and win count of the player Terran.
void Game::Stats() {
  cout << *m_myTerran << endl;
  cout << "Rests remaining: " << m_numRests << endl;
  cout << "Special attacks remaining: " << m_numSpecial << endl;
  cout << "Zergs defeated: " << m_wins << endl;
}

// ProcessBattle()
// Checks whether the player Terran won, the current Zerg won, or they tied.
// If user won, increments player Terran's win count and checks whether they earned a rest.
void Game::ProcessBattle(bool zergAlive, bool alive) {
  if (alive) { // Battle results in a win
    cout << "You defeated the " << m_curZerg->GetName() << "!" << endl;
    m_wins++;
    srand(time(NULL));
    // 10% chance of earning a rest after winning
    int checkRest = rand() % 10;
    if (checkRest == 0) {
      cout << "You gained another rest!" << endl;
      m_numRests++;
    }
  } else if (zergAlive) { // Battle results in a loss
    cout << "The " << m_curZerg->GetName() << " defeated you!" << endl;
  } else { // Battle results in a tie
    cout << "You defeated each other at the same time!" << endl;
  }
}
