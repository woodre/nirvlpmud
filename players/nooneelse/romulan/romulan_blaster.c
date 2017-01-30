/*
 romulan_blaster.c
*/

inherit "obj/weapon";

reset(arg) {
  if (arg) return;
  ::reset(arg);

  set_name("romulan blaster");
  set_alt_name("blaster");
  set_short("Romulan Blaster");
  set_long("A Romulan blaster, capable of doing serious damage.\n");
  set_class(16);
  set_weight(3);
  set_value(2000);
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  if (random(100) < 20) {
    write("The blaster's bolt strikes a vital spot!\n");
    return 6;
  }
  return;
}
