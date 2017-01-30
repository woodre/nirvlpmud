inherit "/obj/armor";

void reset(int arg){
  if(arg) return;
  ::reset(arg);
  set_name("cloak");
  set_short("Rump's Cloak");
  set_long("Rump's personal cloak.\n");
  set_ac(2);
  set_params("other|water", 2, 90, 0);
  set_type("cloak");
  set_weight(1);
  set_value(100);
}
