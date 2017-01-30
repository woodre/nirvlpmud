inherit "obj/monster";

int count;

reset(arg){
   if(arg) return 0;
   ::reset(arg);
   set_name("The street cleaner");
   set_alias("cleaner");
   set_short("A street cleaner");
   set_long(
"     This is a small magical tractor that rolls along and\n"+
"cleans the streets of Nirvana.\n");
   set_level(1);
   enable_commands();
   set_can_kill(0);
   set_aggressive(0);
}

id(str) { return str == "cleaner"; }

activate() {
  string * exits;
  int size, rand, i;
  object * inv;
  count += 1;
  if(count >= 1800) {
    write("The street cleaner runs out of gas and dies.\n");
    destruct(this_object());
    return 1; }       /* 30 min. of cleaning */
  inv = all_inventory(environment(this_object()));
  for( i = 0; i < sizeof( inv ); i++ ) {
    if(inv[i]->is_player() || inv[i]->is_pet() ||
       inv[i]->query_npc() || inv[i]->is_castle()) { }
    else {
       destruct(inv[i]);
       tell_room(environment(this_object()),
       "The street cleaner cleans up some trash.\n");
       }
  }
  this_object()->run_away();
  call_out("activate", 1);
  return 1;
}

catch_tell(string str) {
  string msg;
  if(sscanf(str,"activate%s",msg) || sscanf(str,"%sactivate%s",msg)
                               || sscanf(str,"%sactivate", msg)) {
    activate();
    return 1; }
  return 1;
}
