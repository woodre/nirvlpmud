/*
  confetti.c - what can i say.  i got bored!
*/

reset(arg) {
  if (arg) return;

  call_out("trash_this", 100);
}

trash_this() { destrutct(this_object()); }

short() { return "A sprinkling of confetti"; }

long() {
  write(short()+"!  It's a pile of small, milti-colored pieces of paper.\n");
}

id(str) { return str=="confetti"; }
