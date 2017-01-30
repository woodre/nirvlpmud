inherit "obj/armor";
reset(arg){
  ::reset(arg);
  set_name("shirt");
  set_short("Shirt");
  set_type("armor");
  set_long("This is a cool looking shirt.  Swirls of glitter\n"+
           "and color blind you as light flares back at you\n");
  set_ac(4);
  set_weight(2);
  set_value(1000);
}
