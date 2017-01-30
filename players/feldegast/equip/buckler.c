inherit "/obj/armor.c";

void reset(int arg) {
  set_name("buckler");
  set_alias("rounded buckler");
  set_short("A rounded buckler");
  set_long(
    "This is a simple shield made out of a layer of boiled leather over\n"+
    "a piece of hardwood with a pair of leather straps on the back.\n");
  set_ac(1);
  set_type("shield");
  set_weight(3);
  set_value(50);
}
