inherit "obj/armor";
reset(arg){
  ::reset(arg);
  set_name("solar plate");
  set_short("Solar Plate");
  set_alias("armor");
  set_long("A armor plate that seems to made from strings of\n"+
    "sun rays. Heat exudes from the armor.\n");
  set_ac(4);
  set_weight(2);
  set_value(10000);
  set_light(4);
}
