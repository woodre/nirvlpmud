dwield(string str) {
  object firstwep, firstshad, wep, shadow, offwep, mygob;
  int wepwc;
  mygob = present("destroyer_ob", TP);
if(this_player()->query_guild_rank() < 3){ write("You can't use ability yet.\n"); return 1; }
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
   command("wield "+str+"",this_player());
  write(YEL+"Your enhanced genetic make up allows you to dwield "+
      wep->short()+".\n"+NORM);
  shadow = clone_object("/players/pestilence/closed/destroyer/powers/wepshad.c");
  shadow->start_wep_shadow(wep);
  mygob->set_offwep(wep);
  return 1; }
