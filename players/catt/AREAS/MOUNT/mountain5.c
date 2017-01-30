#include "room.h"
#include "/players/catt/AREAS/base_defines.c"


#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {

}

THREE_EXIT(MOUNT+"mountain4","down",
           MOUNT+"mountain7","in",
           MOUNT+"mount_crest1","west",
  
           "entrance to goblin strong hold",
            "You are now at the entrance to the Goblin strong hold.\n" +
            "It is a dirty cluttered area with old junk everwhere. But\n" +
            "you can tell that this entrance could be easily defended.\n", 1)


