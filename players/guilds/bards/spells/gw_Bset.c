#include "/players/guilds/bards/def.h"

status main(string str) {
  string target;
  object who;
  object instr, instr2;
  
  if (spell(-1000, 11, 9) == -1);
  if (!str || sscanf(str, "%s", target) != 1) {
    write("\nBard Master, you must type: Bset <bard name>\n\n");
    return 1;
  }
  if (!(who = find_player(target))) {
    write("I can not find " + TARG + " within the realms of magic.\n");
    return 1;
  }
  if ((string)who->query_guild_name() != "bard") {
    write(TARG + " is not a BARD!\n");
    return 1;
  }
  instr = present("bard_obj",who);
  if(instr) {
    command("pppp",who);
    destruct(instr);
  }
  instr2 = clone_object("/players/guilds/bards/instrument.c");
  move_object(instr2, who);
  write("You have given " + TARG + " a new instrument.\n");
  tell_object(who, "You have a new instrument.\n");
  return 1;
}

