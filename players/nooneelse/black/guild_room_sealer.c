/*
 cult_room_sealer.c - temporarily block off a direction
*/

string owner_name, str, direction_str;

short() {
  return "A shimmering red light blocks your way to the "+direction_str;
}

long() {
  write(short()+".\n");
  if (this_player()->query_level() > 20)
    write("As a wizard, you can remove it with 'remove block'.\n");
  else
  if (lower_case(this_player()->query_real_name())==owner_name)
    write("As the owner, you can remove it with 'remove block'.\n");
}

init() {
  add_action("block_exit",   direction_str);
  add_action("remove_block", "remove");
}

block_exit(str) {
  if (lower_case(this_player()->query_real_name())==owner_name ||
      this_player()->query_level() > 20) return;
  write("The light flares!  The intensity prevents you from continuing.\n");
  say(this_player()->query_name()+" tries to go "+direction_str+
      " but the light flares and stops "+this_player()->query_objective()+
      ".\n");
  return 1;
}

remove_block(str) {
  if (!str || !str=="block") return;
  if (lower_case(this_player()->query_real_name())==owner_name ||
      this_player()->query_level() > 20) {
    say(capitalize(this_player()->query_name())+
        " mumbles a strange phrase and the shimmering red light disappears.\n");
    write("You mumble a strange phrase and the shimmering "+
          "red light disappears.\n");
    destruct(this_object());
    return 1;
  }
}

reset(arg) {
  if (arg) return;

  direction_str="out";
}

get() { return; }

set_owner(str) { owner_name=str; }

set_direction(str) {
  direction_str = str;
  return 1;
}

id(str) { return str=="shimmering light" ||
                 str=="red light" ||
                 str=="light" ||
                 str=="block"; }
