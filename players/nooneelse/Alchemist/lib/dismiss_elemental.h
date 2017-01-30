/*
  dismiss_elemental.h.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Dismiss elemental ---------- */
dismiss_elemental(str) {
  string str2;

  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str) {
    write(NORM+CYN+"You must specify what you want to dismiss.\n"+NORM);
    return 1;
  }
  sscanf(str, "%s elemental", str2);
  if (str2 != "air" && str2 != "fire" && str2 != "earth") {
    write(NORM+CYN+"You must specify which elemental to dismiss.\n"+
          "use: dismiss <air/fire/earth> elemental\n"+
          "     NOTE: if you select 'earth', "+
          "all earth elementals will be dismissed.\n"+NORM);
    return 1;
  }
  if (str2=="air") {
    if (MY_POUCH->query_air_elemental_obj()) {
      write(NORM+CYN+"Your air elemental swirls briefly and fades away.\n"+NORM);
      tell_room(environment(MY_FANGS->query_air_elemental_obj()),
                NORM+CYN+"The air elemental swirls briefly and fades away.\n"+NORM);
      destruct(MY_POUCH->query_air_elemental_obj());
      MY_POUCH->set_air_elemental_obj(0);
      return 1;
    }
    else {
	  write(NORM+CYN+"You don't have an active air elemental.\n"+NORM);
	  return 1;
  }
  if (str2=="fire") {
    if (MY_POUCH->query_fire_elemental_obj()) {
      write(NORM+CYN+"Your fire elemental flares briefly and fades away.\n"+NORM);
      tell_room(environment(MY_FANGS->query_fire_elemental_obj()),
                NORM+CYN+"The fire elemental flares briefly and fades away.\n"+NORM);
      destruct(MY_POUCH->query_fire_elemental_obj());
      MY_POUCH->set_fire_elemental_obj(0);
      return 1;
    }
    else {
	  write(NORM+CYN+"You don't have an active fire elemental.\n"+NORM);
	  return 1;
  }
  if (str2=="earth") {
    MY_POUCH->dismiss_earth_elementals();
    write(NORM+CYN+"You have dismissed all of your earth elementals.\n"+NORM);
  }
}
