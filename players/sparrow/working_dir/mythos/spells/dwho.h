#include "/players/mythos/closed/guild/def.h"
dwho() {
object ob;
string msg;
int n;
ob = users();
  write(CYN+
"\n   __________________________________________________________________________\n"+NORM);
  write("   Name\t\tLevel     Guild\t\tArea\n");
  write(CYN+
"   __________________________________________________________________________\n\n"+NORM);
  for(n = 0; n < sizeof(ob); n++) {
  /*
  if(((tl < 20 && ob[n]->query_invis() < 20) || tl > 20) && 
  ob[n]->query_level() > 0) {
  */
  
  if(((tl >= (ob[n]->query_level()) && ob[n]->query_invis()) ||
    !ob[n]->query_invis()) || tpn == "mythos" || tpn == "arrina" || tpn == "daranath" &&
     ob[n]->query_level() > 0) {
 
  msg = "";
  msg += NORM;
      if(ob[n]->query_attack()) {
        if((ob[n]->query_attack())->query_npc()) {
          msg += "C  "; }
        else { msg += "PK "; } }
        else if(ob[n]->query_ghost()) {
              msg += "?  "; }
      else { msg += "   "; }
      msg += capitalize(ob[n]->query_real_name());
      if(strlen(ob[n]->query_real_name()) < 5){ msg += "\t\t";}
      else{msg += "\t";}
      msg += ob[n]->query_level()+" + "+ob[n]->query_extra_level();
      if(strlen(ob[n]->query_level()+" + "+ob[n]->query_extra_level()) < 6) {
      msg += "     "; }
      if(strlen(ob[n]->query_level()+" + "+ob[n]->query_extra_level()) == 6) {
      msg += "    "; }
      if(strlen(ob[n]->query_level()+" + "+ob[n]->query_extra_level()) == 7) {
      msg += "   "; }
      if(strlen(ob[n]->query_level()+" + "+ob[n]->query_extra_level()) > 7) {
      msg += "  "; }
      if(present(fear,ob[n])) {
      msg += BOLD+"G"+NORM; }
      else {
      msg += pad(ob[n]->query_guild_name(),4); }
      if(!present(fear,ob[n]) && present(pact,ob[n])) {
      msg += " !"; }
      msg += "\t";
      if(!environment(ob[n])) { msg += "LOGIN";}
      if( environment(ob[n]) ) {
      msg += pad(environment(ob[n])->short(),35); 
      msg += NORM;}
      if( environment(ob[n]) && environment(ob[n])->realm() && 
          environment(ob[n])->realm() == "NT") {
         msg += HIB+"  x"+NORM; }
      if(ob[n]->query_fight_area() || ob[n]->query_pl_k() ||
        (present(fear,ob[n]) && present(fear,ob[n])->query_defence())) {
        msg += HIR+"  *"+NORM; }
   if(ob[n]->query_invis()) { msg += "] "+GRN+ob[n]->query_invis()+NORM+" ["; }
      if(in_editor(ob[n]) && tl > 19) { msg += HIM+" ED"+NORM; }
      msg += "\n";
      write(msg);
  } }
  write("\n"+
"   C = combat,G = guild,! = w/aura,x = non-teleport,* = killable,? = dead\n");
  write(CYN+
"   __________________________________________________________________________\n"+NORM);
  return 1;}
