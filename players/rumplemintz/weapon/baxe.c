inherit "obj/weapon";

void reset(status arg) {
  ::reset(arg);
  if(arg)
    return;
  set_alias("axe");
  set_short("A Bloody Axe");
  set_long("An axe with the blood of many battles on it.\n");
  set_class(10);
  set_weight(3);
  set_value(800);
  set_name("A Bloody Axe");
  set_hit_func(this_object());
}

int weapon_hit(object attacker) {
  if (random(10) > 5) {
    say(this_player()->query_name() +
        "'s axe strikes and stains itself with more blood.\n");
    write("You hit hard with your axe and stain it some more!\n");
    return 2;
  }
  return 0;
}
