inherit "obj/treasure";

int charges;


void reset(int arg) {
  set_id("cartridge");
  set_alias("poison cartridge");
  set_short("poison cartridge");
  set_long(
"A small vial filled with posion.\n"
  );
  set_weight(1);
  set_value(100);
  charges=12;
}
int reload() {
  destruct(this_object());
  this_player()->recalc_carry();
  return charges;
}
