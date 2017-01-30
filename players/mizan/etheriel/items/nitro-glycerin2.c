id(str) { return str == "vial" || str == "nitro"; }
short() { return "A vial of nitroglycerin [UNSTABLE]"; }
long() {
  write("Whoa! This vial is labelled: 'DO NOT SHAKE OR DROP'.\n"+
        "You can assume that it would be very bad if you shaked\n"+
        "or dropped this thing... or even drank it... It would also\n"+
        "be a rather silly idea to even pick up this thing it seems.\n");
}

get() { return 1; }
query_save_flag() { return 1; }
query_weight() { return 1; }
query_zok() { return "BOOOOM!!"; }

init() {
  add_action("drinkme_and_die","drink");
  add_action("shakeme_and_die","shake");
}

drinkme_and_die(str) {
  if(!str || str != "nitroglycerin") return 0;
  write("You pop open the cap and slam some nitroglycerin.\n\n"+
        "BOOM!!!\n");
  tell_room(environment(this_player()),
  (this_player()->query_name()) + " stupidly drinks a vial of nitroglycerin.\nBOOM!!\n");
  zok_player();
  destruct(this_object());
  return 1;
}

shakeme_and_die(str) {
  if(!str || str != "nitroglycerin") return 0;
  write("You stupidly shake the vial of nitroglycerin.\n\n"+
        "BOOM!!!\n");
  tell_room(environment(this_player()),
  (this_player()->query_name()) + " stupidly shakes a vial or nitroglycerin.\nBOOM!!\n");
  zok_player();
  destruct(this_object());
  return 1;
}

drop() {
  write("You drop the vial of nitroglycerin. Doh!\n\n"+
        "BOOM!!!\n");
  zok_player();
  destruct(this_object());
}

zok_player() {
  int a;
  a=this_player()->query_hp();
  a = a -1;
  this_player()->add_hit_point(0-a);
  this_player()->set_second_life();
  return 1;
}

