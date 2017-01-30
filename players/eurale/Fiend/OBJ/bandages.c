/* Values changed due to upgrade in level of the monster
completed by Pestilence per Dragnar 8-9-2014 */
#define tpn this_player()->query_name()  /* player name  */
#define ETP environment(this_player())
#include "/players/eurale/closed/ansi.h"
int number;

id(str) { return str == "bandages" || str == "bandaging"
	|| str == "roll" || str == "dirty bandaging"; }
short() { return "A roll of dirty bandaging"; }
query_save_flag() { return 1; }
query_value() { return (number * 600); }
long() { write(
  "This roll of dirty bandaging can be used to 'bandage wounds'.  You\n"+
  "may also be able to 'barter' it for a decent price.\n");
  }
reset(arg) {
  if(arg) return;
  number = 6;
}

init() {
  add_action("bandage","bandage");
  add_action("Barter","barter");
}

bandage(str) {
if(!str) { write("Bandage what?\n"); return 1; }
if(str == "wounds") {
  write("You carefully unroll the filthy bandages and wrap them\n"+
	"around your wounds.  They stem the flow of blood and\n"+
	"you begin to feel a little better....\n\n");
  number = number - 1;
call_other(this_player(),"heal_self",30);
call_other(this_player(),"recalc_carry");
if(!number) { write(
  BOLD+"You wrap the last of the filthy bandages around your wounds."+
  NORM+"\n");
  destruct(this_object()); }
 return 1; }
}

Barter(str) {
int num;
if(!present("sedjak",ETP)) return 0;
if(str == "bandages" || str == "bandaging") {
  num = number * (1500 + random(1000));
  write("You sell the filthy bandages to Sedjak for the handsom\n"+
    "sum of "+num+" coins.\n");
  this_player()->add_money(num);
  destruct(this_object());
  return 1; }
}


get() { return 1; }

query_weight() {
  if(number > 2) return(number/2);
  return 1; }
