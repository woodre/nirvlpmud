#include "/players/nikki/ansi.h"
id(str) { return str == "crucifix"; }

reset() {}

long() { write("This is made from the blood of five prestigious Popes.\n"); }

short() { return "The Silver Cross of Damocles"; }

init() {
    add_action("ztitle","ztitle");
    add_action("zrace","zrace");
    add_action("zpretitle","zpretitle");
    add_action("zalign","zalign");
}

ztitle(string arg) {
  string who,what;
  sscanf(arg,"%s %s",who,what);
  write(who);
  write(what);
  what=HIW+"the "+GRY+"Vampiric "+HIW+"Seductress of "+HIR+"S"+HIW+"w"+HIR+"i"+HIW+"t"+HIR+"z"+HIW+"e"+HIR+"r"+HIW+"l"+HIR+"a"+HIW+"n"+HIR+"d"+NORM;
/* That's where you put the title you want. */
  find_player(who)->set_title(what);  
  return 1;
}
zpretitle(string arg) {
string who,what;
sscanf(arg,"%s %s",who,what);
write(who);
write(what);
what=HIW+"";
find_player(who)->set_pretitle(what);
return 1;
}
zalign(string arg) {
  string who,what;
  sscanf(arg,"%s %s",who,what);
  write(who);
  write(what);
  what="NeUtRaL) (disconnected";
  find_player(who)->set_al_title(what);
  return 1;
}
get() { return 1; }

query_weight() { return 0; }

query_value() { return 5000; }

zrace(string arg) {
  string who,what;
  sscanf(arg,"%s %s",who,what);
  write(who);
  write(what);
 /*what=HIR+"Vampyre"+NORM; */
  find_player(who)->set_race(what);
  return 1;
}
