#include "std.h"
 int shield, notin;
init() {
	add_action("north"); add_verb("north");
	add_action("south"); add_verb("south");
  set_light( 1);
  this_player()->set_fight_area();
 }
 short() {
	   return "The wastelands";
  }
 long() {
	write("The land here is ruined.  There doesn't seem to be anyone\n" +
"around that you can see.  The ground feels like glass, although in\n" +
"some places it looks as if life has started to form again.  Ahead\n" +
"of you is the grave of a forest of long ago.\n");
	write("	The only obvious exits are north and south.\n");
  }
north() {
  string oppn;
  object opp;
    if(this_player()->query_attack()){
     opp=this_player()->query_attack();
    oppn = opp->query_name();
    this_player()->set_title("ran from a fight with "+oppn);
    }
  call_other(this_player(), "move_player", "north#/players/dragnar/rooms/room2.c");
  return 1;
  }
south() {
	call_other(this_player(), "move_player","south#/players/dragnar/rooms/entrance.c");
	this_player()->clear_fight_area();
	return 1;
}
