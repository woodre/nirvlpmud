inherit "/obj/armor.c";

void reset(int arg) {
  if(arg) return;
  set_name("padded");
  set_alias("armor");
  set_short("Padded armor");
 set_long(
    "This is a thickly padded leather vest which can provide some, but not\n"+
    "much protection.\n");
  set_ac(1); /* Something has to be! */
  set_type("armor");
  set_weight(1);
  set_value(100);
}
