#include "/players/pestilence/ansi.h"

main(string str) {
  object firstwep, firstshad, wep, shadow, offwep, mygob;
  object TP;
  int wepwc;
  TP = this_player();
  mygob = present("dknight_ob", TP);
if(this_player()->query_guild_rank() < 8){ write("You can't use ability yet.\n"); return 1; }
  if(TP->query_level() < 19) {
    write("You are not worthy enough for this skill.\n");
    return 1; }
  if(!str) {
    if(offwep) {
    TP->stop_offwielding(); return 1; }
  else write("Offwield what?\n"); return 1; }
  wep = present(str, TP);
  offwep = mygob->query_offwep();
  if(!wep) { write("You don't have that!\n"); return 1; }
  if(!wep->weapon_class()) { write("That is not a weapon!\n"); return 1; }
  if(wep->two_handed()) {
   write("You cannot offwield a two-handed weapon.\n"); return 1; }
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
  write(BOLD+RED+"Dark powers combine with your soul, to let you offwield "+
      wep->short()+".\n"+NORM);
  shadow = clone_object("/players/pestilence/closed/dark/obj/wepshad.c");
  shadow->start_wep_shadow(wep);
  mygob->set_offwep(wep);
  mygob->set_firstwep(firstwep);
  firstshad = clone_object("/players/pestilence/closed/dark/obj/wepshad2.c");
  firstshad->start_wep_shadow(firstwep);
  return 1; }
