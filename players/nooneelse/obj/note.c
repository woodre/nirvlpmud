/*
  note.c
*/

inherit "obj/treasure";

string note_owner_name;

init() {
  ::init();

  add_action("read", "read");
}

read(str) {
  if (str != "note") return;
  say(this_player()->query_name()+" reads a note.\n");
  long();
  return 1;
}

reset(arg) {
  set_short("A note");
  set_long("This is a note.  It says: I am a note! :)\n");
  set_value(0);
  set_weight(1);
  call_out("destruct_this", 1000);
}

destruct_this() {
  tell_object(environment(this_object()),"The note crumbles to dust.\n");
  destruct(this_object());
}

set_message(str) { set_long(str); }

get() { return (this_player()->query_real_name()==note_owner_name ||
                this_player()->query_level() > 20); }

set_owner(str) { note_owner_name=str; }

id(arg) { return arg=="note"; }
