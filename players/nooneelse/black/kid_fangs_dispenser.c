/*
  kid_fangs_dispenser.c - a dispenser for vamps to get fangs for their kids
*/

inherit "obj/treasure";

reset(arg) {
  if (arg) return;

  set_short("A dispenser");
  set_long(
    "This dispenser will let you get some pretend fangs for your kids.\n"+
    "Use:  dispense fangs <kid name>\n");
  set_weight(666);
  set_value(0);
}

get() { return 0; }

id(str) { return str=="dispenser"; }


init() {
  add_action("dispense_fangs", "dispense");
}

dispense_fangs(str) {
  string kid_name;
  object kid_obj;
  if (!str) return 0;
  kid_name=0;
  sscanf(str, "fangs %s", kid_name);
  if (!kid_name) {
    write("Use:  dispense fangs <kid name>\n");
    return 1;
  }
  kid_obj=present(lower_case(kid_name), environment(this_object()));
  if (!kid_obj) {
    write(capitalize(kid_name)+" isn't here.\n");
    return 1;
  }
  if (!kid_obj->is_kid() && !kid_obj->am_i_a_servant()) {
    write("These are only for vampire's kids, wolves and servants.\n");
    return 1;
  }
  move_object(clone_object("/players/nooneelse/black/kid_fangs"), kid_obj);
  write(capitalize(kid_name)+" now has some fangs.\n");
  return 1;
}
