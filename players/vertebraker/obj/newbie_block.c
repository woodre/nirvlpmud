/* for jello */

string *dd;
reset(x) {
  if(x || root()) return;
/*
  call_out("update_exits", 1);
This really doesn't need to be calling out - earwax */
}

update_exits() {
  if(!environment()) return;
  dd = environment(this_object())->query_dest_dir();
/*
  call_out("update_exits", 60);
*/
}

init() {
  int x, y;
  if(!dd) return;
  y = sizeof(dd);
  for(x=0;x<y;x++) {
    add_action("da_move", dd[x]);
  }
}

da_move(str) {
  if(query_verb() == "up") return 0;
  if((int)this_player()->query_level() < 8) {
    write("Mizan's area is best explored at a higher level.\n");
    return 1;
  }
}
