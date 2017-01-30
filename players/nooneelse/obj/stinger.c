/*
 stinger.c
*/

inherit "obj/weapon";

object stinger;

reset(arg) {
  ::reset(arg);

  set_name("stinger");
  set_class(12);
  set_weight(3);
  set_value(500);
  set_short("A reptile's stinger");
  set_long("It appears to be the stinger of a large reptile.\n");
  set_hit_func(this_object());
}


weapon_hit(attacker) {
  if (random(100) < 5) {
    write("Wyvern's venom drips into the open wound.\n");
    return 10;
  }
  return;
}

id(str) { return (str=="stinger"); }
