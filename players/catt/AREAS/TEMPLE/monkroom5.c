#include "room.h"
#include "/players/catt/AREAS/base_defines.c"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
extra_reset() {
  object slayercaptain, slayer;
  int i;
  i = 0;
   if(!present("slayer")) {
    while(i < 2) {
      i += 1;
      slayer = clone_object(NPC+"TEM_slayer");
      move_object(slayer, this_object());
     }}
   if(!present("captain")) {
      slayercaptain = clone_object(NPC+"TEM_slayer_captain");
      move_object(slayercaptain, this_object());
}}
ONE_EXIT(TEMPLE+"monkroom4","up",
      "Demon Lord Brakian's Temple Office",
      "This room has been converted into an office. You see\n"+
      "a large oak desk stacked with papers and maps. The \n"+
      "walls are adorned with murals of a large demon in \n"+
      "various states of activity, from maiming a human with \n"+
      "its claws, to another one where the demon is sitting on\n"+
      "a pile of human bodies.\n",1)
