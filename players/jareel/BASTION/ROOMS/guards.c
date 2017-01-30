
#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     if(!present("guard 5")) {
          object guard, sword;
          int i;
          i=0;
          while(i<5) {
               i+=1;
               guard=clone_object("obj/monster");
               guard->set_name("guard");
               guard->set_info("skeleton guard");
               guard->set_alias("skeleton");
               guard->set_race("undead");
               guard->set_short("a skeleton guard");
               guard->set_long("Empty sockets stare back.\n");
               guard->set_level(12);
               guard->set_hp(180);
               guard->set_ep(100000);
               guard->set_agressive(0);
               guard->set_ac(10);
               guard->set_al(0);
               sword=clone_object("obj/weapon");
               sword->set_name("shortsword");
               sword->set_id("shortsword");
               sword->set_alt_name("sword");
               sword->set_short("a shortsword");
               sword->set_long("It is simple and deadly steel.\n");
               sword->set_class(14);
               sword->set_weight(3);
               sword->set_value(700);
               transfer(sword, guard);
               move_object(guard, this_object());
               guard->init_command("wield shortsword"); }
     }
}

TWO_EXIT("players/bastion/isle/wiz/e_hall1", "north",
     "players/bastion/isle/wiz/foyer", "west",
     "Guard Room",
     "You have entered a room devoid of furnishings. That is not to say\n"+
     "it is empty however...\n",
     1)
