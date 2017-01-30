/*
 klingon_security_key.c
*/

inherit "obj/treasure";

reset(arg) {
  if (arg) return;

  set_short("A red steel rod");
  set_long("A 4mm red steel rod, with a diameter of 1/2mm.\n");
  set_value(25);
  set_weight(1);
}

id(str) { return (str=="rod" ||
                  str=="klingon security key" ||
                  str=="klingon_security_key"); }
