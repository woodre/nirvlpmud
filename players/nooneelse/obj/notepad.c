/*
  notepad.c
*/

#define MAX_NBR_NOTES 21
#define PRICE_PER_PAGE 3

inherit "obj/treasure";

string note_writer_name;
int notepad_value, note_nbr, i;

init() {
  ::init();

  add_action("write_note", "write");
}

write_note(str) {
  object obj;
  if (!str) return;
  obj=clone_object("players/nooneelse/obj/yellow_note");
  obj->set_writer(lower_case(this_player()->query_name()));
  obj->set_note_nbr(note_nbr);
  obj->set_message(str);
  move_object(obj, this_player());
  note_nbr++;
  write("You scribble a quick note.\n");
  say(this_player()->query_name()+" writes a note.\n", this_player());
  if (note_nbr >= MAX_NBR_NOTES) {
    write("You have used the notepad up.\n");
    destruct(this_object());
  }
  return 1;
}

reset(arg) {
  if (arg) return;

  note_nbr=1;
  set_short("A notepad");
  set_weight(0);
}

long() {
  i = MAX_NBR_NOTES - note_nbr;
  write("This is a pad of "+i+" yellow sticky note paper(s).\n"+
        "Use it to leave temporary messages for someone.\n"+
        "(For instance, if they're linkdead & you have to take off.)\n"+
        "Use: write <msg> to write a note to someone, then\n"+
        "     give note to <whoever>\n");
}

query_value() { return (MAX_NBR_NOTES - note_nbr) * PRICE_PER_PAGE; }

id(str) { return str=="notepad" || str=="pad"; }
