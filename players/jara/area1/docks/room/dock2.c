/* Pier 1, Created <5/8/00> by Jara */

#include "defs.h"
inherit "room/room";

int peeps;

reset(arg) {

object ob;

  if(arg) return;
  set_light(1);
  short_desc="An old pier";
  long_desc=
    "  The south end of the pier extends further into the water. A small,\n"+
    "folding chair and a worn, wooden tacklebox have been placed near the\n"+
    "edge of the pier. The waters beneath the pier are a bit clearer than\n"+
    "the shore, and small, silver fish are visible just beneath the gentle\n"+
    "waters.\n";
  items=({
    "shore",
    "The shore stretches for several miles in each direction, covered with high\n"+
    "sand dunes and rock formations",
    "waters",
    "The waters beneath the pier are a bit clearer here. Several pieces of seaweed\n"+
    "cling to the pilings that hold up the pier",
    "chair",
    "The small, metal chair is rusted at the hinges and holds a comfortable pad on\n"+
    "the seat",
    "tacklebox",
    "An old, rusted metal tacklebox, used to hold fishing tackle",
    "fish",
    "The small silver fish beneath the pier are numerous. They dart quickly between\n"+
    "the shadows" });
  dest_dir=({
    PATH+"dock1","north" });
  if(!present("fisherman")) {
    ob=clone_object("/players/jara/area1/docks/mon/fisher.c");
    move_object(ob,this_object());
  }
}

void init() {
  ::init();

  add_action("search","search");

  peeps++;
  if(find_call_out("emotes") == -1)
    call_out("emotes",15+random(15));
}

void exit() {
  peeps--;
  if(peeps <= 0)
    while(remove_call_out("emotes") != -1) ;
}

void emotes() {
  object ob,next;
  string msg;

  switch(random(4)) {
    case 0: msg="The waves crash gently against the beach.\n"; break;
    case 1: msg="A seagull flies by overhead.\n"; break;
    case 2: msg="A fish splashes in the water. \n"; break;
    case 3: msg="The pier moves slightly with the waves.\n"; break;

  }
  tell_room(this_object(),msg);
  while(remove_call_out("emotes") != -1); /* by verte 6.11.01 */
  call_out("emotes",20+random(15));
}

search(str) {
  if(!str) {
    write("You find nothing.\n");
  return 1;
 }
  if(str == "tacklebox") {
    write("Within the tacklebox, you find an assortment of hooks and live bait.\n");
  return 1;
  }
 }
