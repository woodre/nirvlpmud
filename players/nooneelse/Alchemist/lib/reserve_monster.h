/*
  reserve_monster.h
*/

#include "defs.h"

/* -------- reserve a monster for the alchemist ---------- */
/* ~~~~~~~~~ effort to stop kill stealing ~~~~~~~~ */
forbid_entry(str) {
  object sphere_obj, monster_obj;

  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str) {
    write(NORM+CYN+"You must supply the name of the monster. "+
          "(ex: 'reserve wolf').\n"+NORM);
    return 1;
  }
  monster_obj=present(str, MY_ROOM);
  if (!monster_obj) {
    write(NORM+CYN+"'"+str+"' is not here.\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 20) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("olive branch") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (olive branch).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("iron rod") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (iron rod).\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_sphere_obj()) {
    write(NORM+CYN+"You already have a sphere. You must either remove it,\n"+
          "or wait till it dissapates.\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("olive branch", 1);
  MY_POUCH->subtract_quantity("iron rod", 1);
  MY_PLAYER->add_spell_point(- 50);
  sphere_obj = clone_object(ALCHEMIST_RESERVE_MONSTER);
  sphere_obj->set_owner(MY_NAME);
  sphere_obj->set_monster_name(str);
  sphere_obj->set_monster_obj(monster_obj);
  move_object(monster_obj, sphere_obj);
  move_object(sphere_obj, MY_ROOM);
  MY_POUCH->set_sphere_obj(sphere_obj);
  MY_POUCH->tell_my_room(
              NORM+CYN+MY_NAME_CAP+
              " makes a few gestures and concentrates for\n"+
              "a moment and a flaring blue sphere springs up around "+str+"."+NORM);
  write(NORM+CYN+"You make a few gestures and concentrate for a moment and a\n"+
        "flaring blue sphere springs up around "+str+".\n"+NORM);
  return 1;
}
