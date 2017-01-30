inherit "/obj/armor";

void reset(int arg){
  if(arg) return;
  ::reset(arg);
  set_name("necklace");
  set_short("Rump's Necklace");
  set_long("Rump's Necklace\n");
  set_ac(2);
  set_res(90);
  set_type("necklace");
  set_weight(1);
  set_value(100);
}
