#include "/players/snow/guild/def.h"
cyborg_wield(string str) {
  object wep, shadow;
  if(!str) { write("Grip what?\n"); return 1; }
  wep = present(str, TP);
  if(!wep) { write("You don't have that!\n"); return 1; }
  if(!wep->weapon_class()) { write("That is not a weapon!\n"); return 1; }
  if(wep->query_wep_shadow()) { write("You are already gripping that!\n");
    return 1; }
  shadow = clone_object("/players/snow/guild/objects/wepshad.c");
  shadow->start_wep_shadow(wep);
  write("You grip the "+wep->short()+" firmly with your bionic arm.\n");
  wep->wield(wep->query_name());
  present(GID, TP)->add_body_xp("arms", 2);
  return 1; }
