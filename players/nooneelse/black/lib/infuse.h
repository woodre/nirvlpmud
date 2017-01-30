/*
  infuse.h
*/

#include "defs.h"

/* --------------- infuse another vampire with energy (sp) --------------- */
infuse(str) {
  object obj;
  string target_name;
  int sp_amt;
  if (!str) {
    write("Use: infuse <who> <sp>\n");
    return 1;
  }
  if (MY_LEVEL < 5 || MY_GUILD_EXP < 668) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  target_name = 0;
  obj = 0;
  sp_amt = 0;
  if (sscanf(str, "%s %d", target_name, sp_amt)!=2) {
    write("Use: infuse <who> <sp>\n");
    return 1;
  }
  obj = find_player(target_name);
  if (MY_PLAYER==obj) {
    write("You cannot infuse yourself.\n");
    return 1;
  }
  if (!target_name || !obj || obj->query_invis()) {
    write(capitalize(target_name)+" can't be found to infuse with energy.\n");
    return 1;
  }
  if (!present("nooneelse vampire fangs", obj)) {
    write(capitalize(target_name)+" isn't a vampire and can't be infused\n"+
          "with energy.\n");
    return 1;
  }
  if (sp_amt <= 0) {
    write("You must specify how much energy to send.  "+
          "Use: infuse <who> <sp>\n");
    return 1;
  }
  if (MY_SPELL_POINTS < sp_amt) {
    write("you don't have that many spell points\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- sp_amt);
  /* lose up to 20% in transfer */
  sp_amt = sp_amt - random(((sp_amt / 10) * 2));
  obj->add_spell_point(sp_amt);
  write("You concentrate for a moment and send "+sp_amt+
        " of your mental energy to "+capitalize(target_name)+".\n");
  tell_object(obj, "You jerk for a second as energy flows into you from "+
                   MY_NAME_CAP+".\n");
  tell_room(environment(obj),
            capitalize(target_name)+" jerks for a second as if shocked.\n");
  return 1;
}
