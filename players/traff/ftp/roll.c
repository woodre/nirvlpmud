/* Its a heal, uses stuff, heals for 15.  Player must find clues
   to get one free per reboot.  A few monsters have 1 each and must 
   be killed for the player to get the roll.
   Changes as of 5-29-96:
   Color added
*/
#include "/players/traff/closed/ansi.h"
inherit"obj/food";

reset(arg) {
  ::reset(arg);
  if(!arg) {
  set_name("roll");
  set_short(YEL+"A hot roll"+NORM);
  set_long(HIY+
"Fresh from the oven and golden brown on top, this hot\n"+
"dinner roll looks delicious.\n"+NORM);
  set_eater_mess("The warm bread tastes excellent!\nAhhhhhhh!\n");
  set_eating_mess(" crams down a hot roll!  It sure looked good.\n");
  set_strength(15);
  set_value(25);
}
}

is_heal() { return "stuff"; }

query_potence() { return 15; }
