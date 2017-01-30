/*
 klingon_communicator.c
*/

inherit "obj/treasure";

string str, str1, str2;

init() {
  ::init();

  add_action("transport_me", "choy");
  add_action("forward",      "fo");
  add_action("aft",          "af");
  add_action("starboard",    "st");
  add_action("port",         "po");
}

transport_me(str) {
  object view_obj, old_room;
  string where_str;
  int sp_cost;
  if (!str || str != "chu") return;
  if (environment(this_player())->realm()=="NT") {
    tell_room(environment(this_player()),
              "The communicator beeps, but nothing happens.\n");
    return 1;
  }
  sp_cost = 55+random(5);
  if (this_player()->query_spell_point() < sp_cost) {
    tell_room(environment(this_player()),
              "The communicator beeps, but nothing happens.\n");
    return 1;
  }
  this_player()->add_spell_point(- sp_cost);
  call_other("/players/nooneelse/klingon/klingon_transporter", "???");
  view_obj=find_object("/players/nooneelse/klingon/klingon_transporter");
  old_room=environment(this_player());
  if (where_str = call_other("obj/base_tele","teleport")) {
    tell_room(where_str,
              "You hear a high-pitched electrical hum and see a sparkling\n"+
              "rainbow of color, which fades away to reveal "+
              capitalize(this_player()->query_name())+".\n");
    move_object(this_player(), where_str);
    tell_room(old_room,
        capitalize(this_player()->query_name())+
        " speaks into a small gray box,\n"+
        "saying something that sounds like:\n"+
        "   C'hoy C'hu!\n"+
        "You hear a high-pitched electrical hum and see a sparkling\n"+
        "rainbow of color surround "+capitalize(this_player()->query_name())+
        ", which fades away to\n"+
        "reveal that "+this_player()->query_pronoun()+" has disappeared.\n");
    write("You hear a high-pitched electrical hum and see a sparkling\n"+
          "rainbow of color envelope you.  Suddenly, you hear loud electrical\n"+
          "crackling and popping!  Something has gone wrong with the transport!\n"+
          "When the rainbow fades away, you see:\n\n");
    command("look", this_player());
    return 1;
  }
  tell_room(view_obj,
            "You hear a high-pitched electrical hum and see a sparkling\n"+
            "rainbow of color, which fades away to reveal "+
            capitalize(this_player()->query_name())+".\n");
  move_object(this_player(), view_obj);
  tell_room(old_room,
      capitalize(this_player()->query_name())+
      " speaks into a small gray box,\n"+
      "saying something that sounds like:\n"+
      "   C'hoy C'hu!\n"+
      "You hear a high-pitched electrical hum and see a sparkling\n"+
      "rainbow of color surround "+capitalize(this_player()->query_name())+
      ", which fades away to\n"+
      "reveal that "+this_player()->query_pronoun()+" has disappeared.\n");
  write("You hear a high-pitched electrical hum and see a sparkling\n"+
        "rainbow of color envelope you.  It fades away and you see:\n\n");
  command("look", this_player());
  return 1;
}

forward() {
  if (sscanf(file_name(environment(this_player())),
             "%sklingon%s", str1, str2)==2) {
    command("fore", this_player());
    return 1;
  }
}

aft() {
  if (sscanf(file_name(environment(this_player())),
             "%sklingon%s", str1, str2)==2) {
    command("aft", this_player());
    return 1;
  }
}

starboard() {
  if (sscanf(file_name(environment(this_player())),
             "%sklingon%s", str1, str2)==2) {
    command("starboard", this_player());
    return 1;
  }
}

port() {
  if (sscanf(file_name(environment(this_player())),
             "%sklingon%s", str1, str2)==2) {
    command("port", this_player());
    return 1;
  }
}

reset(arg) {
  if (arg) return;

  set_short("A dark gray metal box");
  set_value(225);
  set_weight(1);
}

long() {
  string str1, str2;
  write("A small, dark gray, metal box with a small built-in microphone.\n"+
        "On the side, in small letters are the words 'choy chu'.\n");
  if (sscanf(file_name(environment(this_player())),
             "%sklingon%s", str1, str2)==2)
    write(
      "\nWhile on the Klingon ship, the following abreviations will work:\n"+
      "    forward   = fo\n"+
      "    aft       = af\n"+
      "    starboard = st\n"+
      "    port      = po\n");
}

id(str) { return (str=="klingon communicator" ||
                  str=="communicator" ||
                  str=="box"); }
