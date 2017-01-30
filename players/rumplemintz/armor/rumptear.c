inherit "/obj/armor";

void reset(int arg){
  if(arg) return;
  ::reset(arg);
  set_name("tear");
  set_short("Rump's Tear Earring");
  set_long("Rump's Tear Earring.\n");
  set_ac(2);
  set_params("other|poison", 2, 90, 0);
  set_type("earring");
  set_weight(1);
  set_value(100);
}
