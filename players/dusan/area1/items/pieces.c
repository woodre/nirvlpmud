#include "/players/dusan/ansi.h"
inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("pieces"); 
set_alias("bones");
set_short(""+BOLD+""+YEL+"Bone pieces"+NORM+"");
set_long(
  "A skeletons rib cage and a few other pieces.\n"+
  "It looks like you could 'rearrange' them into\n"+
  "these armor types: gloves, helmet, shield, armor\n"+
  "boots, or amulet.\n" );
set_weight(1);
set_value(400); 
}

init() {
  ::init();
  add_action("rearrange","rearrange"); }
rearrange(str){
  if(environment() != this_player()) return;
  if(str == "gloves"){ move_object(clone_object("/players/dusan/area1/armors/bring.c"), this_player()); 
  write("You rearrange the bones into a pair of gauntlets.\n"); 
  destruct(this_object());
  return 1; }
  if(str == "helmet"){ move_object(clone_object("/players/dusan/area1/armors/bhelm.c"),this_player()); 
  write("You hollow out a skull and shape it into a helmet.\n"); 
  destruct(this_object());
  return 1; } 
  if(str == "shield"){ move_object(clone_object("/players/dusan/area1/armors/bshield.c"), this_player());
  write("You rearrange the bones into a shield.\n"); 
  destruct(this_object());
  return 1; }
  if(str == "armor"){
  if(!present("pieces 3",this_player())) {
  write("You need more pieces!!\n"); return 1; }
  move_object(clone_object("/players/dusan/area1/armors/bplate.c"), this_player());
  destruct(present("bones 2",this_player()));
  destruct(present("bones 2",this_player()));
  write("You rearrange the bones into some armor.\n"); 
  destruct(this_object());
  return 1; }
  if(str == "boots"){ move_object(clone_object("/players/dusan/area1/armors/bboots.c"), this_player()); 
  write("You rearrange the bones into some boots.\n"); 
  destruct(this_object());
  return 1; }
  if(str == "amulet"){ move_object(clone_object("/players/dusan/area1/armors/bnecklace.c"), this_player()); 
  write("You rearrange the bones into a necklace.\n"); 
  destruct(this_object());
  return 1; }
  }