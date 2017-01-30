inherit "/obj/armor";

void reset(int arg){
  if(arg) return;
  ::reset(arg);
  set_name("boots");
  set_short("Rump's Boots");
  set_long("Rump's personal shit kickers.\n");
  set_ac(2);
  set_params("other|electricity", 2, 90, 0);
  set_type("boots");
  set_value(100);
  set_weight(1);
}
