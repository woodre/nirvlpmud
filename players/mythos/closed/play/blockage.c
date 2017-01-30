object room;

start_block_shadow(where) {
room = where;
shadow(room, 1);
return 1;}

stop_shadow_me() {
shadow(room, 0);
return 1;}

exit() {
  if(this_player()->query_real_name() != "mythos" &&
     this_player()->id("lilith") &&
     this_player()->query_real_name() != "meshitsukai" &&
     this_player()->query_real_name() != "priest") return 1;
  stop_shadow_me();
}
