#include "/players/dusan/ansi.h"
inherit "obj/treasure";

object parents;

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

init() {
  ::init();
  add_action("reunite","reunite"); }
reunite(str) {
  if(environment() != this_player()) return; 
  if(!str){ write("reunite what?\n"); return 1; }
  if(str != "amy"){ write("reunite what?\n"); return 1; }  
  if(present("parents_obj", environment(this_player()))){
  this_player()->add_exp(250);
  write("Amy jumps out of your hands and rushes into the arms of her parents.\n"); 
  destruct(this_object());
  this_player()->recalc_carry();  
  return 1; 
} 
write("They are not here!!\n"); return 1;
}
