/*
  sign_note_office.c
*/

inherit "room/room";

string text;
object note_writer_obj, sign_maker_obj, note, sign, who_obj;

init() {
  ::init();

  add_action("read",      "read");
  add_action("write_note", "write");
  add_action("make_sign",  "make");
}

read(str) {
  if (str != "sign") return;
  command("look at sign", this_player());
  say(this_player()->query_name()+" reads the sign.\n");
  return 1;
}

write_note(str) {
  if (str!="note") return;
  if (this_player()->query_money() < 5) {
    write("The clerk says: You don't have enough money.\n");
    return 1;
  }
  if (note_writer_obj && environment(note_writer_obj)==this_object()) {
    write("Please wait, "+note_writer_obj->query_name()+
          " is already busy writing a note.\n");
    return 1;
  }
  note_writer_obj=this_player();
  text="";
  note=clone_object("players/nooneelse/obj/note");
  input_to("note_input");
  write("The clerk fetches a piece of paper.\n"+
        "He says:  Enter your message, finish with '**', abort with '~q'\n"+
        "-");
  return 1;
}

note_input(str) {
  if (str=="~q") {
    write("The clerk crumbles the piece of paper and throws it away.\n");
    note_writer_obj=0;
    return 1;
  }
  if (str=="**")  {
    tell_object(note_writer_obj,
                "The clerk says:  If you want to address the note to a player,"+
                " enter the name.\n");
    input_to("get_dest");
    write("-");
    return 1;
  }
  text=text+str+"\n";
  tell_object(note_writer_obj, "-");
  input_to("note_input");
  return 1;
}

get_dest(str) {
  if (str != "") note->set_owner(str);
  finish_note();
}

finish_note() {
  note->set_message(text);
  if (transfer(note, note_writer_obj)) {
    tell_object(note_writer_obj,
                "The clerk says: You can't carry more!\n"+
                "He crumbles the note and throws it away.\n");
    return 1;
  }
  tell_object(note_writer_obj, "The clerk hands you the note.\n");
  this_player()->add_money(-5);
  for (who_obj=first_inventory(this_object());
       who_obj;
       who_obj=next_inventory(who_obj))
    if (who_obj != note_writer_obj)
      tell_object(who_obj,
                  "The clerk hands "+note_writer_obj->query_name()+
                  " a note.\n");
  note_writer_obj=0;
  return 1;
}

make_sign(str) {
  if (str!="sign") return;
  if (this_player()->query_money() < 50) {
    write("The clerk says: You don't have enough money.\n");
    return 1;
  }
  if (sign_maker_obj && environment(sign_maker_obj)==this_object()) {
    write(sign_maker_obj->query_name()+" is already busy making a sign.\n");
    return 1;
  }
  sign_maker_obj=this_player();

  write("The clerk fetches a small board.\n"+
        "He says:  Enter a one line message, abort with '~q'\n"+
        "-");
  input_to("get_message");
  return 1;
}

get_message(str) {
  if (str=="" || str=="~q") {
    tell_object(sign_maker_obj,
                "The clerk says:  Ok, don't make a sign then.\n");
    sign_maker_obj=0;
    return 1;
  }
  sign=clone_object("players/nooneelse/obj/sign");
  sign->set_message(str);
  sign->set_owner(sign_maker_obj->query_real_name());
  if (transfer(sign, sign_maker_obj)) {
    write("The clerk says: You cannot carry more.\n"+
          "He breaks the sign in two and throws it away.\n");
    return 1;
  }
  sign_maker_obj->add_money(-50);
  tell_object(sign_maker_obj, "The clerk hands you the sign.\n");
  for (who_obj=first_inventory(this_object());
       who_obj;
       who_obj=next_inventory(who_obj))
    if (who_obj!=sign_maker_obj)
      tell_object(who_obj,
                  "The clerks hands "+sign_maker_obj->query_name()+
                  " a sign.\n");
  sign_maker_obj=0;
  return 1;
}

reset(arg) {
  if (arg) return;

  set_light(1);
  no_castle_flag=1;
  short_desc = "Sign Making/Note Writing Office";
  long_desc = short_desc+"\n"+
              "Behind a counter sits a clerk.  On the counter, next to the\n"+
              "clerk, there is a sign.\n";
  items = ({
            "clerk", "He peers at you in a friendly manner, through "+
                     "tiny glasses",
            "sign", "You can 'write note' or 'make sign' here.\n"+
                    "  notes: 5 coins\n"+
                    "  signs: 50 coins\n",
          });
  dest_dir =  ({
  "/players/eurale/VAMPIRES/RMS/souvenir_shop.c","south",
              });
}
