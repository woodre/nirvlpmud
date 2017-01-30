/*
 klingon_disrupter.c
*/

inherit "obj/weapon";

reset(arg) {
  if (arg) return;
  ::reset(arg);

  set_name("klingon disrupter");
  set_alt_name("disrupter");
  set_short("Klingon disrupter");
  set_long("A Klingon disrupter, capable of doing massive damage.\n");
  set_class(18);
  set_weight(3);
  set_value(4000);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  if (random(100) < 30) {
    write("The disrupter's bolt strikes a vital spot!\n");
    return 7;
  }
  return;
}
