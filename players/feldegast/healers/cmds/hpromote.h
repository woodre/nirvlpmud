int do_hpromote(string str) {
  object target;
  object pend;
  string x;
  int newrank;
  if(!str) {
    write("Usage: hpromote <healer> <newrank>\n");
    return 1;
  }
  if(sscanf(str,"%s %d",x,newrank)!=2) {
    write("Usage: hpromote <healer> <newrank>\n");
    return 1;
  }
  target=find_player(x);
  if(!target) {
    write("That person is not logged in.\n");
    return 1;
  }
  pend=present(GUILD_ID,target);
  if(!pend) {
    write("That person isn't a healer.\n");
    return 1;
  }
  pend->set_rank(newrank);
  target->add_guild_rank((int)TP->query_guild_rank()-(int)pend->query_rank());
  write("You've promoted/demoted "+capitalize((string)target->query_real_name())+" to rank "+newrank+".\n");
  tell_object(target,"Your rank has been changed to rank "+newrank+".\n");
  return 1;
}
