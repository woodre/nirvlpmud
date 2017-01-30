inherit "room/room";
#include "/players/snow/closed/color.h"
 
int guards;

reset(arg){
 
 if(!arg){
 
 set_light(1);
short_desc=GREEN+"Hall of the Troglodyte King"+OFF;
long_desc=GREEN+
"\tYou are in a large, drab hall.\n"+
"Bits and pieces of seaweed lie scattered about. The crude stone walls\n"+
"are slimy and green. To the north lies an arched doorway while to the\n"+
"south there is an opening that leads out to the surf.\n"+
OFF;
 
items=({
  "seaweed","Green, slimy seaweed...",
  "walls","The walls are hewn from solid rock and are covered with slime",
  "slime","The slime appears to be some sort of sea-scum",
  "doorway","The doorway appears to open up into a larger room",
  "opening","An opening out to the surf of a beach",
  "surf","The surf of a beach"
});
 
  dest_dir=({
  "/players/snow/water/throne_room","north",
  "/players/snow/beach/surf1","out"
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
