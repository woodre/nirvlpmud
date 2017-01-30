/*
  scan_monster.h
*/

#include "defs.h"

/* --------------  check out a monster's % hp level --------------*/
scan_monster(str) {
  object obj;
  int n;
  if (MY_LEVEL < 5 || MY_GUILD_EXP < 668) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (!str) {
    write("You must supply the monster's name.\n");
    return 1;
  }
  obj = 0;
  obj = present(str, MY_ROOM);
  if (!obj) obj = MY_PLAYER->query_attack();
  if (!obj) obj = find_living(str);
  if (!obj) {
    write("I can't find '"+str+"' to scan.\n");
    return 1;
  }
  if (!obj->id("wolf") && !obj->id("servant")) {
    if (MY_SPELL_POINTS < 5) {
      write("You don't have enough spell points.\n");
      return 1;
    }
  }
  if (obj->query_mhp() <= 0)
    write("Sorry, can't scan the '"+str+"'.\n");
  else {
    n = (obj->query_hp() * 10) / obj->query_mhp();
    if (!obj->id("wolf") && !obj->id("servant"))
      MY_PLAYER->add_spell_point(- 5);
    write(obj->short()+"'s current % of hp is "+n+"0.\n");
  }
  return 1;
}
