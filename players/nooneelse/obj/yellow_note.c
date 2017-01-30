/*
  note.c
*/

inherit "obj/treasure";

string note_writer_name;
int note_nbr;

init() {
  ::init();

  add_action("read",      "read");
  add_action("read",      "examine");
  add_action("burn_note", "burn");
}

read(str) {
  if (str != "note") return;
  say(this_player()->query_name()+" reads a note.\n");
  long();
  return 1;
}

burn_note(str) {
  if (!str || !id(str)) return;
  write("The note flares up and disappears like it was made of flashpaper.\n");
  say(this_player()->query_name()+" burns a piece of paper which flares up\n"+
      "and disappears like it was made of flashpaper.\n", this_player());
  destruct(this_object());
  return 1;
}


reset(arg) {
  set_short("A note");
  set_long("This is a note.  It says: I am a note! :)\n\n"+
           "   To get rid of it, type 'burn note'\n");
  set_value(0);
  set_weight(0);
  call_out("destruct_this_note", 3600);
}

destruct_this_note() {
  destruct(this_object());
  return 1;
}

set_message(str) {
  set_short("A note from "+capitalize(note_writer_name));
  set_long("This is note # "+note_nbr+" from "+capitalize(note_writer_name)+
           ".  Written at "+ctime(time())+".\n\n"+
           capitalize(str)+"\n\n"+
           "   To get rid of it, type 'burn note'\n");
}

set_writer(str) { note_writer_name=str; }

set_note_nbr(arg) { note_nbr=arg; }

id(arg) { return arg=="note"; }
