#include <ansi.h>
#include "../defs.h"
status main(string str, object PO, object User)
{
  object firstwep, firstshad, wep, shadow, offwep;
  if(User->query_level() < 19 && User->query_race() != BOLD+RED+"SandStorm"+OFF) {
    write("You are not a "+BOLD+RED+"Master"+OFF+OFF+" yet.\n");
    return 1; }
  if(!str) {
    offwep = (object)PO->query_offwep();
    if(offwep) {
    User->stop_offwielding(); return 1; }
  else write("Offwield what?\n"); return 1; }
  wep = present(str, User);
  offwep = (object)PO->query_offwep();
  if(!wep) { write("You don't have that!\n"); return 1; }
  if(!wep->weapon_class()) { write("That is not a weapon!\n"); return 1; }
  if(wep->two_handed()) {
   write("You cannot offwield a two-handed weapon.\n"); return 1; }
  firstwep = (object)User->query_weapon();
  if(!firstwep) {
    write("You must wield a weapon before you can offwield.\n");
    return 1; }
  if(firstwep->two_handed()) {
    write("You cannot offwield while wielding a two-handed weapon.\n");
    return 1; }
  if(wep->query_wielded()) {
    write("You cannot offwield a wielded weapon.\n"); return 1; }
  if((int)wep->offwield_function() == 2) {
    write("You cannot offwield this weapon.\n"); return 1; }
  if(wep->query_bloodfist_wep_shadow()) {
    write("You cannot offwield a forged weapon.\n"); return 1; }
  User->offwield(wep);
  write(BOLD+RED+"United with the swirling Sands, you offwield "+
      wep->short()+".\n"+OFF+OFF);
  shadow = clone_object(OBJECTPATH+"/wepshad.c");
  shadow->start_wep_shadow(wep);
  PO->set_offwep(wep);
  PO->set_firstwep(firstwep);
  firstshad = clone_object(OBJECTPATH+"/wepshad2.c");
  firstshad->start_wep_shadow(firstwep);
  { /* Added by illarion to prevent offwielding with shields */
          object *inv;
          int x,s;
          inv=all_inventory(User);
          s=sizeof(inv);
          for(x=0;x<s;x++) {
                  if((string)inv[x]->query_type()=="shield" && inv[x]->query_worn()) {
                       log_file("derv_shield_cheat",ctime()+" "+User->query_real_name()+":"+object_name(inv[x])+"\n");
                        tell_object(User,BOLD+RED+"The Sands consume your shield!\n"+OFF);
                          transfer(inv[x],"/room/void");
                          destruct(inv[x]);
                  }
          }
  }
  return 1; }