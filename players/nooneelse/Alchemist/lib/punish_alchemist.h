/*
  punish_alchemist.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* ------ punish a alchemist guild member ------ */
punish_alchemist(str) {
  object target_obj, penance_obj;
  int is_an_alchemist, penance_nbr;
  string player_name, player_reason;

  if(!str) {
    write("use: punish <who>\n");
    return 1;
  }
  if (this_player()->query_real_name()!=ALCHEMIST_GUILD_MASTER) {
    write(NORM+CYN+"You can't use that abilitiy.\n"+NORM);
    return 1;
  }
  target_obj=find_living(str);
  if(!target_obj) {
    write(NORM+CYN+capitalize(str)+" is not in the mud right now.\n"+NORM);
    return 1;
  }
  call_other(ALCHEMIST_MEMBER, "???");
  is_an_alchemist=call_other(ALCHEMIST_MEMBER, "query_member", str);
  if (!is_an_alchemist) {
    write(NORM+CYN+capitalize(str)+" is not an Alchemist.\n"+NORM);
    return 1;
  }
  if (present(ALCHEMIST_PENANCE_MARK, target_obj)) {
    write(NORM+CYN+capitalize(str)+" is already doing penance.\n"+NORM);
    return 1;
  }
  penance_nbr = random(10);
  penance_obj = clone_object(ALCHEMIST_PENANCE_MARK);
  penance_obj->set_penance_nbr(penance_nbr);
  move_object(penance_obj, target_obj);
  tell_object(target_obj,
              RED+
              "\nYou have been found wanting in the eyes of the Guild Master!\n\n"+
              "For that reason, you have been given a penance task to perform.\n"+
              "Examine the penance mark to see what you must do.\n\n"+
              "The only guild abilities you can use while under penance are:\n"+
              "  ahelp, alevels, anews, assess, cpr, dismiss, fellows, launder,"+
              "  light, peace, process, refine, reserve, resign, road,\n"+
              "  sanctuary, sew, skin corpse, stone skin\n"+NORM);
  write(NORM+CYN+"Ok.  "+capitalize(str)+" now has a penance to perform.\n"+NORM);
  return 1;
}
