inherit "/obj/armor";

void reset(int arg){
  if(arg) return;
  ::reset(arg);
  set_name("gauntlets");
  set_short("Rump's Gauntlets");
  set_long("Rump's personal gauntlets.\n");
  set_ac(2);
  set_params("other|fire", 2, 90, 0);
  set_type("gloves");
  set_weight(1);
  set_value(100);
}
