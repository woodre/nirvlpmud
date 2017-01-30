#include "/players/dusan/ansi.h"
inherit "obj/treasure";

reset(arg) {
  if(arg) return;  
set_id("Amy"); 
set_alias("Amy");
set_short("A little girl");
set_long(
  "A little girl in a torn and soiled yellow sundress.\n"+
  "It looks like she has been in the swamp for awhile. \n"+
  "Maybe you should 'reunite' her to her parents. \n");
set_weight(4);
set_value(0); 
}
/* I took out the part of the code I wasnt sure of could you tell me */
/* what I need to do to fix this so she in only able to be used in the */
/* room with the parents? */
object parents;
parents = ("/players/dusan/area1/mobs/parents.c");
init() {
  ::init();
  add_action("reunite","reunite"); }
reunite(str) {
  if(environment() != this_player()) return;
  environment(environment());
  if(parents != present){ write("They are not here!\n"); return 1; }
  if(!str){ write("reunite what?\n"); return 1; }
  if(str != "amy"){ write("reunite what?\n"); return 1; }  
  this player()->add_xp(250); */
  write("Amy jumps out of your hands and rushes into the arms of her parents.\n"); 
  destruct(this_object());
  return 1; 
} 