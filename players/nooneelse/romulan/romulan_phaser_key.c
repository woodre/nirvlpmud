/*
 romulan_phaser_key.c
*/

inherit "obj/treasure";

reset(arg) {
  if (arg) return;

  set_short("A blue silicone disc");
  set_long("A small blue silicone disc.\n");
  set_value(25);
  set_weight(1);
}

id(str) { return (str=="disc" ||
                  str=="romulan phaser key" ||
                  str=="romulan_phaser_key"); }
