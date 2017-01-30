/* Interesting test device to check out weapons. */
id(str) { return str == "wepset"; }

init() {
  if(this_player()->query_level() > 99) add_action("wepset","wepset"); }

wepset(str) {
  object ob;
  if(!str) { write("Wepset <who>.\n"); return 1; }
  if(!read_file("/players/mythos/closed/guild/room/backup/"+str+".o")) {
    write("No weapon on file.\n"); return 1; }
  ob = clone_object("/players/mythos/closed/guild/spells/dwep.c");
  ob->restore_thing("players/mythos/closed/guild/room/backup/"+str);
  move_object(ob, this_player());
  write("Completed.\n"); return 1; }
