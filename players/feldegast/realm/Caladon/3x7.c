/*
File: 3x7.c
Creator: Feldegast @ nirvana.mudservices.com
Date: 2/1/01
Description:
  Barony of Caladon, the graveyard
*/
#include "defs.h"

inherit ROOM;

int seal;

void reset(int arg) {
  ::reset(arg);
  seal=1;
  if(arg) return;
  x=3; y=7;
  set_light(1);
  short_desc="Graveyard";
  long_desc=
"  The surrounding hills are dotted with granite tombstones.  A cast\n\
iron fence encloses the graveyard.  An ancient crypt sits atop the\n\
hill at the center of the graveyard.\n";
  items=({
    "hills", "The surrounding hills are dotted with granite tombstones",
    "tombstones", "The tombstones are covered with various names, dates, and epithets",
    "fence", "The cast iron fence encloses the graveyard on all sides",
    "graveyard", "reflexive",
    "crypt", "The crypt has been sealed by an ancient glyph imprinted upon wax",
  });
  dest_dir=({
    PATH+"4x7.c","east",
    PATH+"crypt.c", "enter",
  });
}

void init() {
  ::init();
  add_action("cmd_break", "break");
  add_action("cmd_enter", "enter");
}

int cmd_break(string str) {
  if(str!="seal" && str!="sigil" && str!="glyph" && str!="wax") {
    notify_fail("Break what?\n");
    return 0;
  }
  if(!seal) {
    write("The seal has already been broken.\n");
    return 1;
  }
  write("You break the seal placed upon the crypt.\n");
  say(TPN+" breaks the seal.\n");
  seal=0;
  return 1;
}


int cmd_enter(string str) {
  if(str!="crypt") {
    write("Enter what?\n");
    return 1;
  }
  if(seal) {
    write("The crypt has been sealed.\n");
    return 1;
  }
  return (int)::cmd_move(str);
}
  