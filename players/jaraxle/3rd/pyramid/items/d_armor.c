
inherit "/obj/armor.c";
#include "/players/jaraxle/define.h"
void reset(int arg) {
  if(arg) return;
  set_name("egyptian plate");
  set_alias("plate");
  set_short("Egyptian Plate");
  set_long(
    "A lightweight suit of dark brown leather. Plates\n"+
    "of thin gold cover the shoulders and chest.\n"
  );
  set_ac(3);
  set_type("armor");
  set_weight(2);
  set_value(500+random(251));
}
