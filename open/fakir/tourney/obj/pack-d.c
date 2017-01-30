#include "defs.h"

inherit "/players/feldegast/tourney/Packs/pack.c";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object(ARMOR+"Tmisc.c"),this_object());
  move_object(clone_object(ARMOR+"Tring.c"),this_object());
  move_object(clone_object(ARMOR+"Tamulet.c"),this_object());
  move_object(clone_object(ARMOR+"Tboots.c"),this_object()); 
  move_object(clone_object(ARMOR+"Tarmor.c"),this_object());  
  move_object(clone_object(WEAPONS+"Tdagger.c"),this_object());
}