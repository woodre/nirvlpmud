inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("hood");
  set_short("A chain mail hood");
  set_long(
   "  A hood made of interlinked chains.  Although it looks to be\n"+
   "thin and weak, it may provide some protection from attacks.\n");
  set_type("helmet");
  set_ac(1);
  set_weight(1);
  set_value(750);
}
