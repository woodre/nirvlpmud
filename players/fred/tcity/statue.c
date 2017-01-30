#include "/players/fred/ansi.h"
inherit "/obj/treasure.c";

reset (arg) {
	set_id("statue");
	set_short("A Large Statue");
	set_long(
      "  A large statue carved entirely out of a huge mass of granite.\n"+
      "It depicts a knight in full combat gear mounted on a powerful\n"+ 
      "looking steed. The knight's one arm is raised high above his\n"+
      "head pointing a large sword towards the heavens as if preparing\n"+
      "to charge into battle.\n");
}

query_weight() {
	return 50000;
      } 

