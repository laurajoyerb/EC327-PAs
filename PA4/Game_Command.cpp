#include <iostream>
#include "Game_Command.h"

using namespace std;

void do_move_command(Model& model)
{
  int id;
  double x, y;
  char ax;

  cin >> id >> x >> y;

  cout << "Move Astronaut (enter 'a') or Alien (enter 'x'): ";
  cin >> ax;

  while (ax != 'x' && ax != 'a')
  {
    cout << "Please enter 'a' for Astronaut or 'x' for Alien: ";
    cin >> ax;
  }

  Cart_Point pt = Cart_Point(x,y);

  if (ax == 'a')
  {
    Person* p = model.get_Person_ptr(id);
    p -> start_moving(pt);
  }
  else if (ax == 'x')
  {
    Alien* x = model.get_Alien_ptr(id);
    x -> start_moving(pt);
  }
}

void do_work_command(Model& model)
{
  int id1, id2;

  cin >> id1 >> id2;

  Person* p = model.get_Person_ptr(id1);
  Oxygen_Depot* od = model.get_Oxygen_Depot_ptr(id2);

  p -> start_supplying(od);
}

void do_deposit_command(Model& model)
{
  int id1, id2;

  cin >> id1 >> id2;

  Person* p = model.get_Person_ptr(id1);
  Space_Station* ss = model.get_Space_Station_ptr(id2);

  p -> start_depositing(ss);
}

void do_stop_command(Model& model)
{
  int id;
  char ax;

  cin >> id;

  cout << "Move Astronaut (enter 'a') or Alien (enter 'x'): ";
  cin >> ax;

  while (ax != 'x' && ax != 'a')
  {
    cout << "Please enter 'a' for Astronaut or 'x' for Alien: ";
    cin >> ax;
  }

  if (ax == 'a')
  {
    Person* p = model.get_Person_ptr(id);
    p -> stop();
  }
  else if (ax == 'x')
  {
    Alien* x = model.get_Alien_ptr(id);
    x -> stop();
  }
}

void do_lock_command(Model& model)
{
  int id1, id2;

  cin >> id1 >> id2;

  Person* p = model.get_Person_ptr(id1);
  Space_Station* ss = model.get_Space_Station_ptr(id2);

  p -> go_to_station(ss);
}

void do_go_command(Model& model)
{
  cout << "Advancing one tick." << endl;
  model.update();
  model.show_status();
}

void do_run_command(Model& model)
{
  cout << "Advancing to next event." << endl;
  bool var = model.update(); // calls update at least once
  int counter = 0;
  while (!var && counter < 4) // allows this loop to run 4 times because 5th time is outside of loop
  {
    var = model.update();
    counter++;
  }
  model.show_status();
}

void do_attack_command(Model& model)
{
  int id1, id2;

  cin >> id1 >> id2;

  Person* p = model.get_Person_ptr(id1);
  Alien* x = model.get_Alien_ptr(id2);

  x -> start_attack(p);
}

void do_quit_command(Model& model)
{
  cout << "Terminating program." << endl;
  model.~Model();
  exit(0);
}