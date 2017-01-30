id(str) { return str == "rshadset"; }

init() { if(this_player()->query_level() > 50) {
  add_action("set_rshad","rshad");
  add_action("unset_rshad","unrshad");
  }}

set_rshad(str) {
  object ob;
  object sob;
  if(!str) { write("rshad <player> or rshad <filename>\n"); return 1; }
  if(find_player(str)) {
    ob = environment(find_player(str));
    }
  if(!ob) ob = find_object(str);
  if(!ob) { write("Cannot find "+str+" to shadow.\n"); return 1; }
  write("Room set to "+file_name(ob)+"\n");
  sob = clone_object("/players/snow/closed/rshad");
  sob->set_room_shadow(ob);
  write("Room shadow going on "+file_name(ob)+".\n");
  return 1; }

unset_rshad(str) {
  object ob;
  if(!str) { write("Unset rshad on what <player> or <file>?\n"); return 1; }
  if(find_player(str)) ob = environment(find_player(str));
  if(!ob) ob = find_object(str);
  if(!ob) { write("Could not find "+str+" to unset rshad.\n"); return 1; }
  ob->stop_room_shadow(ob);
  write("Room shadow stopped on "+file_name(ob)+".\n");
  return 1; }
