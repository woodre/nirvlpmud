/*
 d_sword.c - an example of using the new decaying weapon.c
*/

inherit "/players/nooneelse/obj/weapon";

reset(arg) {
  ::reset(arg);

  set_name("broadsword");
  set_alt_name("sword");
  set_class(15);
  set_weight(4);
  set_value(2000);
  set_short("a broadsword");
  set_long("It is a shining broadsword.\n");
  set_hit_func(this_object());
}

weapon_hit(attacker) {
  if (random(100) < 10) {
    write("The broadsword's keen edge bites deep.\n");
    return 7;
  }
  return;
}
