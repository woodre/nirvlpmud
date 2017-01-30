id(str) { return str == "quick fix object" || str == "fix" ||
         str == "quick fix"; }
short() { return "Quick fix object"; }
long() {
  write("A quick fixer-upper that should hopefully help out.\n"+
        "Type 'quickfix' to operate.\n");
  write("Type 'quickhb' for heartbeat restoration.\n");
  write("To destroy this object, type 'no_fix'.\n");
  return 1;
}
get() { return 1; }
drop() { return 1; }

init() {
  add_action("fix_up","quickfix");
  add_action("re_beat","quickhb");
  add_action("destroy_fix","no_fix");
}

query_auto_load() { return "/players/snow/ITEMS/fix.c"; }

fix_up() {
  if(this_player()->query_ghost()) {
    write("You are unfortunately in a state beyond help.\n");
  return 1;
  }
  call_other(this_player(),"reset",1);
  this_player()->recalc_quest();
  write("Fixup complete... hopefully you work now!\n");
return 1;
}

re_beat() {
  this_player()->set_heart_beat(1);
  this_player()->heart_beat();
  write("Your heart begins to beat again. Wow thank goodness!\n");
return 1;
}
destroy_fix() {
  destruct(this_object());
  write("You destroy your Quick Fix Object.\n");
return 1;
}
