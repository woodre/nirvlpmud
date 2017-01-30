/*
  sign.c
*/

inherit "obj/treasure";

string sign_owner_name;

init() {
  ::init();

  add_action("read", "read");
}

read(str) {
  if (str != "sign") return;
  say(this_player()->query_name()+" reads a sign.\n");
  long();
  return 1;
}

reset(arg) {
  set_short("A sign");
  set_long("This is a sign.  It says: I am a sign! :)\n");
  set_value(0);
  set_weight(5);
  call_out("destruct_this", 15000);
}

destruct_this() {
  tell_object(environment(this_object()),"The sign crumbles to dust.\n");
  destruct(this_object());
}

set_message(str) { set_long(str+"\n"); }

set_owner(str) { sign_owner_name=str; }

get() { return (this_player()->query_real_name()==sign_owner_name ||
                this_player()->query_level() > 20); }

id(arg) { return arg=="sign"; }
