#include "std.h"
 int shield, notin;
init() {
add_action("remove_ghost","mpray");
  add_action("east","east");
  set_light( 1);
  this_player()->set_fight_area();
 }
 short() {
	   return "The Monk Arena";
  }
 long() {
  write("You have entered the Monk arena. This is the place where Monks"+
  "\n"+
"can come to fight amongst themselves and not lose any xp's\n" +
"The only draw back to this room, is that when you die, you will\n" +

"still lose a stat. But that is the price you pay.\n" +
"This room is the only one where it is legal for Monks to\n" +
"attack first and whenver you feel like it, but you wont lose any xps.\n"+
"Once you are dead, type mpray to get your xps and life back\n" +
"Have Fun!\n");
   write("The only exit is to the east.\n");
  }

remove_ghost() {
if(this_player()->query_ghost() > 0) {
int xp,newxp;
 xp = this_player()->query_exp();
newxp = xp*4;
newxp = newxp/3;
newxp = newxp - xp;
call_other(this_player(),"add_exp",newxp);
return call_other(this_player(), "remove_ghost",0);
return 1;
}

}
east() {
  string oppn;
  object opp;
    if(this_player()->query_attack()){
     opp=this_player()->query_attack();
    oppn = opp->query_name();
    this_player()->set_title("ran from a fight with "+oppn);
    }
  call_other(this_player(), "move_player", "east#players/hawkeye/closed/guild/advance.c");
  this_player()->clear_fight_area();
  return 1;
  }
realm() {return "NT"; }
