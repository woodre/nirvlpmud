#include <ansi.h>

#define TP this_player()

main(string str) {
  object firstwep, firstshad, wep, shadow, offwep, mygob;
  mygob=previous_object();
  if(this_player()->query_ghost()) return 0;
  
  if(TP->query_ghost()) return 0;
  if(TP->query_guild_rank() < 6) {
    write("You must master your current skills first.\n");
     return 1;
 }
  if(!str) {
    offwep = mygob->query_offwep();
    if(offwep) {
    TP->stop_offwielding(); return 1; }
  else write("Offwield what?\n"); return 1; }
  wep = present(str, TP);
  offwep = mygob->query_offwep();
  if(!wep) { write("You don't have that!\n"); return 1; }
  if(!wep->weapon_class()) { write("That is not a weapon!\n"); return 1; }
  if(wep->two_handed()) {
   write("You cannot offwield a two-handed weapon.\n"); return 1; }
  /*if(!wep->id("sword") && !wep->id("knife") && !wep->id("dagger")){
    write("You may not wield any weapons besides swords or knives.\n");
    return 1;
  }*/
  firstwep = TP->query_weapon();
  if(!firstwep) {
    write("You must wield a weapon before you can offwield.\n");
    return 1; }
  if(firstwep->two_handed()) {
    write("You cannot offwield while wielding a two-handed weapon.\n");
    return 1; }
  if(wep->query_wielded()) {
    write("You cannot offwield a wielded weapon.\n"); return 1; }
  if(wep->offwield_function() == 2) {
    write("You cannot offwield this weapon.\n"); return 1; }
  TP->offwield(wep);
  write("You wield "+wep->short()+" in your offhand.\n");
  shadow = clone_object("/players/snow/dervish/objects/wepshad.c");
  shadow->start_wep_shadow(wep);
  mygob->set_offwep(wep);
  mygob->set_firstwep(firstwep);
  firstshad = clone_object("/players/snow/dervish/objects/wepshad2.c");
  firstshad->start_wep_shadow(firstwep);
  { /* Added by illarion to prevent offwielding with shields */
	  object *inv;
	  int x,s;
	  inv=all_inventory(TP);
	  s=sizeof(inv);
	  for(x=0;x<s;x++) {
		  if((string)inv[x]->query_type()=="shield" && inv[x]->query_worn()) {
                       log_file("derv_shield_cheat",ctime()+" "+TP->query_real_name()+":"+file_name(inv[x])+"\n");
                        tell_object(TP,BOLD+"The ancients consume your shield!\n"+OFF);
			  transfer(inv[x],"/room/void");
			  destruct(inv[x]);
		  }
	  }
  }
  return 1; }
