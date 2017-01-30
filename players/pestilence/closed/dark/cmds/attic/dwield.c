#include "/players/pestilence/ansi.h"
#define TP this_player()

main(string str) {
  object firstwep, firstshad, wep, shadow, offwep, mygob;
  int wepwc;
  mygob = present("dknight_ob", TP);
if(this_player()->query_guild_rank() < 9){ write("You can't use ability yet.\n"); return 1; }
if (this_player()->query_sp() < 30) {
    write("You do have the energy for this skill.\n");
    return 1;}
  if(!str) {
    if(offwep) {
    TP->stop_wielding(); return 1; }
  else write("Dwield what?\n"); return 1; }
  wep = present(str, TP);
  offwep = mygob->query_offwep();
  if(!wep) { write("You don't have that!\n"); return 1; }
  if(!wep->weapon_class()) { write("That is not a weapon!\n"); return 1; }
  firstwep = TP->query_weapon();
  if(wep->query_wielded()) {
    write("You are already wielding that.\n"); return 1; }
  if(wep->query_offwielded()) {
    write("You are offwielding that.\n"); return 1; }
   command("wield "+str+"",this_player());
  write("You focus your "+HIR+"HATRED"+NORM+" into "+
      wep->short()+".\n"+NORM);
   shadow = clone_object("/players/pestilence/closed/dark/obj/dwieldshad2.c");
      shadow->load_it(wep);
	  this_player()->add_spell_point(-30);
  return 1;
  }
