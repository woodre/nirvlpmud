inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("sandals");
  set_alias("shoes");          
  set_short("Sandals");
  set_long(
  "  These sandals are made from a tough leather with \n"+
  "with small leather straps and a few silver buckles.\n");
  set_type("boots");
  set_ac(1);
  set_weight(1);
  set_value(50);
}
