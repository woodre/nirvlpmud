#include "/players/dusan/ansi.h"
inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("skull"); 
set_alias("skull");
set_short(""+BOLD+""+YEL+"A skull"+NORM+"");
set_long(
  "A large bleached humans skull.  It looks like\n"+
  "you could 'hollow' it. \n");
set_weight(2);
set_value(400); 
}

init() {
  ::init();
  add_action("hollow","hollow"); }
hollow(str){
  if(environment() != this_player()) return;
  if(!str){ write("hollow what?\n"); return 1; }
  if(str != "skull"){ write("hollow what?\n"); return 1;} 
  move_object(clone_object("/players/dusan/area1/armors/bhelm.c"), this_player()); 
  write("You hollow out the skull.\n"); 
  destruct(this_object());
  return 1; }
 