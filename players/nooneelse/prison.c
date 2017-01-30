/*
 prison.c
*/

short() { return "The prison of Nooneelse"; }

long() {
  write("You are in Nooneelse's prison.\n");
  write("There are no exits.\n");
}

reset(arg) {
  if (arg) return;

  set_light(1);
}

init() {
  add_action("quit",  "quit");
  add_action("shout", "shout");
  add_action("tell",  "tell");
}

quit() {
  write("You're not getting out that way!\n");
  return 1;
}

shout() {
  write("Shout all you want.  Noone will hear you.\n");
  return 1;
}

tell() {
  write("No, You're not telling anyone!\n");
  return 1;
}
