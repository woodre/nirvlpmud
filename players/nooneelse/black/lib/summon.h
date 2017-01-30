/*
  summon.h
*/

#include "/players/eurale/defs.h"
#include "defs.h"

object obj;

/* --------------- Summon a player to the vamp's location --------------- */
summon(str) {
  object target_obj, summons_obj;
  string str1;
  if (MY_LEVEL < 13 || MY_GUILD_EXP < 670) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if(!str) {
    write("Use: summon <who>\n");
    return 1;
  }
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_ASSISTANT &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_LIEUTENANT) {
    if (MY_SPELL_POINTS < 50) {
      write("You don't have enough spell points.\n");
      return 1;
    }
  }
  str1 = file_name(MY_ROOM);
  if (str1==GUILD_COFFIN_ROOM) {
    write("You cannot use the summons in the coffins, you must\n"+
          "use the invite command in the coffins.\n");
    return 1;
  }
  if (MY_ROOM->realm()=="NT") {
    write("You are in an area that prevents that.\n");
    return 1;
  }
  target_obj = find_player(str);
  if(!target_obj || target_obj->query_invis()) {
    write("Can't find "+capitalize(str)+".\n");
    return 1;
  }
  if (present("summons", target_obj)) {
    write(capitalize(str)+" already has a summons.\n");
    return 1;
  }
  summons_obj = clone_object(VAMPIRE_GUILD_SUMMONS);
  summons_obj->set_summons_owner(MY_NAME);
  move_object(summons_obj, target_obj);
  tell_object(target_obj,
    HIR+"You have been summoned by "+MY_NAME_CAP+"."+NORM+"\n"+
    "You can:\n"+
    "  use it by typing 'accept summons' to go to "+MY_NAME_CAP+"'s location\n"+
    "  get rid of it by typing 'drop summons'\n"+
    "  check out "+MY_NAME_CAP+"'s location before deciding with "+
    "'check summons'\n");
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_ASSISTANT &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_LIEUTENANT)
    MY_PLAYER->add_spell_point(-50);
  write(HIR+capitalize(str)+" has been summoned!"+NORM+"\n");
  return 1;
}
