#define TO this_object()
#include "/players/eurale/closed/ansi.h"
int chance, ti;
int old_sps,tempsps;

id(str) { return str == "hole" || str == "pulsating black hole"; }

short() { write(BOLD+"~~pulsating black HOLE~~"+NORM+"\n"); }

long() { write(
  "A pulsating black hole that seems to be drawing all energy toward\n"+
  "itself.  It makes your skin crawl to be near it....\n"); }

drop() {return 0;}
get() { return 0;}

reset(arg) {
  if(arg) return;
}

init() {
  ti = 0;
  old_sps = environment(TO)->query_spell_point();
  call_out("check",1);
}

check() {
if(environment(TO)) {
  environment(TO)->add_spell_point(-(old_sps + 300));
  ti = ti + 1;

  if(ti == 10) {
    tell_object(environment(TO),
      "The hole slowly closes and then "+BOLD+"EXPLODES"+NORM+" in a "+
      "million shards of "+BOLD+"DARKNESS!"+NORM+"\n");
    tempsps = -(environment(TO)->query_spell_point());
    environment(TO)->add_spell_point(tempsps + old_sps);
    destruct(TO);
    return 1; }

  call_out("check",1);
  return 1; }
}

query_save_flag() { return 1; }
