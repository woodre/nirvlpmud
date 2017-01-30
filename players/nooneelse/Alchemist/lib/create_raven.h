/*
  create_raven.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Make a raven from a corpse ---------- */
create_raven(raven_name) {
  object target_obj, raven_obj;
  int i;
  string first_letter;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you create anything? You are a ghost!\n"+NORM);
    return 1;
  }
  /* put in because some were naming ravens after players */
  /* raven_name = "edgar"; */
  /* taken out by nooneelse because i have a fix for that */
  first_letter = extract(raven_name, 1, 1);
  if (file_size("/pfiles/"+first_letter+"/"+raven_name)>0) {
    write(NORM+CYN+"You can't name your raven after a player!\n"+NORM+
          NORM+HIR+"DON'T"+NORM+CYN+" try this kind of crap again!\n"+NORM);
    return 1;
  }

  if (MY_POUCH->query_raven_obj()) {
    write(NORM+CYN+"You can only make one raven at a time.\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 60) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }

  if (MY_POUCH->query_quantity("moldy bread") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (moldy bread).\n"+NORM);
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
  if (MY_SPELL_POINTS < 30) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  target_obj = present("corpse", MY_ROOM);
  if (!target_obj) {
    write(NORM+CYN+"A corpse must be present to do that.\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("moldy bread", 1);
  MY_POUCH->subtract_quantity("mercury", 1);
  MY_POUCH->subtract_quantity("iron rod", 1);
  MY_POUCH->subtract_quantity("vampire blood", 1);
  MY_PLAYER->add_spell_point(- 30);
  destruct(target_obj);
  raven_obj = clone_object(VAMPIRE_raven);
  MY_POUCH->set_raven_obj(raven_obj);
  raven_obj->set_master_name(MY_NAME);
  /*NOTE: both set_name & set_raven_name are overridden in the raven's
          set_raven_name to name it edgar */
  /* not anymore! */
  raven_obj->set_name(lower_case(raven_name));
  raven_obj->set_raven_name(lower_case(raven_name));
  i = MY_LEVEL;
  raven_obj->set_level(i);
  raven_obj->set_hp(666666);
  raven_obj->set_ac(99);
  i = MY_LEVEL;
  if (i < 10) i = 4;
  raven_obj->set_wc(i);
  move_object(raven_obj, MY_ROOM);
  command("fix raven", MY_PLAYER);
  write(NORM+CYN+MY_NAME_CAP+"Pours some oil on the corpse.\n"+
        "The corpse goes through some wierd contortions, "+
        "then raises as a raven and says:\n"+
        "'   My name is "+capitalize(raven_obj->query_name())+"'.\n"+NORM);
  MY_POUCH->tell_my_room(
              NORM+CYN+
              MY_NAME_CAP+"Pours some oil on the corpse.\n"+
              "The corpse goes through some wierd contortions,\n"+
              "then raises as a raven and says:\n"+
              "'   My name is "+capitalize(raven_obj->query_name())+"'."+NORM);
  return 1;
}
