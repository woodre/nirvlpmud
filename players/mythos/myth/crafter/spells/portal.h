portal(string where,string targ) {
string wch,trg;
string wch2,trg2;
object port;
int tmp,tmp2;
  if(!where) { write("portal <destination> <target>\n"+
                     "destination : p# or t# or here - for current room\"+
                     "  ex. p1 or t1 or here\n"+
                     "target: if no target then default is current room\n"+
                     "        or target  person\n"+
                     "        or p# or t#\n");
               command("showtemp",tp); command("showperm",tp);
               return 1; }
  if(sscanf(where,"p%d",tmp) == 1) wch = "p";
  else if(sscanf(where,"t%d",tmp) == 1) wch = "t";
  else if(where == "here") wh = "h"
  else return 0;
  if(wch != "p" && wch != "t" && wh != "h") return 0;
  if(targ) {
  if(sscanf(targ,"p%d",tmp2) == 1) trg = "p";
  else if(sscanf(targ,"t%d",tmp2) == 1) trg = "t";
  else trg = targ;}
  else trg = "h";
  if(tsp < 40) { write("You do not have enough sp.\n"); return 1; }
  if((trg == "h" || wh == "h") && etp->realm() == "NT") {
    write("You may not create a portal to or from here.\n");
  return 1; }
  if(trg != "h" && trg != "p" && trg != "t") {
    if(!find_player(trg)) { write("Target person is not on.\n"); return 1; }
    if(find_player(trg)->query_invis()) {
      write("Target person is not on.\n"); return 1; }
    if(find_player(trg)->query_level() > 19) {
      write("You may not make a wiz a target.\n"); return 1; }
    if(environment(find_player(trg))->realm() == "NT") {
      write("Something prevents you from making a portal near that person.\n");
    return 1; }
  }
  if(wch == "p") {
    if(tmp > MAXROM/2 || tmp < 1) {
     write("That number does not exist.\n"); return 1; }
     wch2 = SOURCE->query_rom((tmp-1)*2);
     if(!wch2) { write(tmp+" has not been set to a location.\n");
     return 1; }
  } else if(wch == "t") {
    if(tmp > MAXRAMUSE/2 || tmp < 1) {
     write("That number does not exist.\n"); return 1; }
     wch = SOURCE->query_ram((tmp-1)*2);
     if(!wch2) { write(tmp+" has not been set to a location.\n");
     return 1; }
  } else wch2 = object_name(etp);
  if(trg == "p") {
    if(tmp2 > MAXROM/2 || tmp2 < 1) {
     write("That number does not exist.\n"); return 1; }
     trg2 = SOURCE->query_rom((tmp2-1)*2);
     if(!trg2) { write(tmp2+" has not been set to a location.\n");
     return 1; }
  } else if(trg == "t") {
    if(tmp2 > MAXRAMUSE/2 || tmp2 < 1) {
     write("That number does not exist.\n"); return 1; }
     trg2 = SOURCE->query_ram((tmp2-1)*2);
     if(!trg2) { write(tmp2+" has not been set to a location.\n");
     return 1; }
  } else if(trg == "h") trg2 = object_name(etp);
  else trg2 = object_name(environment(find_player(trg)));
  tp->add_spell_point(-40);
  port = clone_object("/players/mythos/myth/crafter/spells/portal.c");
  port->set_dest("portal",wch2);
  port->set_who(tpn);
  move_object(port,trg2);
  write("\n");
  tell_room(environment(port),"\n");
return 1; }