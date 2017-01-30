/*
  scan.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* --------------  check out my pet's % hp level --------------*/
scan_monster(str) {
  object obj;
  int n;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 60) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (!str) {
    write(NORM+CYN+"You must supply the pet's name.\n"+NORM);
    return 1;
  }
  obj = 0;
  obj = present(str, MY_ROOM);
  if (!obj) obj = MY_PLAYER->query_attack();
  if (!obj) obj = find_living(str);
  if (!obj) {
    write(NORM+CYN+"I can't find '"+str+"' to scan.\n"+NORM);
    return 1;
  }
  if (obj->query_mhp() <= 0)
    write(NORM+CYN+"Sorry, can't scan the '"+str+"'.\n"+NORM);
  else {
    n = (obj->query_hp() * 10) / obj->query_mhp();
    write(NORM+CYN+obj->short()+"'s current % of hp is "+n+".\n"+NORM);
  }
  return 1;
}
