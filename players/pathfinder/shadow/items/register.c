#define TP this_player()
id(str) { return str == "noid"; }
 
init() {
  add_action("join_shadows", "join");
}
 
join_shadows(str) {
  object mark;
  if(!str || str != "shadows") {
    write("What are you trying to do!??!?!\n");
    return 1;
    }
  mark = clone_object("/players/pathfinder/closed/shadow/shadow.c");
  tell_object(TP,"You have just joined the Shadow Guild!\n");
  TP->set_guild_name("shadow");
  mark->guild_echo("<< "+capitalize(this_player()->query_real_name())+" >> has joined the Shadow Guild!\n");
  move_object(mark,TP);
  mark->save_me();
  destruct(this_object());
  return 1;
}
