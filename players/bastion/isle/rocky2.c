/* 10/14/05 Earwax: Converted this to palace land for Upus. */

inherit "/players/earwax/housing/land.c";

#include <std.h>

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset(arg) {
   object ob;
   if (!present("small scroll")) {
      ob = clone_object("obj/treasure");
      ob->set_id("small scroll");
      ob->set_alias("scroll");
      ob->set_short("a small scroll");
      ob->set_long("It has some writing on it.\n");

      ob->set_read("   /-\\---------------------------\\ \n"+ 
                   "  (   )                           )\n"+
                   "   \\_/___________________________/ \n"+
                   "    |                           | \n"+
                   "    | Dear Adventurer,          | \n"+
                   "    |                           | \n"+
                   "    | I hope you enjoy your     | \n"+
                   "    | visit to my islands. If   | \n"+
                   "    | you are a mere beginner,  | \n"+
                   "    | than perhaps you might try| \n"+
                   "    | killing some seagulls.    | \n"+
                   "    |                           | \n"+
                   "    | Take care should you      | \n"+
                   "    | venture into one of the   | \n"+
                   "    | caves though. It has been | \n"+
                   "    | rumored that a terrible   | \n"+
                   "    | beast has mades it's lair | \n"+
                   "    | deep within one!          | \n"+
                   "    |                           | \n"+
                   "    | Enjoy!                    | \n"+
                   "    | Bastion the Archmage      | \n"+
                   "   /-\\---------------------------\\ \n"+
                   "  (   )                           )\n"+
                   "   \\_/___________________________/ \n" );
      move_object(ob, this_object());
   }
  set_realm_name("Rocky Shore");
  set_lot_size(-2);
  set_cost(1000000);
  setup_land();
}



FOUR_EXIT("players/bastion/isle/grass4", "north",
          "players/bastion/isle/rocky3", "east",
          "players/bastion/isle/nearshore", "south",
          "players/bastion/isle/rocky1", "west",
          "Rocky shore",
          "You stand on the rocky shore of a small island.\n" +
          "You hear the pounding of the surf and the occasional cry of sea\n" +
          "gulls over the rushing wind. The shore continues to the east and\n" +
          "west, while tall grass rises up to the north. South is the sea.\n",
          1)
