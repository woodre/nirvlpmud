id(str) { return str == "knifescar" || str == "palm" || str == "bloodpalm"; }

extra_look() { return "A Small Scar on the Palm"; }

long() { write("A wound on the palm: a pact\n");
    write("To induct another: blood_bind <player>\n"); }

query_auto_load() { return "/players/mythos/closed/guild/blood_bind.c:"; }

init() {
  add_action("blood_bind","blood_bind");
}

blood_bind(str) {
object targ;
if(!str) return;
  targ = find_player(str);
  if(!targ) { write("That player is not on.\n"); return 1; }
  if(targ->query_invis()) { write("That player is not on.\n"); return 1; }
  if(targ->query_level() > 19) { 
    write("This is a player thing not a wiz thing.\n");
  return 1; }
  if(present("bloodpalm",targ)) {
    write("Already blood bond.\n");
  return 1; }
  move_object(clone_object("/players/mythos/closed/guild/blood_bind.c"),targ);
  targ->save_me();
  write("A VOICE speaks: The pact has been made.\n");
  tell_object(targ,"A VOICE speaks: The pact has been made.\n");
return 1; }
