#include "../DEFS.h"

status main(string str) {
  object ob, pob;
  string who, art, belt;
  int currentlevel, level, degreelevel, qual;

  if(!IPTP->guild_manager()) return 0;

  if(!str || !sscanf(str, "%s %d", who, level) ||
     !find_player(who) || 
     !present(GUILD_ID, find_player(who))) {
    write("Not a valid user.\n");
    return 1;
  }
  if(level < 0) {
    write("Not a valid level.\n");
    return 1;
  }
  pob = find_player(who);
  ob  = present(GUILD_ID, pob);
  currentlevel = (int)ob->query_art_level();
  if(level == currentlevel) {
    write(capitalize(who)+" is already of art level "+level+".\n");
    return 1; 
  }
  belt = (string)call_other(ALEVELD, "findBeltColor", level);
  tell_object(ob, 
    "Your belt level has been changed by "+TPN+".\n");
  tell_object(TP,
    "You change "+capitalize(who)+"'s belt level to "+level+".\n");
  write_file(LOGDIR + "/ARTS",
    TRN+" changed "+capitalize(who)+"'s art level from "+
    currentlevel+" to "+level+". ("+ctime()+")\n");
  qual = (int)ob->guild_lev();
  qual += level;
  ob->set_art_level(level);
  pob->add_guild_rank(-((int)pob->query_guild_rank()));
  pob->add_guild_rank(qual);
  pob->save_me();
  ob->save_me();
  move_object(ob, pob); /* force init */
  return 1;
}
