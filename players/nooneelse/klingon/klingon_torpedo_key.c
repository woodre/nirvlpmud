/*
 klingon_torpedo_key.c
*/

inherit "obj/treasure";

reset(arg) {
  if (arg) return;

  set_short("A green steel rod");
  set_long("A 4mm green steel rod, with a diameter of 1/2mm.\n");
  set_value(25);
  set_weight(1);
}

id(str) { return (str=="rod" ||
                  str=="klingon torpedo key" ||
                  str=="klingon_torpedo_key"); }
