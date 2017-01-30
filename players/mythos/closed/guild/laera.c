id(str) { return str == "dwep"; }

short() { return "dwep"; }
long() { write("Type 'dwep'\n"); }
init() {
  if(this_player()) if(this_player()->query_real_name() != "laera") { destruct(this_object()); return 1; }
  add_action("dwep","dwep");
}

dwep() {
  object ob;
  ob = clone_object("/players/mythos/closed/guild/spells/dwep.c");
  ob->restore_thing("players/mythos/closed/guild/room/backup/laera");
move_object(ob,this_player());
write("Laera's Sword of Lies has been created.\n");
destruct(this_object());
return 1; }
