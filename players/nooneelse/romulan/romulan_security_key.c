/*
 romulan_security_key.c - key to captain's door
*/

inherit "obj/treasure";

reset(arg) {
  if (arg) return;

  set_short("A black silicone disc");
  set_long("A small black silicone disc.\n");
  set_value(25);
  set_weight(1);
}

id(str) { return (str=="disc" ||
                  str=="romulan security key" ||
                  str=="romulan_security_key"); }
