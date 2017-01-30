inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("tie");
  set_short("Bow Tie");
  set_long(
  "  A small purple bow tie with little yellow\n"+
  "pokadots on it.\n");
  set_type("amulet");
  set_ac(1);
  set_weight(1);
  set_value(50);
}
