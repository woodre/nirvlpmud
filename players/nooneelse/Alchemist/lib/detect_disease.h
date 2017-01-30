/*
  detect_disease.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- detect diseases ---------- */
detect_disease(str) {
  object target_obj;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you detect anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str) {
    write(NORM+CYN+"use: detect disease [<who>]\n"+NORM);
    return 1;
  }
  if (str=="disease") str=str+" me";
  sscanf(str, "disease %s", str2);
  if (!str || !str2) {
    write(NORM+CYN+"use: detect disease\n"+NORM);
    return 1;
  }
  if (str2!="me" && !present(str2, MY_ROOM) {
    write(NORM+CYN+capitalize(str2)+" is not here!\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 20) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("mercury") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (mercury).\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("mercury", 1);
  MY_PLAYER->add_spell_point(- 50);
  write(NORM+CYN+"You place the talisman on your forehead and concentrate.\n"+NORM);
  MY_POUCH->tell_my_room(NORM+CYN+MY_NAME_CAP+
                      " places a talisman on "+MY_POSSESSIVE+
                      " forehead and closes "+MY_POSSESSIVE+" eyes."+NORM);
  if (str2=="me")
    target_obj=MY_PLAYER;
  else
    target_obj=find_player(str2);
  if (present("flu", MY_PLAYER)) {
	str=NORM+CYN+"You detect the flu.\n"+NORM
    tell_object(target_obj, str);
  }
  if (present("headcold", MY_PLAYER)) {
	str=NORM+CYN+"You detect a head cold.\n"+NORM
    tell_object(target_obj, str);
  }
  if (present("cold", MY_PLAYER)) {
	str=NORM+CYN+"You detect a cold.\n"+NORM
    tell_object(target_obj, str);
  }
  if (present("mummy_rot", MY_PLAYER)) {
	str=NORM+CYN+"You detect the mummy rot.\n"+NORM
    tell_object(target_obj, str);
  }
  if (present("disease", MY_PLAYER)) {
	str=NORM+CYN+"You detect a disease.\n"+NORM
    tell_object(target_obj, str);
  }
  return 1;
}
