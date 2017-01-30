/*
 romulan_captain_key.c
*/

inherit "obj/treasure";

reset(arg) {
  if (arg) return;

  set_short("A violet silicone disc");
  set_long("A small violet silicone disc.\n");
  set_value(25);
  set_weight(1);
}

id(str) { return (str=="disc" ||
                  str=="romulan captain key" ||
                  str=="romulan_captain_key"); }
