inherit "obj/weapon";

void reset(int arg) {
  ::reset(arg);
  if(arg)
    return;
  set_alias("sword");
  set_short("Bone Sword");
  set_long(\
"A Sword made entirely out of bone.  It is not very sharp, but will work.\n");
  set_class(10);
  set_weight(3);
  set_value(800);
  set_name("Bone Sword");
  set_hit_func(this_object());
}

int weapon_hit(object attacker) {
  if (random(10) > 5) {
    say(this_player()->query_name() +
        "'s sword strikes with a bone crushing sound, get it?\n");
    write(\
"Your sword hit's with a bone crushing sound, better make sure it didnt break.\n");
    return 2;
  }
  return 0;
}
