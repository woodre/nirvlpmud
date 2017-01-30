#include "../DEFS.h"

status main(string str) {
  object ob, imp;
  string file;

  if(!call_other(OFFICED, "checkStone", TP, "diamond")) return 0;
  if(!str || !find_player(str)) {
    write("Unsuspend which guild member?\n");
    return 1; }
  ob = find_player(str);
  if((string)ob->query_guild_name() != GUILDNAME) {
    write("User "+capitalize(str)+" is not a "+GUILDNAME+".\n");
    return 1; }
  if(!IPOB) move_object(clone_object(GUILDOBJ), ob);
  IPOB->set_suspended(0);
  IPOB->save_me();
  move_object(IPOB, ob); /* force init */
  ob->set_guild_title();
  tell_object(ob, 
    "You have been reestablished into the guild.\n");
tell_object(ob,
"You should get a more honorable title.\n");
  call_other(CHANNELD, "overchannel", 
OPN+" has been reinstated as a guild member by "+TPN+".\n");
  write_file(LOGDIR + "/SUSPEND",
    capitalize(str)+" was reestablished by "+
    TRN+". ("+ctime()+")\n");
  return 1;
}
