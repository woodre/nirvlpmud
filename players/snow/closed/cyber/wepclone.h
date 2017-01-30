#include "DEFS.h"

weapon() {
/* gives a player their ninja weapon */
  int currentwep, artcost;
  string wepmaster;
  wepmaster = "/players/snow/closed/cyber/rooms/weaponry.c";
  currentwep = IP(TP)->query_weapon();
  if(present("nwep",TP)) {
    write("You already have a weapon.\n");
  return 1;
  }
  if(!currentwep) {
    wepmaster->get_weapon("unarmed");
    write("You focus your Ch'i for battle.\n");
    return;}
  if(!(wepmaster->isAweapon(currentwep)) ) {
    write("Your weapon does not exist. Get a wiz, quick.\n");
    return;}
  if(currentwep == "unarmed") {
    write("You focus your Ch'i for battle.\n");
    currentwep = (wepmaster->findGoodNameForWeapon(currentwep));
    wepmaster->get_weapon(currentwep); return; }
  if(TP->query_spell_point() < 40) {
    write("You try to retrieve your weapon from cyberspace.\n");
    write("However, you are too low in energy.\n");
    wepmaster->get_weapon("unarmed");
    write("You focus your Ch'i for battle.\n"); return; }
  call_other(TP, "add_spell_point", -40);
  currentwep = (wepmaster->findGoodNameForWeapon(currentwep));
  wepmaster->get_weapon(currentwep);
  write("You draw a "+currentwep+" out from cyberspace.\n");
  say(TPN+" draws a "+currentwep+" out from cyberspace.\n");
return 1; }
