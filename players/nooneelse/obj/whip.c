/*
 whip.c
*/

inherit "obj/weapon";

object whip;

reset(arg) {
  ::reset(arg);

  set_name("whip");
  set_class(15);
  set_weight(4);
  set_value(2000);
  set_short("a whip tail");
  set_long(
    "It appears to be the tail of a scorpion, with the stinger intact.\n");
  set_hit_func(this_object());
}


weapon_hit(attacker) {
  if (random(100) < 10) {
    write("Scorpion's venom drips into the open wound.\n");
    return 15;
  }
  return;
}

id(str) {
  return (str=="whip" || str=="tail" || str=="whip tail");
}
