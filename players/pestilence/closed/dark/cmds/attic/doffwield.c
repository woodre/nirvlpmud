#include <ansi.h>

#define TP this_player()

main(string str) {
  object firstwep, wep, offwep, mygob, shadow;
  mygob=previous_object();
  if(this_player()->query_ghost()) return 0;
  
  if(TP->query_ghost()) return 0;
  if(TP->query_guild_rank() < 9) {
    write("You must master your current skills first.\n");
     return 1;
 }
 if (this_player()->query_sp() < 30) {
    write("You do have the energy for this skill.\n");
    return 1;}
  if(!str) {
    offwep = mygob->query_offwep();
    if(offwep) {
      offwep->stop_offwield();
      mygob->set_offwep(0);
      write("You stop offwielding "+offwep->query_name()+" in your offhand.\n");
    }
    else 
      write("Offwield what?\n"); 
    return 1; 
  }
    if(TP->query_level() < 19) {
    write("You are not worthy enough for this skill.\n");
    return 1; }
	
  wep = present(str, TP);
	if(!wep) { write("You don't have that!\n"); return 1; }

  firstwep = TP->query_weapon();
  if(!firstwep) {
    write("You must wield a weapon before you can offwield.\n");
    return 1; 
  }
  offwep = mygob->query_offwep();
  if(offwep && offwep->query_wielded_by() == this_player())
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
  if(wep->offwield_function() == 2) {
    write("You cannot offwield this weapon.\n"); return 1; }
  if(wep->offwield(TP))
  {
    write("You focus your "+HIR+"HATRED"+NORM+" into "+wep->query_name()+", as you wield it in your offhand.\n");
    mygob->set_offwep(wep);
    shadow = clone_object("/players/pestilence/closed/dark/obj/dwieldshad3.c");
/*
   shadow = clone_object("/players/pestilence/closed/dark/obj/dwieldshad2.c");
*/
     shadow->load_it(wep);
	 this_player()->add_spell_point(-30);
    return 1;
  }
  return 0;
}
