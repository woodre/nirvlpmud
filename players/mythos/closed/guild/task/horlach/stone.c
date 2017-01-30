#include "/players/mythos/closed/guild/def.h"
int tim;

id(str) { return str == "altar" || str == "stone" || str == "stone altar" ||
                 str == "crydium"; }

drop() { return 1; }

get() { return 0; }

short() { return HIB+"Altar"+NORM; }

long() { write("A large altar made of the eery material crydium.\n"+
               "Upon the altar is some markings that you may read.\n"+
               "An odd light eminates from within the glass-like\n"+
               "surface of the altar.\n"); }

set_time(n) { tim = n; }

reset(arg) {
  if(arg) return;
  set_heart_beat(1);
}

init() {
  add_action("read","read");
  add_action("touch","touch");
}

read(str) {
  if(!str) return 0;
  if(id(str)) {
    write(HIR);
    cat("/players/mythos/closed/guild/task/horlach/talisman");
    write(NORM+"\n");
  return 1;}
}

touch(str) {
  if(!str) return 0;
  if(id(str)) {
    write(BOLD+"\nA VOICE speaks: Do Not Touch the Stone of Crydium!\n\n"+NORM);
    tp->zap_object(tp);
  return 1; }
}

heart_beat() {
}