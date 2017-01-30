 
inherit "obj/weapon";
reset(arg) {
  if(arg) return;
  set_name("pin");
  set_alias("rolling pin");
  set_short("Rolling pin");
  set_long("A dangerous rolling pin.\n");
  set_value(50);
  set_weight(2);
  set_class(5);
}
