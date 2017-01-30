#include "room.h"

object rambo,ob;

#undef EXTRA_RESET
#define EXTRA_RESET\
              extra_reset();

    extra_reset() {
/*
  if(!rambo || (present("rambo"))) {
    rambo = clone_object("players/hawkeye/monster/rambo.c");
      transfer(rambo, this_object());

   ~/monster/rambo.c has been taken out for some reason... no clue where it went
    so i have taken this part of the code out
   so players climbing into this room dont get error msgs
}
    - mythos <3-19-97> */
    }
ONE_EXIT("players/hawkeye/room/j-ent.c", "down",
        "Rambo",
  "You stand before a man who is built like a truck and is half as big.\n" +
   "He looks at you with sweat running down his forehead and muscles bulging.\n" +
  "It looks like your in for a fight.\n",1)
