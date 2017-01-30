/*
  cure_diseases.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Cure diseases in the vampire -------- */
cure_disease(str) {
  object target_obj;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you cure anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str) {
    write(NORM+CYN+"use: cure disease [<who>]\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 20) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("moldy bread") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (moldy bread).\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }

  if (str=="disease" || str=="diseases") str=str+" me";
  sscanf(str, "disease %s", str2);
  if (!str || !str2) {
    write(NORM+CYN+"use: cure disease [<who>]\n"+NORM);
    return 1;
  }
  if (str2!="me" && !present(str2, MY_ROOM) {
    write(NORM+CYN+capitalize(str2)+" is not here!\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("moldy bread", 1);
  MY_PLAYER->add_spell_point(- 30);
  if (str2=="me")
    target_obj=MY_PLAYER;
  else
    target_obj=find_player(str2);
  /* make 3 passes in case there's more than one of each */
  cure_diseases(target_obj);
  cure_diseases(target_obj);
  cure_diseases(target_obj);
  write("Ok.");
  return 1;
}

cure_diseases(target_obj) {
  string str;

  if (present("flu", target_obj)) {
    destruct(present("flu", target_obj));
    str=NORM+CYN+"You've just been cured of the flu.\n"+NORM;
    tell_object(target_obj, str);
  }
  if (present("headcold", target_obj)) {
    destruct(present("headcold", target_obj));
    str=NORM+CYN+"You've just been cured of a head cold.\n"+NORM;
    tell_object(target_obj, str);
  }
  if (present("cold", target_obj)) {
    destruct(present("cold", target_obj));
    str=NORM+CYN+"You've just been cured of a cold.\n"+NORM;
    tell_object(target_obj, str);
  }
  if (present("mummy_rot", target_obj)) {
    destruct(present("mummy_rot", target_obj));
    str=NORM+CYN+"You've just been cured of the mummy rot.\n"+NORM;
    tell_object(target_obj, str);
  }
  if (present("disease", target_obj)) {
    destruct(present("disease", target_obj));
    str=NORM+CYN+"You've just been cured of a disease.\n"+NORM;
    tell_object(target_obj, str);
  }
}
