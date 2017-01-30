init() { add_action("goplace","enter"); }
id(str) { return str == "pavilion"; }
get() { return 0; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }
reset() { }
short() { return "RoboMech Pavilion"; }
long() { write(
"     RoboMech Pavilion is a massive black metal and glass\n"+
"pyramidal structure that towers above you, several stories high.\n"+
"Its purpose is for simulated strategic/action gaming.\n"+
"Type 'enter' to play!\n");
}

goplace() {
  say(capitalize(this_player()->query_name())+
      " enters RoboMech Pavilion.\n");
  write("You enter RoboMech Pavilion.\n\n");
  move_object(this_player(),
              "/players/dune/closed/pavilion/rooms/roboentry.c");
  command("look", this_player());
  return 1;
}

int is_castle() { return 1; }
