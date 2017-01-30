inherit "obj/weapon";

void reset(int arg) {
  ::reset(arg);
  if(arg)
    return;
  set_alias("mace");
  set_short("A Dangling Mace");
  set_long("A mace that goes 'woo woo' when you swing it.\n");
  set_class(10);
  set_weight(3);
  set_value(800);
  set_name("A Dangling Mace");
  set_hit_func(this_object());
}

int weapon_hit(object attacker) {
  if (random(10) > 5) {
    say(this_player()->query_name() +
        "'s mace strikes and and wacks off an arm.\n");
    write("You hit hard with your mace and wack off an arm!\n");
    return 1;
  }
  return 0;
}
