/*
  replace_fangs.h
*/

#include "defs.h"

/* ----- Allow upper level members to fix players who lose fangs ------- */
replace_fangs(str) {
  object target_obj, obj;
  if (!str) {
    write("You must specify who you want to repair.\n");
    write("Use: replace <who>\n");
    return 1;
  }
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_ASSISTANT &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_LIEUTENANT) {
    write("You can't use that abilitiy.\n");
    return 1;
  }
  target_obj = find_player(str);
  if (!target_obj) {
    write("Can't find '"+str+"'\n");
    return 1;
  }
  obj = present("nooneelse@vampire@fangs", target_obj);
  if (obj) destruct(obj);
  move_object(clone_object(VAMPIRE_FANGS), target_obj);
  write(capitalize(str)+" now has the latest version of the vampire "+
        "guild's fangs.\n");
  return 1;
}
