inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("gloves");
  set_short("A pair of leather gloves");
  set_long(
    " A fine pair of leather gloves that give ample protection\n"+
    "to the wearer.\n");
  set_type("ring");
  set_ac(1);
  set_weight(1);
  set_value(750);
}
