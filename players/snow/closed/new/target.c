#include "../DEFS.h"
#include DEFS_ENHANCEMENTS

/* TARGETTING SYSTEM */

status main(string str) {
  object meat;
  int mywil, myint, myglev, mylinks;
  if(!((status)IPTP->item_weplink()) && !IPTP->guild_wiz()) return 0;
  if(!gotsp(TP, ENERGY_TARGET)) return 1;
  if(!str) { write("Target what?\n"); return 1; }
  meat = present(str, environment(TP));
  mywil = (int)TP->query_attrib("wil");
  myint = (int)TP->query_attrib("int");
  myglev = (int)IPTP->guild_lev();
  mylinks = (int)IPTP->item_weplink();
  if(!meat) { write("[ "+str+" ] is not here.\n"); return 1; }
  if(!call_other(COMBATD, "valid_attack", meat, TP)) {
    write("You cannot target [ "+str+" ]\n"); return 1; }
  if((object)IPTP->query_target() == meat) {
    write("You have already targetted [ "+str+" ]\n"); return 1; }
  if(mywil < random(23) || myint < random(23) ||
     myglev < random(6) || mylinks < random(4)) {
    failure(); return 1; }
  tell_object(TP, BOLD+"Targetting [ "+str+" ]\n"+OFF);
  IPTP->set_target(meat);
  TP->add_spell_point(-ENERGY_TARGET);
  return 1;
}

failure() {
  tell_object(TP, BOLD+"Targetting Failure.\n"+OFF);
  TP->add_spell_point(-10); return 1; }