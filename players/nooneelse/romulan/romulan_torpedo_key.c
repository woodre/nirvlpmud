/*
 romulan_torpedo_key.c
*/

inherit "obj/treasure";

reset(arg) {
  if (arg) return;

  set_short("A red silicone disc");
  set_long("A small red silicone disc.\n");
  set_value(25);
  set_weight(1);
}

id(str) { return (str=="disc" ||
                  str=="romulan torpedo key" ||
                  str=="romulan_torpedo_key"); }
