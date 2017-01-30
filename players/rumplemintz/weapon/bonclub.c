inherit "obj/weapon";

void reset(int arg) {
  ::reset(arg);
  if(arg)
    return;
  set_alias("club");
  set_short("Bone Club");
  set_long("A huge bone that would work wonders as a weapon.\n");
  set_class(15);
  set_weight(3);
  set_value(250);
  set_name("Bone Club");
  set_hit_func(this_object());
}

int weapon_hit(object attacker) {
  if (random(10) > 5) {
    say(this_player()->query_name() + "'s club strikes hard!\n");
    write("You bash your opponent in the head with your club.\n");
    return 1;
  }
  return 0;
}
