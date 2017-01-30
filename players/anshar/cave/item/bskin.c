
#include "/players/anshar/closed/mydef.h"
inherit "/obj/treasure";

int Z;

short() { return "A huge bearskin"; }

long() { write("     This large, shaggy pelt appears to be worth quite a bit.  \n"+
	       "Perhaps someone might be willing to purchase it from you. Just \n"+
	       "offer it to the right person. \n"); }

id(str) { return str == "skin"; }

init() {
   ::init();
   add_action("sell_skin","offer");
}


sell_skin() {
  if(!present("dmerchant",ENV(TP))) {
  write("There is noone here to offer that to.\n");
  return 1; }
  write("The merchant pays you for the bear skin.\n");
  TP->add_money(random(1000)+4000);
  destruct(this_object());
  return 1; }
