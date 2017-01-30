/*
  clairaudience.h
*/

#include "defs.h"

/* -------- Clairaudience ---------- */
clairaudience(str) {
  object target_obj, snooper_bat_obj, players_there;
  if (!str) {
    write("You must specify who you wish to listen to.\n");
    write("Use: clairaudience <who> or ca <who>\n");
    return 1;
  }
  target_obj=find_living(str);
  if (!target_obj) {
    write("Your mind cannot locate "+str+".\n");
    return 1;
  }
  if (!target_obj->query_npc() &&
      target_obj->query_level() > 19 &&
      MY_LEVEL < 20) {
    write("You can't listen to a wizard!\n");
    return 1;
  }
  players_there = first_inventory(environment(target_obj));
  while (players_there) {
    if (!players_there->query_npc() &&
        players_there->query_level() > 19 &&
        MY_LEVEL < 20) {
      write("You can't listen to a room with a wizard in it!\n");
      break;
    }
    players_there=next_inventory(players_there);
  }
  if(1 == 1) {
/*
  if (MY_LEVEL < 10 || MY_GUILD_EXP < 669) {
changed by wizardchild, this needed removal 
*/
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 20) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 20);
  snooper_bat_obj=clone_object(SNOOPER_BAT);
  snooper_bat_obj->set_owner(MY_NAME);
  move_object(snooper_bat_obj, target_obj);
  write("Ok.  You are concentrating on the environment of "+
        capitalize(str)+"\n");
  return 1;
}
