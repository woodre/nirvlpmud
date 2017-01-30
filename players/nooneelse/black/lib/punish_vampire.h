/*
  punish_vampire.h
*/

#include "defs.h"

/* ------ punish a vampire guild member ------ */
punish_vampire(str) {
  object target_obj, penance_obj;
  int is_a_vamp, penance_nbr;
  string player_name, player_reason;
  if (GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_MASTER &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_ASSISTANT &&
      GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)!=GUILD_LIEUTENANT)
    return 0;
  if(!str) {
    write("Use: punish <who>\n");
    return 1;
  }
  target_obj=find_living(str);
  if(!target_obj) {
    write(capitalize(str)+" is not in the mud right now.\n");
    return 1;
  }
  call_other(GUILD_MEMBER, "???");
  is_a_vamp=call_other(GUILD_MEMBER, "query_member", str);
  if (!is_a_vamp) {
    write(capitalize(str)+" is not a vampire.\n");
    return 1;
  }
  if (present("vampire guild penance marker", target_obj)) {
    write(capitalize(str)+" is already doing penance.\n");
    return 1;
  }
  penance_nbr = random(10);
  penance_obj = clone_object(VAMPIRE_PENANCE_MARK);
  penance_obj->set_penance_nbr(penance_nbr);
  move_object(penance_obj, target_obj);
  tell_object(target_obj,
              "You have been found wanting in the eyes of a vampire "+
              GUILD_OFFICE_FLOOR_TOP->find_officer(MY_NAME)+".\n"+
              "For that reason, you have been given a penance task to do.\n"+
              "Examine the penance marker to see what you must do.\n");
  write("Ok.  "+capitalize(str)+" now has a penance to do.\n");
  return 1;
}
