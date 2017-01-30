inherit "/obj/armor";

void reset(int arg){
  if(arg) return;
  ::reset(arg);
  set_name("shield");
  set_short("Rump's Shield");
  set_long("Rump's personal shield.\n");
  set_ac(2);
  set_params("other|good", 2, 90, 0);
  set_type("shield");
  set_weight(1);
  set_value(100);
}
