#define TRES "/players/snow/random/treasure.c"
inherit "room/room";
#include "/players/snow/closed/color.h"
 
int guards, tres, cash;

reset(arg){

 if(!arg){
 
 set_light(1);
short_desc=GREEN+"Hall of the Troglodyte King"+OFF;
long_desc=GREEN+
"\tYou are in a storage room of sorts.\n"+
"Seaweed pieces and slime cover the floor and walls.\n"+
"There is an arched doorway to the west.\n"+
OFF;
 
items=({
  "seaweed","Seaweed, pieces of it, slimy, slimy, slimy",
  "slime","Organic sea-scum",
  "walls","Slimy green walls of crudely-hewn stone"
});
 
  dest_dir=({
  "/players/snow/water/throne_room","west"
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
  object mon, money;
  mon = present("troglodyte");
  if(mon) {
    mon->attack_object(this_player()); return 1; }
  if(random(2)) {
  write("You search the room but find nothing of value.\n");
  say (this_player()->query_name() +" searches the room in vain.\n");
  return 1;  }
  if(random(4) && tres < 5) {
    write("You find some treasure!\n");
    call_other(TRES, "random_item");
    tres++; return 1; }
  if(random(4) && cash < 3) {
  write("You find some coins!\n");
  money = clone_object("/obj/money");
  move_object(money, this_object());
  money->set_money(random(3000)+3000);
  cash++; return 1; }
  write("You search the room but find nothing of value.\n");
  say (this_player()->query_name() +"searches the room in vain.\n");
  return 1;  }

realm() { return "NT"; }
