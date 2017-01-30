#include "std.h"

object stump;

#undef EXTRA_INIT
#define EXTRA_INIT \
     add_action("south", "south");

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     if(!stump) {
          stump=clone_object("players/bastion/obj/static");
          stump->set_name("tree stump");
          stump->set_alias("stump");
          stump->set_short("tree stump");
          stump->set_long(
               "It must have been quite a tree judging by its size.\n");
          stump->set_object(this_object());
          stump->set_summon("summon_brownie");
          move_object(stump, this_object());
          stump->start_check(); }
     stump->load_summon();
}

summon_brownie(arg) {
     object ob;
     if(present("brownie")) {
          stump->unload_summon();
          return 1; }
     ob=clone_object("obj/monster");
     ob->set_name("brownie");
     ob->set_alias("brownie");
     ob->set_short("a brownie");
     ob->set_long("It is a mischievious-looking creature.\n");
     ob->set_level(5);
     ob->set_hp(75);
     ob->set_wc(9);
     ob->set_ac(5);
     ob->add_money(250);
     ob->set_heart_beat(1);
     say("A brownie jumps from behind a tree and says, 'Boo!'\n");
     say("Brownie giggles inanely.\n");
     move_object(ob, this_object());
     stump->unload_summon();
}

south() {
     write("You make your way back to the road...\n");
     return 0;
}

ONE_EXIT("players/bastion/antaria/belgaers/road4", "south",
     "Clearing",
     "You come upon a small clearing in the woods, the trees rising high\n"+
     "around you. Some mushrooms grow aound a large tree stump in the\n"+
     "center of the glade.\n",
     1)
