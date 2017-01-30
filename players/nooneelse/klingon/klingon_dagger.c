/*
 klingon_dagger.c
*/

inherit "obj/weapon";

reset(arg) {
  if (arg) return;
  ::reset(arg);

  set_name("klingon dagger");
  set_alt_name("dagger");
  set_short("Klingon dagger");
  set_long("A Klingon dagger with sharp spines running down the blade.\n");
  set_class(14);
  set_weight(3);
  set_value(1500);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  if (random(100) < 10) {
    write("The dagger's spines dig in as it is pulled out!\n");
    return 4;
  }
  return;
}
