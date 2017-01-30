
#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     object ob;
     if(!present("woman")) {
          ob=clone_object("obj/monster");
          ob->set_name("woman");
          ob->set_alias("dwarf");
          ob->set_short("a dwarf woman");
          ob->set_long(
             "It is true. Dwarf woman DO have beards.\n");
          ob->set_level(10);
          ob->set_al(400);
          ob->set_hp(150);
          ob->set_wc(14);
          ob->set_ac(8);
          ob->set_chat_chance(30);
          ob->load_chat("The dwarf woman sings merrily to herself.\n");
          ob->load_chat("The woman begins chopping some vegetables.\n");
          ob->load_chat("Dwarf says: that man will ruin my husband...\n");
          ob->set_a_chat_chance(20);
          ob->load_a_chat("Dwarf screams: Someone help me!!\n");
          ob->load_a_chat("Dwarf pleads: Please stop! You're hurting me!\n");
          ob->add_money(500);
          move_object(ob, this_object()); }
}


ONE_EXIT("players/bastion/isle/wiz/shack", "out",
     "Little Shack",
     "You enter a small shack, apparently a home. A bed, large enough\n"+
     "for two, sits in one corner of the room. A cast-iron stove is\n"+
     "also here, providing protection against the chill. You notice\n"+
     "some greens left on a table in preparation for a meal.\n",
     1)
