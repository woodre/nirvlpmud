
#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {
     object shell;
     int i, i2;
     i=0; i2=random(2)+1;
     if(!present("seashell")) {
          while(i<i2) {
               i+=1;
               shell=clone_object("obj/treasure");
               shell->set_name("shell");
               shell->set_short("a seashell");
               shell->set_value(100);
               shell->set_weight(1);
               move_object(shell, this_object()); }
     }
}
THREE_EXIT("players/bastion/isle/sandy1", "northeast",
     "players/bastion/isle/grass1", "east",
     "players/bastion/isle/rocky1", "southeast",
     "Sandy Beach",
     "The rocks thin out into sand here, sea shells lining the shore. The\n"+
     "beach grows rocky to the southeast and continues to the northeast.\n"+
     "Tall grass rises to the east.\n",
     1)
