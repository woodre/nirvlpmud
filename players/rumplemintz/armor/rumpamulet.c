inherit "/obj/armor";

void reset(int arg){
  if(arg) return;
  ::reset(arg);
  set_name("amulet");
  set_short("Rump's Amulet");
  set_long("Rump's gold chains.\n");
  set_ac(2);
  set_params("magical", 2, 90, 0);
  set_type("amulet");
  set_weight(1);
  set_value(100);
}
