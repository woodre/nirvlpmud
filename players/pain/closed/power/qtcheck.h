qtcheck(string str) {
object who, obj;
  if(!str) { write("qtcheck <who>\n"); return 1; }
  who = find_player(str);
  if(!who) { write(str+" is not logged on.\n"); return 1; }
  obj = present("quicktyper",who);
  if(!obj) { write("No quicktyper on "+str+".\n"); return 1; }
  write(">> "+str+"'s History:\n");
  obj->history();
  return 1;
}