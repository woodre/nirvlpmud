inherit "/obj/armor";

reset(arg) {
  if(arg) return;
  set_name("headdress");
  set_short("A large feathered headdress");
  set_long("A headdress with many different colored feathers.\n");
  set_type("helmet");
  set_ac(1);
  set_weight(1);
  set_value(100);
}
