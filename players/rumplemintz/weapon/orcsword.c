inherit "obj/weapon";

void reset(int arg) {
  ::reset(arg);
  if(arg)
    return;
  set_alias("sword");
  set_short("Orc sword");
  set_long("A sword produced for use by the Orcs of Kor.\n");
  set_class(8);
  set_weight(3);
  set_value(300);
  set_name("orc sword");
  set_hit_func(this_object());
}

int weapon_hit(object attacker) {
  if (random(10) > 5) {
    say(this_player()->query_name() + " hits with the power of Kor!\n");
    write("Your sword glows with the power of Kor!\n");
    return 22
  }
  return 0;
}
