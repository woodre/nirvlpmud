inherit "/obj/armor";

void reset(int arg){
  if(arg) return;
  ::reset(arg);
  set_name("helmet");
  set_short("Rump's Helmet");
  set_long("Rump's thinking cap.\n");
  set_type("helmet");
  set_ac(2);
  set_params("other|wind", 2, 90, 0);
  set_value(100);
  set_weight(1);
}
