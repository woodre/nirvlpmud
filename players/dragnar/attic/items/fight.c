#include "std.h"
int x,y;
reset(arg){
	if(arg) return;
	if(!arg) x = 0;
y = 0;
}
init() {
	call_out("corpsecheck",2);
	add_action("NOT"); add_xverb("");
   set_light( 1);
   this_player()->set_fight_area();
}
short() {
   return "The Champions Arena";
}
long() {
   write("You are in the Champions arena.  This means you must fight well or\n"+
      "die.  You are strong however, having a blood scar is a sign of greatness.\n"+
      "May you fight well and increase your knowledge of battle.\n");
	write("The only obvious exit is out.\n");
}
corpsecheck() {
NOT(str) {
	if(str == "pray") {
	if(!this_player()->query_ghost() > 0){
	write("You pray to your God for victory to be yours.\n");
	return 1;
	}
   if(this_player()->query_ghost() > 0) {
      int xp,newxp;
	x = x + 1;
      xp = this_player()->query_exp();
      newxp = xp*4;
      newxp = newxp/3;
      newxp = newxp - xp;
      call_other(this_player(),"add_exp",newxp);
      return call_other(this_player(), "remove_ghost",0);
      return 1;
   	}
	}
	if(str == "out") {
	if(x < 1){
	write("Someone must be taken of their life, then given it back before you can leave.\n");
	return 1;
	}
	if(y > 1){
	x = 0;
	}
	y = y + 1;
	call_other(this_player(),"move_player","out#/players/dragnar/rooms/healshop.c");
	this_player()->clear_fight_area();
	return 1;
	}
	else {
	write("You may not do that here.\n");
	return 1;
	}
}
realm() { return "NT"; }
