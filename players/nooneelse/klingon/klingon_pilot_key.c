/*
 klingon_pilot_key.c
*/

inherit "obj/treasure";

reset(arg) {
  if (arg) return;

  set_short("An orange steel rod");
  set_long("A 4mm orange steel rod, with a diameter of 1/2mm.\n");
  set_value(25);
  set_weight(1);
}

id(str) { return (str=="rod" ||
                  str=="klingon pilot key" ||
                  str=="klingon_pilot_key"); }
