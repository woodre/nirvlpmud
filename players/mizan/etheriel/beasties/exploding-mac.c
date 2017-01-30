id(str) { return str == "mac" || str == "computer" || str == "macintosh"; }
short() { return "A Macintosh computer (being used as a doorstop)"; }
long() {
  write("This is a Macintosh computer, which is being used as a doorstop.\n");
}

can_put_and_get() { return 1; }

reset() {
  if(1 == random(5)) {
  move_object(clone_object("players/mizan/etheriel/items/portable-panic-btn.c"), this_object());
  }
  if(1 == random(5)) { 
  move_object(clone_object("players/mizan/etheriel/heals/portable_cow"), this_object());
  }
}

init() {
   call_out("nuke_me",10);
}
nukeme() 
{
    if(environment(this_object()))
    tell_room(environment(this_object()),
    "A Macintosh computer being used as a doorstop is blown to bits.\n");
    destruct(this_object());
    return 1;
}

