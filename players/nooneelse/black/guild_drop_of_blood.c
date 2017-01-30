/*
  guild_drop_of_blood.c - quest item for penance in the guild
*/

inherit "obj/treasure";

string who, str;

reset(arg) {
  set_short("A drop of dark red blood");
  set_long("This is a drop of the Master's blood.\n");
  set_value(0);
  set_weight(0);
}

init() {
  add_action("drop",  "drop");
  add_action("quit",  "quit");
}

drop(str) {
  if (id(str) || str=="all") {
    write("As you drop the Master's blood, it disintegrates.\n");
    say("As "+this_player()->query_name()+
        " releases a drop of blood, it disintegrates.\n", this_player());
    destruct(this_object());
    if (str=="drop") return 1;
  }
}

quit(str) {
  drop("drop");
  return;
}

id(str) {
  return str=="guild drop of blood" ||
         str=="drop of blood" ||
         str=="blood" ||
         str=="drop";
}
