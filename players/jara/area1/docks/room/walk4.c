/* Boardwalk, Created <5/8/00> by Jara */

#include "defs.h"
inherit "room/room";

int peeps;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="The boardwalk";
  long_desc=
    "  The western end of the boardwalk comes to an abrupt end, blocked by\n"+
    "sand dunes and rock formations. A pier extends south from the board-\n"+
    "walk, held up by massive, wooden pilings, and a small boat is docked.\n"+
    "The high grasses to the north border the edge, and the boardwalk leads\n"+
    "to the east.\n";
  items=({
     "pier",
     "A wooden pier, built of wooden planks and posts",
    "grasses",
    "The thick grass is several feet high",
    "boardwalk",
    "The boardwalk is made of wooden planks and is approximately twelve feet wide",
    "formations",
    "The rock formations are covered with moisture and a thick, green moss",
    "dunes",
    "The sand dunes vary in size, and extend far to the east",
    "pilings",
    "The thick, wooden posts hold the pier level, up off the waters",
    "boat",
    "A small, wooden craft with a small mast and a sail" });
  dest_dir=({
    PATH+"walk3","east",
    PATH+"dock3","south" });
}

void init() {
  ::init();

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

  switch(random(3)) {
    case 0: msg="The waves crash gently against the beach.\n"; break;
    case 1: msg="A seagull flies by overhead.\n"; break;
    case 2: msg="The chill breeze nips against your ears. \n"; break;
    case 3: msg="The grass sways in the breeze.\n"; break;
  }
  tell_room(this_object(),msg);
  call_out("emotes",5+random(10));
}
