inherit "obj/armor";
reset(arg){
  ::reset(arg);
  set_name("do");
  set_short("Do-Maru");
  set_alias("do-maru");
  set_type("armor");
  set_long("The Do is an armor that covers the upper part of the body with laced metal links.\n"+
    "The lower part of the body (upper legs) is protected\n"+
    "by a set of small tassets.  It seems nice and tough.\n");
  set_ac(3);
  set_weight(4);
  set_value(100);
}
