#include "/players/dusan/ansi.h"
inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("metal"); 
set_alias("object");
set_short(""+BOLD+""+BLK+"Metal Object"+NORM+"");
set_long(
  "This oblong piece of gray metal defys identification.  It seems light and strong.\n"+
  "Maybe you should 'show' this to someone who could work it.\n" );
set_weight(4);
set_value(800); 
}

init() {
  ::init();
  add_action("show_smith","show"); }
show_smith(str){
  if(environment() != this_player()) return;
  if(!present("smith", environment(this_player()))) {
  write("There is noone here to show that too.\n"); return 1; }
  if(!present("pieces",this_player())) {
  write("The smith says: I will need something for the handle.\n"); return 1; }
  if(str == "smith" && present("smith", environment(this_player()))){
  move_object(clone_object("/players/dusan/town/weapons/hammer.c"), this_player());
  destruct(present("bones",this_player()));
  write("The smith takes the metal and picks out a large bone and forges a hammer.\n"); 
  destruct(this_object());
  return 1; }
}