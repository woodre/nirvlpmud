#include "../DEFS.h"
#include DEFS_WEAPONS

status main(string str) {
/* gives a player their ninja weapon */
  string currentwep, wepName, tempwep;
  object ob;
  int obweight;

  currentwep = (string)IPTP->query_weapon();
  if(currentwep == "0") currentwep = 0;
  if(currentwep && present(currentwep, TP) ) {
/* added by wocket */
if(present("chi",TP)){
    destruct(present("chi",TP));
    command("wep",TP);
    return 1;
}
/* end addition */
    write("You already have a weapon.\n");
    return 1;
  }
  if(!currentwep) tempwep = UNARM;
  else tempwep = currentwep;
  ob = (object)call_other(WEAPOND, "findWeaponObject", tempwep);
  if(!currentwep || currentwep == UNARM) {
    move_object(ob, TP);
    write("You focus your Ch'i for battle.\n");
    command("wield chi", this_player());
    return 1; 
  }
  if((int)call_other(WEAPOND, "findWeaponCost", 
  (int)IPTP->query_art_level(), currentwep) == -1) {
    write("Your weapon does not exist. Get a wiz, quick.\n");
    return 1;
  }
  if((int)TP->query_spell_point() < 40) {
    write("You try to retrieve your weapon from cyberspace.\n");
    write("However, you are too low in energy.\n");
/* added by wocket */
ob = (object)call_other(WEAPOND,"findWeaponObject",UNARM);
/* end addition */
    move_object(ob, TP);
    write("You focus your Ch'i for battle.\n");
    command("wield chi", this_player());
    return 1; 
  }
  obweight = (int)call_other(WEAPOND,"findWeaponWeight",currentwep);
  if(!TP->add_weight(obweight)) {
    write("You are carrying too much to draw your weapon!\n");
    return 1;
  }
  call_other(TP, "add_spell_point", -40);
  move_object(ob, TP);
  wepName = (string)IPTP->query_weapon_name();
  if (!wepName)
  {
    write("You draw a "+currentwep+" out from cyberspace.\n");
    say(TPN+" draws a "+currentwep+" out from cyberspace.\n");
  }
  else
  {
    write("You draw "+wepName+" the "+capitalize(currentwep)+" out from cyberspace.\n");
    say(TPN+" draws "+wepName+" the "+capitalize(currentwep)+" out from cyberspace.\n");
  }
  command("wield "+currentwep, TP);
  return 1; 
}
