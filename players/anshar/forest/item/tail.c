
#include "/players/anshar/closed/mydef.h"
inherit "/obj/treasure";

int Z;

short() { return "A delit tail"; }

long() { write("     The thin tail of a delit, reputed to have some \n"+
	       "healing properties when processed properly. Perhaps \n"+
	       "someone with the knowledge of the process would be  \n"+
	       "willing to purchase this from you. Just offer it to \n"+
               "the right person. \n"); }

id(str) { return str == "tail"; }

init() {
   ::init();
   add_action("sell_tail","offer");
}

set_amount(str) {
  if(!str) { 
    Z = 0; 
    return 0; }
    Z = str;
    return 1;
  }

sell_tail() {
  if(!present("dmerchant",ENV(TP))) {
  write("There is noone here to offer that to.\n");
  return 1; }
  write("The merchant pays you for the tail.\n");
  TP->add_money(random(200)+(Z*75));
  destruct(this_object());
  return 1; }
