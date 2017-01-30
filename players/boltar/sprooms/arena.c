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
  write("You have entered the village arena. It is both small and simple.\n"+
   "The arena consists of a small 'stage' area that the trail leads to\n"+
   "with a horseshoe shaped hill around it. On the hill stones are placed\n"+
   "in neat rows for spectators to sit and watch what occurs here.\n"+
   "This is known as the place where people come to fight one another.\n"+
   "There is no need to be defined as a player killer here, it is a place\n"+
   "where anyone can fight anyone else. There are no defined rules here,\n"+
   "so beware. Even a spectator could end up in the frey.\n");
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
exit(ob) { if(ob && ob->is_player()) ob->clear_fight_area(); }
realm() {return "NT"; }
