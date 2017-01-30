/*
  raoadblock.c - temporarily block off a direction
*/

string owner_name, str, direction_str, wall_description;

init() {
  add_action("block_exit",   direction_str);
  add_action("remove_block", "remove");
}

block_exit(str) {
  if (lower_case(this_player()->query_real_name())==owner_name) {
    write("<<< As the owner of the wall, you can pass unharmed.\n");
    return 0;
  }
  if (this_player()->query_level() >= 21) {
    write("<<< As a wizard, you can pass unharmed.\n");
    return 0;
  }
  write(capitalize(wall_description)+" prevents you from continuing.\n");
  say(this_player()->query_name()+" tries to go "+direction_str+
      " but "+wall_description+"stops "+this_player()->query_objective()+
      ".\n", this_player());
  return 1;
}

remove_block(str) {
  if (!str || !str=="block") return;
  if (lower_case(this_player()->query_real_name())==owner_name ||
      this_player()->query_level() >= 21) {
    write("You mumble a strange phrase and "+wall_description+" disappears.\n");
    say(capitalize(this_player()->query_name())+
        " mumbles a strange phrase and "+wall_description+" disappears.\n",
        this_player());
    destruct(this_object());
    return 1;
  }
}

reset(arg) {
  if (arg) return;

  direction_str="out";
  call_out("destruct_this", 900);
}

get() { return; }

short() {
  return wall_description+" blocks your way to the "+direction_str;
}

long() {
  write(short()+".\n");
  if (this_player()->query_level() >= 21)
    write("As a wizard, you can remove it with 'remove block' "+
          "or walk thru it.\n");
  else
  if (lower_case(this_player()->query_real_name())==owner_name)
    write("As the owner, you can:\n"+
          "   walk right thru it, or\n"+
          "   remove it with 'remove block'.\n");
}

destruct_this() {
  if (find_player(owner_name)) {
    tell_object(find_player(owner_name),
                "Your "+wall_description+"'s time has run out & it's gone.\n");
  }
  tell_object(environment(this_object()),
              capitalize(wall_description)+" shimmers and disappears.\n");
  destruct(this_oject());
  return 1;
}

set_owner(str) { owner_name=str; }

set_direction(str) {
  direction_str = str;
  return 1;
}

set_wall_description(str) {
  wall_description = str;
  return 1;
}

id(str) { return str=="roadblock" || str=="wall" || str=="block"; }
