/*
  aid.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* --------------- aid another alchemist with energy (sp) --------------- */
aid(str) {
  object obj;
  string target_name;
  int sp_amt;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you aid anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str) {
    write(NORM+CYN+"use: aid <who> <sp>\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 60) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("fire fly") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (fire fly).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("bell") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (bell).\n"+NORM);
    return 1;
  }
  target_name = 0;
  obj = 0;
  sp_amt = 0;
  if (sscanf(str, "%s %d", target_name, sp_amt)!=2) {
    write(NORM+CYN+"use: aid <who> <amount>\n"+NORM);
    return 1;
  }
  obj = find_player(target_name);
  if (MY_PLAYER==obj) {
    write(NORM+CYN+"You cannot aid yourself.\n"+NORM);
    return 1;
  }
  if (!target_name || !obj || obj->query_invis()) {
    write(NORM+CYN+capitalize(target_name)+" can't be found.\n"+NORM);
    return 1;
  }
  if (!present("nooneelse vampire fangs", obj)) {
    write(NORM+CYN+capitalize(target_name)+" isn't an alchemist and can't be aidd\n"+
          "with energy.\n"+NORM);
    return 1;
  }
  if (sp_amt <= 0) {
    write(NORM+CYN+"You must specify how much energy to send.  "+
          "use: aid <who> <amount>\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < sp_amt) {
    write(NORM+CYN+"You don't have that many spell points\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("fire fly", 1);
  MY_POUCH->subtract_quantity("bell", 1);
  MY_PLAYER->add_spell_point(- sp_amt);
  /* lose up to 20% in transfer */
  sp_amt = sp_amt - random(((sp_amt / 10) * 2));
  obj->add_spell_point(sp_amt);
  write(NORM+CYN+"You concentrate for a moment and send "+sp_amt+
        " of your mental energy to "+capitalize(target_name)+".\n"+NORM);
  tell_object(obj, NORM+CYN+"You jerk for a second as energy flows into you from "+
                   MY_NAME_CAP+".\n"+NORM);
  tell_room(environment(obj),
            NORM+CYN+capitalize(target_name)+
            " jerks for a second as if shocked.\n"+NORM);
  return 1;
}
