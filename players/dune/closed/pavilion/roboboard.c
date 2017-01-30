#include "/players/dune/closed/pavilion/DEFS.h"
inherit "/players/dune/closed/pavilion/board";
#define BOARD_NAME "players/dune/closed/pavilion/roboboard"


init() {
    add_action("new",    "note");
    add_action("read",   "read");
    add_action("remove", "remove");
    add_action("new",    "input");
    add_action("read",   "output");
    add_action("remove", "erase");
}

void description() {
  write("This is the RoboMech Pilot Board, please feel free\n"+
        "to input any RoboMech related information here.\n"+
        "Usage:   'input  headline'\n"+
        "         'output messageNumber'\n"+
        "         'erase  messageNumber'\n");
}

string short() {
  return ("The RoboMech Pilot Board(" + num_messages + " msgs)");
}

void restore_me() { restore_object(BOARD_NAME); }
void save_me()    { save_object(BOARD_NAME);    }
