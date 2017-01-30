inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("mittens");
  set_alias("gloves");          
  set_short("Fuzzy Mittens");
  set_long(
  "  A very stylish pair of knit mittens with little\n"+
  "balls of lint stuck to them.\n");
  set_type("gloves");
  set_ac(1);
  set_weight(1);
  set_value(50);
}
