#include "/players/dusan/ansi.h"
inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("pieces"); 
set_alias("bones");
set_short(""+BOLD+""+YEL+"Bone pieces"+NORM+"");
set_long(
  "A skeletons rib cage and a few other pieces.\n"+
  "It looks like you could 'rearrange' them. \n");
set_weight(2);
set_value(400); 
}

init() {
  ::init();
  add_action("rearrange","rearrange"); }
rearrange(str){
  if(environment() != this_player()) return;
  if(!str){ write("rearrange what?\n"); return 1; }
  if(str != "pieces"){ write("rearrange what?\n"); return 1;} 
  move_object(clone_object("/players/dusan/area1/armors/bplate.c"), this_player()); 
  write("You rearrange the bones into some armor.\n"); 
  destruct(this_object());
  return 1; }
 