#include "../DEFS.h"
#define LEVEL 10
#define DRAIN 60

status main(string str) {
  object sob;
  string mon;

  if(!gotrank(TP, LEVEL)) return 0;
  if(!gotsp(TP, DRAIN)) return 1;
  sob = clone_object("/players/dune/closed/guild/objects/stun_blow.c");
  if(!str) {
    if((object)TP->query_attack()) mon = (string)TP->query_attack()->query_real_name();
  else { write("Stun what?\n"); return 1; }
  }
  if(!mon) mon = str;
  if(!mon) { write("Stun what?\n"); return 1; }
  if(!present(mon, environment(TP)) ) {
    write(capitalize(mon)+" is not here.\n"); return 1; }
   if(present(mon, environment(TP))->is_player() && creator(environment(TP)) != "dune") {
    write("You cannot stun that.\n"); return 1; }
  if(present("stun_blow", present(mon, environment(TP)) ) ) {
    write(capitalize(mon)+" is already stunned.\n"); return 1; }
   if(!TP->query_pl_k() && random(3) == 1) {
    write("Your shocking touch fails.\n"); return 1; }
  if(present(mon, environment(TP))->query_level() > TP->query_level()) {
    if(!random(5)) {
      write("Your shocking touch fails.\n"); return 1; }
  }
  write("You stun "+capitalize(mon)+" with a shocking pressure-point touch!\n");
  say(TPN+" stuns "+capitalize(mon)+" with a shocking pressure-point touch!\n");
  move_object(sob, present(mon, environment(TP)) );
  sob->destruct_stun((int)IPTP->query_art_level()*2-4);
  TP->add_spell_point(-DRAIN);
  return 1;
}
