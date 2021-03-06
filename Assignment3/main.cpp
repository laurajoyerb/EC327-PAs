#include <iostream>
#include <string>
#include "Game_Command.h"
#include "Model.h"
#include "View.h"

using namespace std;

int main()
{
  // Intro statements
  cout << "EC327: Introduction to Software Engineering" << endl;
  cout << "Fall 2017" << endl;
  cout << "Programming Assignment 3" << endl;

  // command holds first char in user input to determine next action
  char command;

  // Initializes m to hold all game information (note does not use copy constructor!)
  Model m;

  View v = View();

  // Begins game with statuses of all objects and the initial display and time
  m.show_status();
  m.display(v);


  while (true) // runs until broken by an exit(0)
  {
    bool valid = true; // stores whether or not command was a valid command

    cout << endl;
    cout << "Commands:" << endl;
    cout << "m ID1 X Y to move" << endl;
    cout << "w ID1 ID2 to work an oxygen depot" << endl;
    cout << "d ID1 ID2 to deposit moonstones" << endl;
    cout << "s ID1 to stop" << endl;
    cout << "l ID1 ID2 to lock in at space station" << endl;
    cout << "g to go" << endl;
    cout << "r to run" << endl;
    cout << "q to quit program" << endl;
    cout << endl;
    cout << "Enter a command: ";

    cin >> command;
    command = tolower(command);

    switch (command)
    {
      case 'm':
      {
        do_move_command(m);
        break;
      }
      case 'w':
      {
        do_work_command(m);
        break;
      }
      case 'd':
      {
        do_deposit_command(m);
        break;
      }
      case 's':
      {
        do_stop_command(m);
        break;
      }
      case 'l':
      {
        do_lock_command(m);
        break;
      }
      case 'g':
      {
        do_go_command(m);
        break;
      }
      case 'r':
      {
        do_run_command(m);
        break;
      }
      case 'q':
      {
        do_quit_command(m);
        break;
      }
      default: // Executes for invalid command codes
      {
        cout << "ERROR: Please enter a valid command!" << endl;
        valid = false; // invalid flag
        break;
      }
    }
    if (valid)
    {
      m.display(v); // only displays if command was valid; displays after every command is executed
    }
  }

  return 0;
}
