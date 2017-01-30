#include "std.h"
 int shield, notin;
init() {
  add_action("southwest","southwest");
  set_light( 1);
  this_player()->set_fight_area();
 }
 short() {
	   return "The Village Arena";
  }
 long() {
  write("You have entered the village arena. This is the place where people"+
  "\n"+
  "come to fight one another. There is no need to be defined as a player\n"+
  "killer here, it is a place where anyone can fight anyone else. There\n"+
  "are no defined rules here, so beware.\n");
  write("The Arena consists of a fairly large, stone lined, pit with a dirt bottom.\n");
   write("The only exit is to the southwest.\n");
  }
southwest() {
  string oppn;
  object opp;
    if(this_player()->query_attack()){
     opp=this_player()->query_attack();
    oppn = opp->query_name();
    this_player()->set_title("ran from a fight with "+oppn);
    }
  call_other(this_player(), "move_player", "southwest#room/northroad2.c");
  this_player()->clear_fight_area();
  return 1;
  }
realm(str) { return str == "NM" || str =="ND"; }
