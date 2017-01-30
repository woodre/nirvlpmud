/*
File: raven3.c
Author: Feldegast
Date: 2/25/01
Description:
  Third floor of the tower of ravens in Caladon.
*/
#include "defs.h"

inherit ROOM;

void reset(int arg) {
  object door;
  if(arg) return;
  set_light(1);
  short_desc=BOLD+BLK+"Tower of Ravens"+NORM;
  long_desc=
"  A landing breaks the monotony between the flights of endless\n\
stairs.  A plush velvet carpet covers the floor.  In the middle of\n\
the landing is a marble statue.  A steel-bound door leads west.\n";
  items=({
    "landing", "reflexive",
    "flights", "You fancy them",
    "stairs", "The marble staircase spirals up and down into the darkness",
    "marble", "The marble is black, with streaks of violet",
    "carpet", "It is a plush red velvet carpet",
    "statue", "The statue is constructed out of white marble and easily stands eight feet\n"+
              "tall.  The statue is of an anatomically correct male.  He possesses strong,\n"+
              "but kind features.  He is handsome, in a rugged way, but not vain.  You\n"+
              "notice that he possesses some elven features but doesn't appear to be a pure\n"+
              "breed elf",
  });
  dest_dir=({
    PATH+"raven6.c", "up",
    PATH+"raven2.c", "down",
    PATH+"raven5.c", "west",
  });
  door=clone_object(DOOR);
  door->add_id("door");
  door->add_id("steel-bound door");
  door->set_open_desc("It is a steel-bound door made out of oak.\n");
  door->set_close_desc("It is a steel-bound door made out of oak.\n");
  door->set_destination(PATH+"raven5.c");
  door->set_exit("west");
  door->set_open(0);
  door->set_locked(0);
  door->set_key("clarisse_door");
  door->set_trapped(1);
  door->set_trap_dmg(20);
  door->set_trap_msg("A needle pops out of the door's lock and jabs you in the hand.\n");
  door->set_partner("door", PATH+"raven5.c");
  move_object(door,this_object());
}

