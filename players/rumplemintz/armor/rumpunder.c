inherit "/obj/armor";

void reset(int arg){
  if(arg) return;
  ::reset(arg);
  set_name("boxers");
  set_short("Rump's Boxers");
  set_long("Rump's Boxers.\n");
  set_ac(2);
  set_params("other|sonic", 2, 90, 0);
  set_type("underwear");
  set_weight(1);
  set_value(100);
}
