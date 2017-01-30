#include <ansi.h>
#include "../defs.h"

#define TP this_player()

status main(string str, object PO, object User)
{
  object firstwep, wep, offwep, mygob;
  mygob=previous_object();
  if(this_player()->query_ghost()) return 0;

  if(TP->query_ghost()) return 0;
  if(User->query_level() < 19 && User->query_race() != BOLD+RED+"SandStorm"+OFF) {
    write("You are not a "+BOLD+RED+"Master"+OFF+OFF+" yet.\n");
    return 1; 
  }
  if(!str) {
    offwep = (object) mygob->query_offwep();
    if(offwep) {
      offwep->stop_offwield();
      mygob->set_offwep(0);
      write("You stop offwielding "+offwep->query_name()+" in your offhand.\n");
    }
    else
      write("Offwield what?\n");
    return 1;
  }
  wep = present(str, TP);
  if(!wep) {
    write("You don't have that.\n");
    return 1;
  }
  firstwep = (object) TP->query_weapon();
  if(!firstwep) {
    write("You must wield a weapon before you can offwield.\n");
    return 1;
  }
  offwep = (object) mygob->query_offwep();
  if(offwep && (object) offwep->query_wielded_by() == this_player())
  {
    write("You are already offwielding "+offwep->query_name()+".\n");
    return 1;
  }
  if(firstwep->two_handed()) {
    write("You cannot offwield while wielding a two-handed weapon.\n");
    return 1; }
  if(wep->two_handed()) {
    write("You may not offwield a two-handed weapon.\n");
    return 1;
  }    
  if((int) wep->offwield_function() == 2) {
    write("You cannot offwield this weapon.\n"); return 1; }
  if(wep->offwield(TP))
  {
    write("You wield "+wep->query_name()+" in your offhand.\n");
    mygob->set_offwep(wep);
    return 1;
  }
  return 0;
}
 
