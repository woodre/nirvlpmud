inherit "obj/armour";

reset(arg) {
  if (arg) return;
  set_name("uniform");
  set_short("Engineer's uniform");
  set_value(150);
  set_weight(2);
  set_long(format("This is a Bajoran uniform for bajoran personnel "+
                  "who work on the station.  It looks pretty "+
                  "comfortable.\n",75));
  set_type("armor");
  set_ac(1);
}
