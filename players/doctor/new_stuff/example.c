
#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     object dragon, sword;
     if(!present("dragon")) {
          dragon=clone_object("obj/monster");
          dragon->set_name("sea dragon");
          dragon->set_race("dragon");
          dragon->set_short("a sea dragon");
          dragon->set_long
           ("This dragon is smaller than its inland cousins. Still it is\n"+
            "larger than most elephants. Its scales are grey and deep blue.\n"+
            "It stares at you balefully.\n");
          dragon->set_level(18);
          dragon->set_hp(random(100) + 375);
          dragon->set_ep(1000000);
          dragon->set_ac(8);
          dragon->set_wc(18);
          dragon->set_al(-600);
          dragon->set_aggressive(1);
          dragon->set_chance(30);
          dragon->set_spell_mess1
            ("The dragon belches forth a geyser of steam.");
          dragon->set_spell_mess2
            ("The dragon scalds you in a shower of steam!");
          dragon->set_spell_dam(random(20));
          sword=clone_object("obj/weapon");
          sword->set_name("longsword");
          sword->set_alt_name("sword");
          sword->set_short("a mithril longsword");
          sword->set_long
            ("It is a well-weighted and keenly forged brand.\n");
          sword->set_value(5000);
          sword->set_weight(2);
          sword->set_class(18);
          transfer(sword, dragon);
          move_object(dragon, this_object()); }
}

ONE_EXIT("players/bastion/isle/cave2", "west",
         "Cave",
         "You have entered a small cave littered with debris, among which\n"+
         "you count the bones of several former adventurers. You get an\n"+
         "uneasy feeling. You appear to have entered somethings lair.\n",
         0)
