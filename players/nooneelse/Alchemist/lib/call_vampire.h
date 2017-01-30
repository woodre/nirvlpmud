/*
  call_vampire.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Call a vampire to help fight ---------- */
call_vampire(str) {
  string vampire_name, str1, str2;
  object vampire_obj;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you call anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str) return 0;
  vampire_name=0;
  sscanf(str, "vampire %s", vampire_name);
  if (!vampire_name) {
    write("You must supply the vampire's name.\n"+
          "use: call vampire <name>)\n");
    return 1;
  }

  /* put in because some were naming vampires after players */
  /* vampire_name = "vlad"; */
  /* taken out by nooneelse because i have a fix for that */
  first_letter = extract(vampire_name, 1, 1);
  if (file_size("/pfiles/"+first_letter+"/"+vampire_name)>0) {
    write(NORM+CYN+"You can't name your vampire after a player!\n"+NORM+
          NORM+HIR+"DON'T"+NORM+CYN+" try this kind of crap again!\n"+NORM);
    return 1;
  }

  if (MY_GUILD_RANK < 80) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("arrow") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (arrow).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("mercury") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (mercury).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("iron rod") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (iron rod).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("vampire blood") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (vampire blood).\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  if (MY_FANGS->query_vampire_obj()) {
    write(NORM+CYN+"You can only have one vampire at a time.\n"+NORM);
    return 1;
  }
  str1=file_name(MY_ROOM);
  sscanf(str1, "%s.c", str2);
  if (!str2) str2=str1;
  if (str2 != "players/eurale/VAMPIRES/RMS/vgent" &&
      str2 != "/players/eurale/VAMPIRES/RMS/vgent") {
    write(NORM+CYN+
          "Vampires can only be summoned in the Vampire Guild's entry hall.\n"+
          NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("arrow", 1);
  MY_POUCH->subtract_quantity("mercury", 1);
  MY_POUCH->subtract_quantity("iron rod", 1);
  MY_POUCH->subtract_quantity("vampire blood", 1);
  MY_PLAYER->add_spell_point(- 50);
  vampire_obj=clone_object(ALCHEMIST_VAMPIRE);
  vampire_obj->set_master(MY_NAME);
  vampire_obj->set_name(vampire_name);
  move_object(vampire_obj, MY_ROOM);
  MY_POUCH->set_vampire_obj(vampire_obj);
  MY_POUCH->tell_my_room(
               NORM+CYN+"A vampire glides into the room and stands at "+
               MY_NAME_CAP+"'s left side."+NORM);
  write(NORM+CYN+"A vampire glides into the room and stands at your left side.\n"+NORM);
  return 1;
}
