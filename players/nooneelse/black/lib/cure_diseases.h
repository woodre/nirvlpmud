/*
  cure_diseases.h
*/

#include "defs.h"

/* -------- Cure diseases in the vampire -------- */
cure_disease(str) {
  if (!str || str != "disease") return 0;
  if (MY_LEVEL < 7 || MY_GUILD_EXP < 670) {
    write("You can't use that abilitiy yet.\n");
    return 1; }

  if (MY_SPELL_POINTS < 30) {
    write("You don't have enough spell points.\n");
    return 1; }

  /* make 3 passes in case there's more than one of each */
  cure_diseases();
  cure_diseases();
  cure_diseases();
  MY_PLAYER->add_spell_point(- 50);
  write("Ok.");
  return 1;
}

cure_diseases() {
if(present("toxin",MY_PLAYER) || present("toxin3",MY_PLAYER)) {
  write(HIG+"You neutralize the deadly disir poison."+NORM+"\n");
  destruct(present("toxin",MY_PLAYER));
  destruct(present("toxin3",MY_PLAYER));
  return 1; }

if(present("crotchrot",MY_PLAYER)) {
  write(HIR+"You shiver VIOLENTLY as the blood-born pathogens "+
        "are neutralized."+NORM+"\n");
  destruct(present("crotchrot",MY_PLAYER));
  return 1; }

  if (present("flu", MY_PLAYER)) {
    destruct(present("flu", MY_PLAYER));
    tell_object(MY_PLAYER, "You've just cured yourself of the flu.\n");
  }
  if (present("headcold", MY_PLAYER)) {
    destruct(present("headcold", MY_PLAYER));
    tell_object(MY_PLAYER, "You've just cured yourself of the flu.\n");
  }
  if (present("cold", MY_PLAYER)) {
    destruct(present("cold", MY_PLAYER));
    tell_object(MY_PLAYER, "You've just cured yourself of a cold.\n");
  }
  if (present("mummy_rot", MY_PLAYER)) {
    destruct(present("mummy_rot", MY_PLAYER));
    tell_object(MY_PLAYER, "You've just cured yourself of the mummy rot.\n");
  }
  if (present("disease", MY_PLAYER)) {
    destruct(present("disease", MY_PLAYER));
    tell_object(MY_PLAYER, "You've just cured yourself of a disease.\n");
  }
}
