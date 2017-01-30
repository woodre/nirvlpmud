/*
 * ASCEND command for Ascension
 * way to advance in guild level
 */
#include "../def.h"


int already_in_a_guild(object ob) {
/* Checks if player is in another guild */
  if((ob->query_guild_name() != 0) ||
     (ob->query_guild_exp() != 0)  ||
     (ob->query_guild_file() != 0) ||
     (ob->query_guild_rank() != 0)) {
       return 1;}
  return 0;
}

status main(string str) {
  string type;
  object ob;
  if(!str) {
    write("You show heaven your good deeds.\n");
    LEVELD->renew_class(TP);
    return 1; }

  needrank(7);
  str = lower_case(str);
  if(!find_player(str)) {
    write("Player "+CAP(str)+" is not on Nirvana.\n");
    return 1; }
  ob = find_player(str);
  if(already_in_a_guild(ob)) {
    write(OPN+" cannot also be in a guild.\n");
    return 1; }
  if(ob->query_level() < MIN_LEV) {
    write(OPN+" is not level "+MIN_LEV+" yet.\n");
    return 1; }
  write("You have given "+OPN+" divine grace.\n");
  CHANNELD->announce(ORN+" has risen!\n");
  tell_object(ob, "\n\n\n\n\nYou loose your mortal soul.\n"+
                  "Constructing new soul...\n\n"+
                  "Welcome to Ascension, the Race of Immortals.\n");
  write_file(LOGDIR+"RECRUIT", 
    TRN+" recruited "+ORN+" ("+ctime()+")\n");
  TP->set_guild_file(GUILDOBJ);
  TP->set_guild_name(GUILDNAME);
  TP->add_guild_exp(1);
  TP->save_me();
  move_object(clone_object(GUILDOBJ), ob);
  IPOB->save_me();
  return 1;
}
