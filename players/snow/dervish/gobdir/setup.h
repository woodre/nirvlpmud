/* DERVISH GUILD SETUP FUNCTIONS */
setup(object ob) {
  if(!ENV()) return 0;
  if(!ENV()->is_player()) return 0;
  ob->RegisterArmor(this_object(), ({"physical",0,0,"do_special"}));
  if(!restore_me(ob)) save_me(ob);
  reset();
  return 1; }

save_me(object ob) {
  string file;
  int tellme;
  if(ob) tellme++;
  if(!ob) ob = ENV();
  file = "players/snow/dervish/member/" + ob->query_real_name();
  if(!save_object(file)) {
    if(tellme) tell_object(ob,"Save error...\n");
    return 0;
    }
  if(tellme) tell_object(ob,"Saving Dervish whirlwind...\n");
  return 1;
}

restore_me(object ob) {
  string file;
  file = "players/snow/dervish/member/" + ob->query_real_name();
  if(!restore_object(file)) {
    tell_object(ob,"Dervish whirlwind restoration error...\n");
    return 0;
    }
  tell_object(ob,"Your whirlwind whips about you...\n");
  return 1;
}

do_special(owner)
{
  int lev;
  if(!owner) return;
  return - ((int)owner->query_ac());
}
