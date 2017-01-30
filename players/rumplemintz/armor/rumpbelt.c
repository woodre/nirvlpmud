inherit "/obj/armor";

void reset(int arg){
  if(arg) return;
  ::reset(arg);
  set_name("belt");
  set_short("Rump's Belt");
  set_long("Rump's personal belt.\n");
  set_ac(2);
  set_params("other|dark", 2, 90, 0);
  set_type("belt");
  set_weight(1);
  set_value(100);
}
