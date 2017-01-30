/*
  scroll_create_wall.c - scroll to create a wall to temporarily block
                         a direction
                       - the read/activation mechanism was inspired by boltar's
                         scrolls on nirvana
*/

int scroll_value;

init() {
  add_action("read",     "read");
  add_action("read",     "examine");
  add_action("activate", "activate");
}

read(str) {
  if (!str || !id(str)) return;
  long();
  return 1;
}

activate(str) {
  object obj;
  string block_direction, wall_description;
  if (!str) return 0;
  block_direction=0;
  wall_description=0;
  sscanf(str, "%s wall %s", block_direction, wall_description);
  if (!block_direction) {
    write("You must supply the direction to block.\n");
    return 1;
  }
  if (!wall_description) {
    write("You must supply the description of the wall.\n");
    return 1;
  }
  obj=clone_object("/players/nooneelse/closed/magic_shop/roadblock");
  obj->set_owner(this_player()->query_real_name());
  obj->set_direction(block_direction);
  obj->set_wall_description(wall_description);
  move_object(obj, environment(this_player()));
  write("The scroll begins to glow, then crumbles to dust.\n"+
        "The dust swirls out of your hands and begins to glow brightly.\n"+
        capitalize(wall_description)+" suddenly appears.\n");
  say(this_player()->query_name()+" reads from a scroll.  It starts to glow\n"+
      "then crumbles into dust.\n"+
      "The dust swirls out of "+this_player()->query_possessive()+
      " hands and begins to glow brightly.\n"+
        capitalize(wall_description)+" suddenly appears.\n", this_player());
  destruct(this_object());
  return 1;
}

reset(arg) { return; }

query_save_flag() { return 1; }

short() {
  return "A wall creating scroll";
}

long() {
  write(short()+".\n"+
        "You can't make out most of the words, but you do see\n"+
        "that, it will create a wall to block an exit temporarily.\n\n"+
        "To activate it, type:\n"+
        "   activate <direction> wall <wall description>\n\n"+
        "   ex:  activate east wall A solid wall of transparent ice\n"+
        "   or   activate portal wall A massive granite boulder\n");
  return 1;
}

query_value() { return scroll_value; }
query_weight() { return 1; }

set_scroll_value(arg) { scroll_value=arg; }

get() { return 1; }
drop() { return 0; }

id(str) {
  return str=="scroll" ||
         str=="create wall scroll" ||
         str=="create wall";
}
