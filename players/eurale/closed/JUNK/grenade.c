/*
  paint_grenade.c
*/

inherit "/obj/treasure";

int pin_pulled;

init() {
  ::init();

  add_action("pull_pin",      "pull");
  add_action("throw_grenade", "throw");
}

pull_pin(str) {
  if (!str || str != "pin") return 0;
  if (pin_pulled) {
    write("The pin has already been pulled.\n");
    return 1;
  }
  write("You pull the pin and release the handle.\n");
  say(this_player()->query_name()+" pulls a pin out of a spherical object.\n",
      this_player());
  pin_pulled=1;
  call_out("grenade_explode", 10);
  return 1;
}

throw_grenade(str) {
  object target_obj;
  string target_name;
  target_name=0;
  sscanf(str, "grenade at %s", target_name);
  if (!str || !target_name) return 0;
  target_obj = find_living(target_name);
  if (!target_obj || target_obj==this_player()) {
    write("You consider throwing your grenade but can't find a target.\n");
    return 1;
  }
  if (target_obj->query_level() > 20 &&
      this_player()->query_real_name() != "eurale") {
    write("Are you nuts???  You think better of it and hang on to it.\n\n");
    return 1;
  }
  write("You rear back and heave the grenade at "+target_name+".\n");
  say(this_player()->query_name()+
      " heaves a spherical object into the distance.\n",
      this_player());
  move_object(this_object(), target_obj);
  tell_object(target_obj,
              "\n\n"+this_player()->query_name()+
              " throws a grenade at you!\n\n");
  return 1;
}

grenade_explode() {
  object obj, paint_obj;
  string bucket_color;
  int random_nbr;
  random_nbr=random(5);
  if (random_nbr==0) bucket_color="red";
  if (random_nbr==1) bucket_color="yellow";
  if (random_nbr==2) bucket_color="blue";
  if (random_nbr==3) bucket_color="green";
  if (random_nbr==4) bucket_color="purple";
  /* cover player */
paint_obj = clone_object("players/eurale/closed/JUNK/bucket_stuff.c");
  paint_obj->start_bucket_stuff(random_nbr);
  move_object(paint_obj, environment(this_object()));
  /* cover everyone/everything else */
  obj = first_inventory(environment(environment(this_object())));
  while (obj) {
    paint_obj = clone_object("players/eurale/closed/JUNK/bucket_stuff.c");
    paint_obj->start_bucket_stuff(random_nbr);
    move_object(paint_obj, obj);
    obj=next_inventory(obj);
  }
  tell_room(environment(environment(this_object())),
    "\nWhomp!  A grenade explodes and splashes "+bucket_color+
    " paint everywhere.\n\n");
  destruct(this_object());
  return 1;
}

reset(arg) {
  if (arg) return 0;

  set_id("paint grenade");
  set_alias("grenade");
  set_short("paint grenade");
  set_value(0);
  set_weight(0);
  pin_pulled=0;
}

long() {
  write(
    "This is a deadly grenade!  However, someone has converted it to splatter"+
    " paint.\n");
  if (pin_pulled)
    write("    The pin has been removed!\n");
  else
    write("    pull pin                  - to activate the grenade\n");
  write("    throw grenade at <who>    - to throw the grenade "+
        "into <who>'s room\n"+
        "\n  A small label says: Made by Nooneelse's Doodads Inc.\n");
}
