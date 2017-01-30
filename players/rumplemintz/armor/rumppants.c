inherit "/obj/armor";

void reset(int arg){
  if(arg) return;
  ::reset(arg);
  set_name("pants");
  set_short("Rump's Pants");
  set_long("Rump's personal pants.\n");
  set_ac(2);
  set_params("other|ice", 2, 90, 0);
  set_type("pants");
  set_weight(1);
  set_value(100);
}
