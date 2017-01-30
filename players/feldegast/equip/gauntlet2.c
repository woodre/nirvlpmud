inherit "/obj/armor.c";

void reset(int arg) {
  if(arg) return;
  set_name("gauntlet");
  set_alias("gauntlets");
  set_short("Steel Gauntlets");
  set_long(
    "A pair of steel gauntlets.\n"
  );
  set_ac(1);
  set_type("ring");
  set_weight(2);
  set_value(800);
}
