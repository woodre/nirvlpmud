/* Hall 3 (outside bedroom), Created <6/19/01> by Jara */

#include "/players/jara/misc/ansi.h"
#include "defs.h"
inherit "room/room";
int peeps;

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc="Zercher Castle- Hallway";
  long_desc=
    "  The upstairs hallway is dimly lit by two candelabras, each one with\n"+
    "six candles. The hot wax has dripped down to the base of the candles,\n"+
    "where it has cooled into a rounded pool in the silver basin of the\n"+
    "holders. The eerie shadows cast upon the stone walls seem to reach\n"+
    "out, but the outermost corners of the hallway remained untouched by\n"+
    "light. There is a doorway in the northern wall and the hallway leads\n"+
    "to the east and west.\n";
  items=({
    "candelabras",
    "The six foot tall candelabras are made of pure silver and hold six\n"+
    "white candles",
    "candles",
    "The white candles are flickering softly against the darkness. The\n"+
    "candles have been burning for some time",
    "wax", 
    "The hot wax has been dripping from the candle tip and slowly cooling\n"+
    "as it dripped to the base of the candle",
    "base",
    "The rounded base of the candle holders are filled with the cool wax",
    "holders",
    "The silver basin of the candle holders are rounded in shape and\n"+
    "collect the wax",
    "shadows",
    "The dark shadows seem to dance with the flickering light",    
    "walls",
    "The dark stone walls are cold to the touch and are well worn",
    "corners",
    "The darkness is just beyond the flickering candlelight",
    "doorway",
    "Each doorway is marked with the royal insignia and made of a dark,",
    "oak wood",
    "insigina",
    "A unicorn and lion facing each other in peace", });
  dest_dir=({
    PATH+"broom1","north",
    PATH+"hall2","east",
    PATH+"hall4","west" });
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

  switch(random(2)) {
    case 0: msg="The candle flickers softly...\n"; break;
    case 1: msg="A gentle breeze seems to pass through the hall...\n"; break;

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
}
