#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="Brigand Cave";
  items=({
    "crystal", "It glitters in a mesmerizing way",
    "string", "It looks just like string",
    "turntable","The turntable sits in the center of the tunnel and tilts\n"+
                "whenever you step on it",
  });
  dest_dir=({
    PATH+"rocks6.c","northeast",
    PATH+"rocks3.c","south",
  });
}

void long(string str) {
  if(str) { ::long(str); return; }
  if(!present("illusion countermeasures",TP))
    write(
      "  This cave appears surprisingly featureless, and yet strangely\n"+
      "disorienting.  Tunnels branch off from it at regular intervals\n"+
      "and in all directions.\n"+
      "    There are eight obvious exits: north, northwest, northeast, west, east, southwest, south and southeast\n"
    );
  else
    write(
      "  The tunnel widens slightly here, but continues both to the\n"+
      "north and to the south.  A piece of crystal is hung from a\n"+
      "piece of string and directly beneath it is a turntable.\n"+
      "    There are two obvious exits: northeast and south\n"
    );
}

void init() {
  ::init();
  add_action("cmd_lost","north");
  add_action("cmd_lost","northwest");
  add_action("cmd_lost","northeast");
  add_action("cmd_lost","west");
  add_action("cmd_lost","east");
  add_action("cmd_lost","southwest");
  add_action("cmd_lost","southeast");
}

int cmd_lost(string str) {
  if(present("illusion countermeasures",TP)) {
    if(query_verb() != "northeast") 
      return 0;
    TP->move_player("northeast#"+PATH+"rocks6");
    return 1;
  }
  command("look",TP);
  return 1;
}
