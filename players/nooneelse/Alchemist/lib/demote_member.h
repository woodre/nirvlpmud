/*
  demote_member.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* ---- demote a member & make 'em do guild tasks again ---- */
repair_exp(str) {
  int i, n;
  object obj, target_obj;
  string target_name, hlp_msg;

  hlp_msg="use: demote <who> <task #>\n"+
          "                   0=no tasks done yet\n"+
          "                   1=demon priest\n"+
          "                   2=sturdy short guy (dwarf in mines)\n"+
          "                   3=Baphomet (minotaur)\n"+
          "                   4=Ironwood coffin near Sebastian the Druid\n"+
          "                   5=giants\n\n";

  if (str) sscanf(str, "%s %d", target_name, n);
  if (!str || !target_name || (n<0 || n>5)) {
    write(NORM+CYN+hlp_msg+NORM);
    return 1;
  }
  if (this_player()->query_real_name()!=ALCHEMIST_GUILD_MASTER) {
    write(NORM+CYN+"You can't use that abilitiy.\n"+NORM);
    return 1;
  }
  target_obj=find_player(target_name);
  if (!target_obj) {
    write(NORM+CYN+"Can't find '"+target_name+"'\n"+NORM);
    return 1;
  }
  if (n < 0 || n > 6) {
    write(NORM+CYN+"'"+n+"' is an incorrect task #.  It must be between 0 & 5.\n"+NORM);
    return 1;
  }
  obj=present("Alchemist Pouch", target_obj);
  if (!obj) {
    write(NORM+CYN+capitalize(target_name)+" doesn't have member's pouch.\n"+NORM);
    return 1;
  }
  i = target_obj->query_guild_rank();
  target_obj->add_guild_rank(-i);
  target_obj->add_guild_rank(i);
  write(NORM+CYN+capitalize(target_name)+"'s task level is now '"+n+"'.\n"+NORM);
  return 1;
}
