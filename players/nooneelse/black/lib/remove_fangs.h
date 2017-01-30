/*
  remove_fangs.h
*/

#include "defs.h"

/* ----- Allow upper level members to remove players fangs but not remove
         them from the guild                                     ------- */
remove_fangs(str) {
  object target_obj, obj;
  if (!str) {
    write("You must specify who's fangs you want to remove.\n");
    write("Use: remove <who>\n");
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
if(!obj) {
  write(capitalize(str)+" has no vampire fangs to remove.\n");
  return 1; }
if(obj) {
  write("You remove the fangs of "+capitalize(str)+".\n");
  tell_object(target_obj,BOLD+
    "Your vampire fangs have been removed pending review"+NORM+".\n");
  destruct(obj);
  return 1; }
}
