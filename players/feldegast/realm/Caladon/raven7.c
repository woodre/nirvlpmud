/*
File: raven7.c
Author: Feldegast
Date: 10/20/01
Description:
  Pit beneath the Tower of Ravens.
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(!present("pit monster"))
    move_object(clone_object(MON_PATH+"pitmon.c"), this_object());
  if(arg) return;
  short_desc=BOLD+BLK+"Tower of Ravens"+NORM;
  long_desc=
"  This deep, disgusting pit is filled with slime and smells vile.\n\
A set of manacles are chained to the stone wall.  A flight of stairs\n\
lead up to a metal grate.\n";
  items=({
    "pit", "reflexive",
    "slime", "A thick coating of green slime covers everything",
    "manacles", "A pair of manacles (empty) are chained to the wall",
    "stairs", "A flight of ten granite stairs follow the wall up to\n"+
              "a metal grate",
    "grate", "A metal grate leads back to the fresh air",
  });
  dest_dir=({
    PATH+"raven1.c", "up",
  });
}

void init() {
  ::init();
  add_action("cmd_up", "up");
  add_action("cmd_alt", "open");
}

int cmd_up(string str)
{
  if(present("pit monster"))
  {
    write("The pit monster prevents you from leaving.\n");
    say(TPN+" tries to leave but is blocked by the pit monster.\n");
    return 1;
  }
  else return (int)::cmd_move(str);
}

int cmd_alt(string str)
{
  if(str == "grate")
    command("up", TP);
}
