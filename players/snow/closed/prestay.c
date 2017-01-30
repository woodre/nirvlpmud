id() { return "prestay"; }
drop() { return 1; }
init() { add_action("send_me","sendto"); add_action("nope","pretitle"); }
send_me(str) {
  if(TP->query_level() < 100) return 0
  if(!str) { write("Sendto who?\n"); return 1; }
  if(!find_player(str)) { write("Not online.\n"); return 1; }
  move_object(this_object(), find_player(str));
  write("Done.\n"); return 1; }

nope() { return 1; }
