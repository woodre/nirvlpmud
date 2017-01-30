/*
  confetti_mortar.c - inspired by boltar's nerfgun on nirvana
*/

inherit "/obj/weapon";

init() {
  ::init();

  add_action("fire",   "fire");
}

fire(str) {
  object target_obj;
  string target_name;
  target_name=0;
  sscanf(str, "mortar at %s", target_name);
  if (!str || !target_name) return 0;
  target_obj = find_living(target_name);
  if (!target_obj || target_obj==this_player()) {
    write("You look down the barrel of your mortar and blast yourself "+
          "in the forehead!!!\n");
    say(this_player()->query_name()+
        " looks down the barrel of a mortar and gets blasted in the forehead\n",
        this_player());
    move_object(clone_object("players/nooneelse/obj/confetti"), target_obj);
    move_object(clone_object("players/nooneelse/obj/confetti"),
                environment(target_obj));
    return 1;
  }
  if (target_obj->query_level() > 20 &&
      this_player()->query_real_name() != "nooneelse") {
    write("Are you nuts???  You think better of it and blast "+
          "yourself instead.\n\n");
    fire("mortar at "+this_player()->query_real_name());
    return 1;
  }
  write("Whomp!  You fire the mortar and proceed to blow "+
        capitalize(target_name)+" away!!!\n"+
        "You hear a yelp of pain as you see the shell strike your target"+
        " on top the head\n"+
        "and confetti explode everywhere.\n");
  tell_room(environment(target_obj),
    "\nWhomp!  A mortar shell lands on top of "+capitalize(target_name)+
    "'s head\n"+
    " and showers confetti everywhere.\n\n"+
    "As the barrage stops, you can barely make out "+
    this_player()->query_name()+"'s gleeful laughter\n"+
    "and "+capitalize(target_name)+"'s whimpering.\n\n");
  move_object(clone_object("players/nooneelse/obj/confetti"), target_obj);
  move_object(clone_object("players/nooneelse/obj/confetti"),
              environment(target_obj));
  return 1;
}

reset() {
  set_alias("mortar");
  set_name("confetti mortar");
  set_short("Confetti mortar");
  set_long(
  "This is a deadly mortar!  However, someone has converted it to fire\n"+
  "confetti bombs.\n"+
  "    fire mortar at <who>     - to shoot other players at a distance\n"+
  "\n  A small label says: Made by Nooneelse's Doodads Inc.\n");
  set_value(200);
  set_class(8);
  set_weight(2);
}
