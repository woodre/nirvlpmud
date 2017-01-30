port(string where) {
string wch;
int tmp;
  if(!where) { write("port <mem><#>\n"+
                     "ex: port p1 or port t1\n");
               command("showtemp",tp); command("showperm",tp);
               return 1; }
  if(sscanf(where,"p%d",tmp) == 1) wch = "p";
  else if(sscanf(where,"t%d",tmp) == 1) wch = "t";
  else return 0;
  if(wch != "p" && wch != "t") return 0;
  if(tsp < 40) { write("You do not have enough sp.\n"); return 1; }
  if(etp->realm() == "NT") {
    write("You may not teleport from here.\n");
  return 1; }
  if(wch == "p") {
    if(tmp > MAXROM/2 || tmp < 1) {
     write("That number does not exist.\n"); return 1; }
     wch = SOURCE->query_rom((tmp-1)*2);
     if(!wch) { write(tmp+" has not been set to a location.\n");
     return 1; }
  } else {
    if(tmp > MAXRAMUSE/2 || tmp < 1) {
     write("That number does not exist.\n"); return 1; }
     wch = SOURCE->query_ram((tmp-1)*2);
     if(!wch) { write(tmp+" has not been set to a location.\n");
     return 1; }
  }
  tp->add_spell_point(-40);
  tp->move_player("X#"+wch);
return 1; }