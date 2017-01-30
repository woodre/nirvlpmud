id(str) { return str == "enter"; }
init() { add_action("enter","enter"); }
get() { return 1; }
drop() { return 0; }
reset() {}
short() { return "an enter"; }
enter(string str) {
  if(present(str, environment(this_player()))) {
    move_object(this_player(),
    present(str, environment(this_player())));
    write("done.\n");
    return 1;
    }
   write(str+" not here.\n");
   return 1; }
