inherit "/obj/armor";

void reset(int arg){
  if(arg) return;
  ::reset(arg);
  set_name("wedding");
  set_short("Rump's Wedding Ring");
  set_long("Rump's Wedding Ring.\n");
  set_ac(2);
  set_params("other|laser", 2, 90, 0);
  set_type("ring");
  set_weight(1);
  set_value(100);
}
