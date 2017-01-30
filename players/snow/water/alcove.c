inherit "room/room";
#include "/players/snow/closed/color.h"
 
int guards;

reset(arg){
 
 if(!arg){
 
 set_light(1);
short_desc=GREEN+"Hall of the Troglodyte King"+OFF;
long_desc=GREEN+
"\tYou find yourself in a small alcove.\n"+
"Bits and pieces of seaweed are scattered on the slimy floor.\n"+
"To the south an arched doorway leads into a larger space.\n"+
"There is a glowing green portal on the northern wall.\n"+
OFF;
 
items=({
  "seaweed","The seaweed appears to be slimy seaweed",
  "doorway","Beyond the doorway lies an opulent room",
  "portal","A mysterious green portal"
});
 
  dest_dir=({
  "/players/snow/water/throne_room","south",
  "/players/snow/chaos/r6","portal"
});
  }   }
 
 
init()  {
 ::init();
  if(this_player()->is_player()) check_guard();
  add_action("smell_room","smell"); 
  add_action("search_room","search");
}
 
check_guard() {
  object mon;
  mon = clone_object("/players/snow/water/mon/guard");
  if(!present("troglodyte 2") && guards < 5) {
  tell_room(this_object(),"\n\tA Troglodyte Guard attacks!\n");
  move_object(mon, this_object());
  mon->attack_object(this_player());
  guards++; }
  return 1; }

smell_room() {
  write("You smell an oily, fishy odor and gag in disgust.\n");
  say (this_player()->query_name() +"sniffs the air and gags in disgust.\n");
  return 1;  }
 
search_room() {
  write("You search the room but find nothing of value.\n");
  say (this_player()->query_name() +"searches the room in vain.\n");
  return 1;  }
realm() { return "NT"; }
