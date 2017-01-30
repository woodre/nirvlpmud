/* nighteye.c: night goggles */
inherit "obj/armor";
reset(arg) {
  if(arg)
    return ;
  ::reset(arg);
  set_name("eyes");
  set_alias("night eyes");
  set_short("A pair of night eyes");
  set_long("A small set of goggle-like eyes, which you could probably wear.\n"
          +"Though these probably would not do much in terms of protection, they would\n"
          +"definitely provide night vision, for a price.\n"
          +"Type \"eyes <look>\" to do something in the dark.\n");
  set_ac(1);
  set_weight(1);
  set_type("helmet");
  set_value(2500);
}
id(str) { return str == "eyes" || str == "night eyes" || str == "goggles"; }
init() {
  ::init();
  add_action("wear_me", "wear");
  add_action("night_look", "eyes");
}
wear_me(str) {
  if(id(str))
    write("You strap the eyes over your head.\n");
  return 0;
}
night_look(str) {
  if(!str) {
    write("Type \"eyes <look>\" to do something in the dark.\n");
    return 1;
  }
  if(set_light(0)) {
    write("It is already light here.\n");
    return 1;
  }
  if(this_player()->query_hp() <= 15) {
    write("You lack the hit points.\n");
    return 1;
  }
  if(!this_object()->query_worn()) {
    write("You must be wearing the eyes first.\n");
    return 1;
  }
  this_player()->add_hit_point(-15);
  write("You concentrate, and the area near you becomes clearer.\n");
  set_light(1);
  command(str, this_player());
  set_light(-1);
  return 1;
}
