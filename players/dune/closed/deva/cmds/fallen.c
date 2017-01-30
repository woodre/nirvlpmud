/*
 * FALLEN command for Ascension
 * kick player out of guild
 */
#include "../def.h"

status main(string str) {
  string file;
  int real_exp, gexp, glev;
  object ob;

  needrank(11);
  if(!str) {
    write("Who is the fallen angel?\n");
    write("Note: This is to be done in only drastic circumstances.\n");
    return 1; }
  if(!find_player(str)) {
    write("No such player\n");
    return 1; }
  ob = find_player(str);
  if(!IPOB) {
    write("No such angel.\n");
    return 1; }
  real_exp = ((int)call_other(ob, "query_exp", 0));
  ob->set_guild_name(0);
  gexp = ((int)ob->query_guild_exp());
  glev = ((int)ob->query_guild_rank());
  ob->add_guild_exp(-gexp);
  ob->add_guild_rank(-glev);
  ob->set_title("the Fallen Angel");
  ob->set_guild_file(0);
  ob->set_home("room/church");
  file = ALTSAVEDIR+lower_case(ORN)+".o";
  rm(file);
  tell_object(ob, "\n\n\n\n\nYou loose your immortal soul.\n"+
                  "Constructing standard mortal soul...\n\n"+
                  "Your paradise has been lost, you are fallen angel.\n");
  CHANNELD->announce(ORN+" has fallen from the heavens.\n");
  write_file(LOGDIR+"FALLEN", ORN+" was cast out of heaven by "+
                         TRN+". ("+ctime()+"\n");
  destruct(IPOB);
  real_exp = real_exp / 2;
  ob->add_exp(-real_exp);
  ob->save_me();
  return 1;
}
