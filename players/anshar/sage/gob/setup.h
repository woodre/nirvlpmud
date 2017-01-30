/* SUPER HERO GUILD SETUP FUNCTIONS */
setup(object ob) {
  if(!ENV()) return 0;
  if(!ENV()->is_player()) return 0;
  if(!restore_me(ob)) save_me(ob);
  reset();
  return 1; }

save_me(object ob) {
  string file;
  int tellme;
  if(ob) tellme++;
  if(!ob) ob = ENV();
  file = "players/anshar/sage/member/" + ob->query_real_name();
  if(!save_object(file)) {
    if(tellme) tell_object(ob,"Save error...\n");
    return 0;
    }
  if(tellme) tell_object(ob,"Saving Sage Stats...\n");
  return 1;
}

restore_me(object ob) {
  string file;
  file = "players/anshar/sage/member/" + ob->query_real_name();
  if(!restore_object(file)) {
    tell_object(ob,"Sage restoration error...\n");
    return 0;
    }
  tell_object(ob,"Your stats are restored...\n");
  return 1;
}
