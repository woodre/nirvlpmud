inherit "/obj/armor";

void reset(int arg){
  if(arg) return;
  ::reset(arg);
  set_name("bracelet");
  set_short("Rump's Bracelet");
  set_long("Rump's personal bracelet.\n");
  set_ac(2);
  set_params("other|light", 2, 90, 0);
  set_type("bracelet");
  set_weight(1);
  set_value(100);
}
