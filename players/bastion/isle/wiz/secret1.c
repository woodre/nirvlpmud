
#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     int date;
     object ob;
     if(!present("paper")) {
          ob=clone_object("obj/treasure");
          date=random(10) + random(10)*10 + random(10)*100 + random(10)*1000 + random(10)*10000 + random(10)*100000;
          ob->set_id("paper");
          ob->set_alias("slip");
          ob->set_short("a slip of paper");
          ob->set_long("Some numbers are written in an elegant hand.\n");
          ob->set_read(date + "\n");
          ob->set_value(5);
          ob->set_weight(1);
          move_object(ob, this_object()); }
     return 1;
}

TWO_EXIT("players/bastion/isle/wiz/bedroom", "east",
     "players/bastion/isle/wiz/guest1", "west",
     "Secret Passage",
     "You enter a dark, narrow passage. The cobwebs suggest this corridor\n"+
     "doesn't see much use.\n",
     1)
