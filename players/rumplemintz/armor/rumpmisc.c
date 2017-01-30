inherit "/obj/armor";

void reset(int arg){
  if(arg) return;
  ::reset(arg);
  set_name("mask");
  set_short("Rump's Mask");
  set_long("Rump's personal mask.\n");
  set_ac(2);
  set_params("other|earth", 2, 90, 0);
  set_type("misc");
  set_weight(1);
  set_value(100);
}
