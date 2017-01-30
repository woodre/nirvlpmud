register(string str) {
object who;
  if(!str) { write("register <who> \n"); return 1; }
  who = find_player(str);
  if(!who) { write(str+" is not logged on.\n"); return 1; }
  if(who->query_ghost()) { write("That player is dead.\n"); return 1; }
  who->reset(1);
  who->recalc_carry();
  who->recalc_quest();
  write("Registered.\n");
  return 1;
}
