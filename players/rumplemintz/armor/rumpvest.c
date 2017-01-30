inherit "/obj/armor";

void reset(int arg){
  if(arg) return;
  ::reset(arg);
  set_name("vest");
  set_short("Rump's Vest");
  set_long("Rump's undervest.\n");
  set_ac(2);
  set_params("other|mental", 2, 90, 0);
  set_type("chest");
  set_weight(1);
  set_value(100);
}
