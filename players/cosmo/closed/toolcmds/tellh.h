tellh(string str) {
object who;
  if(!str) { write("tellh <who> \n"); return 1; }
  who = find_player(str);
  if(!who) { write(str+" is not logged on.\n"); return 1; }
  who->write_tellhistory();
  return 1;
}
