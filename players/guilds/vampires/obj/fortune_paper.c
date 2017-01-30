/*
 fortune_paper.c
*/

/*
 This is a fortune from the fortune cookie
*/

inherit "obj/treasure";

string message, str;

init() {
  ::init();

  add_action("read", "read");
}

read(str) {
  if (!str) return;
  if (str!="paper" && str!="fortune") return;
  command("look at paper", this_player());
  return 1;
}

reset(arg) {
  if (arg) return;

  set_short("A small slip of paper");
  set_long("A small slip of paper.\n");
  set_value(1);
  set_weight(1);
}

long() {
  write("A small slip of paper.  It says:\n   "+message+"\n\n");
}

set_message(str) { message = str; }

id(str) { return (str=="paper" || str=="fortune"); }
