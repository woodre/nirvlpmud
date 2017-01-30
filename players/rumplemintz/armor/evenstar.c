inherit "/obj/armor.c";

void reset(status arg) {
  if(arg) return;
  ::reset(arg);
  set_name("evenstar pendant");
  set_alias("pendant");
  set_short("Evenstar Pendant");
  set_long("\
    Given to Aragorn by Arwen as a reminder of their love, It's crafted \n\
    in beautiful mithril alloyed with unknown other Elven materials. \n\
    \n");
  set_type("amulet");
  set_ac(2);
  set_weight(1);
  set_value(5000);
}
