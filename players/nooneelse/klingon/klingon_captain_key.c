/*
 klingon_captain_key.c
*/

inherit "obj/treasure";

reset(arg) {
  if (arg) return;

  set_short("A black steel rod");
  set_long("A 4mm black steel rod, with a diameter of 1/2mm.\n");
  set_value(25);
  set_weight(1);
}

id(str) { return (str=="rod" ||
                  str=="klingon captain key" ||
                  str=="klingon_captain_key"); }
