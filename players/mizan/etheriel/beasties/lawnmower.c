id(str) { return str == "lawnmower"; }
short() { return "A sputtering lawnmower"; }
long() {
  write("This is a cheaply made piece of junk, which appears to be on the\n"+
        "verge of total and utter breakdown.\n");
}

can_put_and_get() { return 1; }

reset() {
  move_object(clone_object("players/mizan/etheriel/heals/dirtbag"), this_object());
}

  init() {
if(this_player()->is_player())
  call_out("nukeme", 10);
  }
nukeme() {
  if(environment())
  tell_room(environment(this_object()),
  "A sputtering lawnmower is blown to bits.\n");
  destruct(this_object());
}

