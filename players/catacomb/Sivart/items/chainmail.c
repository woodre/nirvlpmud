inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("chainmail");
  set_short("A suit of Durkor chainmail");
  set_long(
     " A fine suit of connected chainlinks that provide protection\n"+
     "from attacks.\n");
  set_type("armor");
  set_ac(3);
  set_weight(4);
  set_value(2000);
}
