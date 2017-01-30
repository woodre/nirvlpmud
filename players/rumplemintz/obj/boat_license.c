inherit "/players/rumplemintz/basic/item";

void configure() {
  item::configure();
  set_id(({ "license", "boat_license" }));
  set_short("A Boat License");
  set_long("A license to drive a boat.\n");
}
