#include "/players/mythos/closed/guild/def.h"
inherit "room/room";

reset(arg) {
if(!arg) {
  set_light(0);
    short_desc = BOLD+"THE DEMON KEEPER"+NORM;
    long_desc =
    "\nYou stand within the DEMON KEEPER!\n\n"+
    "All is dark here.  All is silent.\n"+
    "All that you feel is anger and evil.\n";
} }
realm() {return "NT"; }
init() {
  ::init();
  if(tp->query_npc()) { destruct(tp); return 1;}
  if(!present(fear,tp)) { tp->move_player("into the void#room/void.c");
                          tp->heal_self(-(tp->query_hp())/3);
                          return 1;}
  if(present(fear,this_player())) {
   present(fear,this_player())->set_defence(0);
   if(!present("task7",tp)) { 
     move_object(clone_object("/players/mythos/closed/guild/task/7/task7.c"),tp);} 
  }
  add_action("ssay","gossip");
  add_action("ssay","risque");
  add_action("ssay","babble"); 
  add_action("ssay","junk");
}

ssay() { write("What?\n"); return 1;}

